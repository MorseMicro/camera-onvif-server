# Camera ONVIF server

ONVIF server that spawns an external program to show RTSP streams
designed for normal cameras. Planned to support:

 - auto-discovery
 - device management
 - media
 - imaging

Why? We want to be able to easily have APIs/auto-discovery on arbitrary
devices, including ones that 'need' custom RTSP servers
(i.e. ones that don't use v4l2 or libcamera).


## Err, what is ONVIF/SOAP/gsoap/etc.?

ONVIF is an industry agreed upon bunch of APIs for talking to
video-ish devices. SOAP means that it uses XML documents
for RPC over HTTP (cf a more modern JSON-blob or gRPC or
...).

gsoap is a C/C++ autogenerator thing that if you give it
a bunch of WSDL (Web Services Description Language) files
it turns them into a horrifically large about of code.


## Build and run

    make
    ./camera-onvif-server :my-ip: --properties settings/dummy/properties.xml --config settings/dummy/config.xml


If you omit --properties/--config, they default to `./properties.xml`
and `./config.xml`.

We make a distinction between _properties_ (fixed attributes of the camera)
and _configuration_ (things that can change via the ONVIF APIs at runtime).
Both of these are loaded from XML files (see settings/*.xml), but the
configuration XML file is updated based on what the user does
(e.g. sets new encoder configuration or creates a profile or ...).


## Testing

    make test  # basic unit-tests only
    make lint
    make check  # does both


## GSOAP

gsoap static and auto-generated files are in soaplib. All the necessary files
are included in the repository, but the process of getting them
is in the `Makefile`.

If you'd like to update them (currently they're taken from 2.8.127),
get gsoap, set GSOAP_DIR to where you extracted it, then type:

    cd soaplib && make clean && make

Note that this will _download_ the WSDL files.


## Internal architecture

Start with main() in main.cpp. It will kick off three things:

- the `Camera`, whose main job is to make sure the `RTSPServer` is running
  (which may be a separate process, or it may just attempt to communicate
  with an existing RTSP server via some API). The `Camera` class also takes care
  of interpreting the fixed properties.xml file (to decide what RTSPServer
  to use), and also loads and when necessary mutates the config.xml file.
- the WS-Discovery server (which listens to UDP broadcasts and responds to them);
  see discovery.cpp/h.
- the actual ONVIF API server, which listens to SOAP ONVIF commands and communicates
  them to the `Camera` class and is started from server.cpp. The heavy lifting here
  is done almost entirely by gsoap autogeneration; our work is a separate file corresponding to
  each actual wsdl file (i.e. imaging.cpp, media.cpp, devicemgmt.cpp).
  Since the defined API is quite large but we don't actually support all of it
  at the moment, stubs.cpp covers the not implemented functions
  (which are required to compile - remember, this is all generated...).
  If you want to add a function, move it from stubs.cpp to the appropriate
  other file.

We also use the ONVIF API server to deliver an HTML index page by adding an http_get_handler.
See httpgethandler.c/h.


## Adding support for a new RTSP server

Any time we initialise a new `Camera`, it's provided with an `RTSPServer` object,
usually selected by the Type in `properties.xml`.

If you want to add another RTSP server type:

- add a new RtspServerType to soaplib/onvif-config.xsd and run `make` in `soaplib`
- extend RTSPServer (see rtspserver.h) and implement the necessary abstract methods
- add your new type to the `switch` statement in camera.cpp
