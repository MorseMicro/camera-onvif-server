CC = $(CXX)
SOAPOBJS = soaplib/stdsoap2.o \
           soaplib/soapClient.o \
           soaplib/soapServer.o \
           soaplib/wsaapi.o \
           soaplib/wsddapi.o \
           soaplib/threads.o \
           soaplib/xml-rpc.o \
           soaplib/json.o \
           soaplib/jsonC.o \
           soaplib/httpget.o \
           soaplib/soapC_001.o \
           soaplib/soapC_002.o \
           soaplib/soapC_003.o \
           soaplib/soapC_004.o \
           soaplib/soapC_005.o \
           soaplib/soapC_006.o
# soaplib/wsseapi.o soaplib/mecevp.o soaplib/smdevp.o soaplib/struct_timeval.o \

DEBUG_FLAGS = -DDEBUG -g -O1 -fno-omit-frame-pointer # -fsanitize=address,undefined,leak
# Defining SOAP_NOTHROW here actually enables throws (badallocs) so we don't have to check
# for null everywhere (by default, it's set to (std::nothrow)).
CPPFLAGS += -DSOAP_NOTHROW='' -DJSON_NAMESPACE -DWITH_NOIDREF -DWITH_SOCKET_CLOSE_ON_EXIT -I.
CXXFLAGS_LENIENT := $(CXXFLAGS) --std=c++17 -Os -fdata-sections -ffunction-sections
CFLAGS_LENIENT := $(CFLAGS) --std=c++17 -Os -fdata-sections -ffunction-sections
CFLAGS = $(CFLAGS_LENIENT) -MMD -Wall -Werror
CXXFLAGS = $(CXXFLAGS_LENIENT) -MMD -Wall -Werror
LDFLAGS += -s -Wl,--gc-sections
LDLIBS += -lpthread

MAINOBJ = main.o
MYOBJS = discovery.o \
	server.o stubs.o devicemgmt.o media.o imaging.o \
	httpgethandler.o \
	camera.o rtspserver_process.o rtspserver_mediamtxrpi.o \
	utils.o
OBJECTS = $(MYOBJS) $(SOAPOBJS)
TESTOBJS = tests/main.o tests/devicemgmt.o tests/media.o tests/imaging.o
ALL_OBJECTS = $(MAINOBJ) $(OBJECTS) $(TESTOBJS)
ALL_MY_OBJECTS = $(TESTOBJS) $(MAINOBJ) $(MYOBJS)

camera-onvif-server: $(MAINOBJ) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -Wall -Werror $^ -o $@ $(LDLIBS)

test-runner: CXXFLAGS_LENIENT += $(DEBUG_FLAGS)
test-runner: CFLAGS_LENIENT += $(DEBUG_FLAGS)
test-runner: LDFLAGS =
test-runner: $(TESTOBJS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -Wall -Werror $^ -o $@ $(LDLIBS)

.PHONY: debug
debug: CXXFLAGS_LENIENT += $(DEBUG_FLAGS)
debug: CFLAGS_LENIENT += $(DEBUG_FLAGS)
debug: LDFLAGS =
debug: camera-onvif-server

.PHONY: check
check: licence-check test  # lint - disabled due to issues (see below)

.PHONY: lint
lint:
	cppcheck .  # takes way too long
	clang-tidy *.cpp  # clang can't deal with soaplib/json.h

.PHONY: licence-check
licence-check:
	addlicense -c 'Morse Micro' -l GPL-2.0-or-later -s -check *.h *.cpp tests/*.cpp

.PHONY: licence-fix
licence-fix:
	addlicense -v -c 'Morse Micro' -l GPL-2.0-or-later -s *.h *.cpp tests/*.cpp

.PHONY: test
test: test-runner
	./test-runner

.PHONY: clean
clean:
	# Don't nuke the generated files; we most likely just care about the objects
	rm -f camera-onvif-server $(ALL_OBJECTS)

-include $(ALL_MY_OBJECTS:%.o=%.d)

# Don't annoy people about generated files.

soaplib/%.o: soaplib/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_LENIENT) -c $^ -o $@

soaplib/%.o: soaplib/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS_LENIENT) -c $^ -o $@

