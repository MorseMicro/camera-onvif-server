CC = g++
SOAPOBJS = soaplib/stdsoap2.o \
           soaplib/wsaapi.o \
           soaplib/soapServer.o \
           soaplib/struct_timeval.o \
           soaplib/soapC_001.o \
           soaplib/soapC_002.o \
           soaplib/soapC_003.o \
           soaplib/soapC_004.o \
           soaplib/soapC_005.o \
           soaplib/soapC_006.o \
           soaplib/soapC_007.o
# soaplib/wsseapi.o soaplib/mecevp.o soaplib/smdevp.o soaplib/struct_timeval.o \
# soaplib/wsddapi.o \

CPPFLAGS += -DWITH_NONAMESPACES -DWITH_NOIDREF
CFLAGS += -Os
CXXFLAGS += -Os
CXXFLAGS_LENIENT := $(CXXFLAGS)
CLAGS_LENIENT := $(CFLAGS)
CFLAGS += -Wall -Werror
CXXFLAGS += -Wall -Werror

MAINOBJ = main.o
OBJECTS = utils.o camera.o server.o stubs.o devicemgmt.o $(SOAPOBJS)
TESTOBJS = tests/tests.o
ALL_OBJECTS = $(MAINOBJ) $(OBJECTS) $(TESTOBJS)

camera-onvif-server: $(MAINOBJ) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -Wall -Werror $^ -o $@ $(LDLIBS)

test-runner: CXXFLAGS += -DDEBUG -g -O0
test-runner: CFLAGS += -DDEBUG -g -O0
test-runner: $(TESTOBJS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -Wall -Werror $^ -o $@ $(LDLIBS)

.PHONY: debug
debug: CXXFLAGS += -DDEBUG -g -O0
debug: CFLAGS += -DDEBUG -g -O0
debug: camera-onvif-server

.PHONY: check
check: test lint

.PHONY: lint
lint:
	cppcheck .

.PHONY: test
test: test-runner
	./test-runner

.PHONY: clean
clean:
	# Don't nuke the generated files; we most likely just care about the objects
	rm -f camera-onvif-server $(ALL_OBJECTS)

# Don't annoy people about generated files.

soaplib/%.o: soaplib/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_LENIENT) -c $^ -o $@

soaplib/%.o: soaplib/%.c
	$(CXX) $(CPPFLAGS) $(CFLAGS_LENIENT) -c $^ -o $@

