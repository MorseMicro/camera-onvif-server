# Automate https://www.genivia.com/examples/onvif/index.html#ONVIF_Client_Application_in_C++_to_Retrieve_Image_Snapshots
# Idea is that this slurps everything down, but then the stuff we actually use is checked in.

# You probably need to set this to wherever you extracted gsoap-2.8
GSOAP_DIR = $(HOME)/builds/gsoap-2.8/gsoap

ALL_WSDLS =   http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl \
  http://www.onvif.org/onvif/ver10/events/wsdl/event.wsdl \
  http://www.onvif.org/onvif/ver10/deviceio.wsdl \
  http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl \
  http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl \
  http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl \
  http://www.onvif.org/onvif/ver10/network/wsdl/remotediscovery.wsdl \
  http://www.onvif.org/ver10/advancedsecurity/wsdl/advancedsecurity.wsdl

# These are the WSDLS I need at the moment.
WSDLS =   http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl \
  http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl \
  http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl \
  http://www.onvif.org/onvif/ver10/network/wsdl/remotediscovery.wsdl

# Any addition stuff.
CUSTOM_XSDS = onvif-config.xsd

LIBRARY_SOURCEFILES = stdsoap2.cpp stdsoap2.h # dom.cpp
#PLUGIN_SOURCEFILES = smdevp.c mecevp.c wsaapi.c wsseapi.c wsddapi.c threads.c \
#                     smdevp.h mecevp.h wsaapi.h wsseapi.h wsddapi.h threads.h
PLUGIN_SOURCEFILES = wsaapi.c wsaapi.h wsddapi.c wsddapi.h threads.c threads.h
# CUSTOM_SOURCEFILES = struct_timeval.c struct_timeval.h
XML_RPC_JSON_SOURCEFILES = json.cpp json.h xml-rpc.cpp xml-rpc.h xml-rpc-iters.h

JSON_OUTPUT_SOURCEFILES = jsonH.h jsonStub.h jsonC.cpp envC.cpp

ONVIF_SOURCEFILES = soapServer.cpp soapClient.cpp \
                    soapH.h soapStub.h \
                    soapC_001.cpp \
                    soapC_002.cpp \
                    soapC_003.cpp \
                    soapC_004.cpp \
                    soapC_005.cpp \
                    soapC_006.cpp \
                    soapC_007.cpp \
					soaplib/DeviceBinding.nsmap \
					soaplib/ImagingBinding.nsmap \
					soaplib/MediaBinding.nsmap \
					soaplib/RemoteDiscoveryBinding.nsmap


GENERATED_SOURCEFILES = $(ONVIF_SOURCEFILES) $(PLUGIN_SOURCEFILES) $(CUSTOM_SOURCEFILES) $(LIBRARY_SOURCEFILES) $(JSON_OUTPUT_SOURCEFILES)

.DELETE_ON_ERROR:
.NO_PARALLEL:

# Note that the objects are built/requested by the Makefile up a level, not here.
# This is purely for setting up the source files appropriately.
generated: $(GENERATED_SOURCEFILES)
.PHONY: generated

$(JSON_OUTPUT_SOURCEFILES): $(XML_RPC_JSON_SOURCEFILES)
	soapcpp2 -qjson -CSL xml-rpc.h

onvif.h: $(CUSTOM_XSDS)
	wsdl2h -O3 -c++14 -t $(GSOAP_DIR)/typemap.dat -x -o onvif.h $(WSDLS) $(CUSTOM_XSDS)
	# Stupid hacks suggested by:
	# https://www.genivia.com/examples/onvif/index.html#ONVIF_Client_Application_in_C++_to_Retrieve_Image_Snapshots
	sed -i -e '/^#import "wsdd10.h"/c\#import "wsdd5.h"' -e '/^#import "wsa.h"/d' onvif.h
	# echo '#import "wsse.h"' >> onvif.h

# If only we had Make 4.3 (then we could use &:)
$(ONVIF_SOURCEFILES): .sentinel ;

.sentinel: onvif.h
	soapcpp2 -I$(GSOAP_DIR):$(GSOAP_DIR)/import -Ed -Ec -c++14 -f400 -x -s -L onvif.h
	@touch $@

.PHONY: clean
clean:
	rm -f $(GENERATED_SOURCEFILES) onvif.h typemap.dat

$(PLUGIN_SOURCEFILES):
	cp $(GSOAP_DIR)/plugin/$@ .

$(LIBRARY_SOURCEFILES):
	cp $(GSOAP_DIR)/$@ .

$(CUSTOM_SOURCEFILES):
	cp $(GSOAP_DIR)/custom/$@ .

$(XML_RPC_JSON_SOURCEFILES):
	cp $(GSOAP_DIR)/samples/xml-rpc-json/$@ .
