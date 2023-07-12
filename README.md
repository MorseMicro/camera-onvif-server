# Camera ONVIF server

ONVIF server that spawns an external program to show RTSP streams
designed for normal cameras. Planned to support:

 - auto-discovery
 - device management
 - media
 - imaging

Why? We want to be able to easily have APIs/auto-discovery on arbitrary
devices, including ones that 'need' custom RTSP servers
(i.e. ones that don't use v4l2 for input).

## Err, what is ONVIF/SOAP/gsoap/etc.?

ONVIF is an industry agreed upon bunch of APIs for talking to
video-ish devices. SOAP means that it uses XML documents
for RPC over HTTP (cf a more modern JSON-blob or gRPC or
...).

gsoap is a C/C++ autogenerator thing that if you give it
a bunch of WSDL (Web Services Description Language) files
it turns them into a horrifically large about of code.

## Setup

gsoap auto-generated files are in soaplib.
Get gsoap, and set GSOAP_DIR appropriately, then type:

    cd soaplib && make

to get them up to date. In future, these will be included in the repo.
Note that this will _download_ the WSDL files.


## Build and run

    make
    ./camera-onvif-server --properties settings/camera-properties.xml --config settings/camera-configuration.xml


We make a distinction between 'properties' (fixed attributes of the camera)
and 'configuration' (things that can change via the ONVIF APIs at runtime).
Both of these are loaded from XML files (see settings/*.xml), but the
configuration XML file is updated based on what the user does
(e.g. sets new encoder configuration or creates a profile or ...).


## Testing

    make test  # basic unit-tests only
    make lint
    make check  # does both