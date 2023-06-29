#include <getopt.h>

#include <iostream>
#include <exception>

#include "utils.h"
#include "camera.h"
#include "server.h"


const char *OPTSTRING = "p:c:";
const option LONGOPTS[] = {
	{"properties", required_argument, nullptr, 'p'},
	{"config", required_argument, nullptr, 'c'},
	{nullptr, no_argument, nullptr, 0},
};

int main(int argc, char * const argv[])
{
	const char *properties = "settings/camera_properties.xml";
	const char *config = "settings/camera_configuration.xml";
	int opt;
	while (-1 != (opt = getopt_long(argc, argv, OPTSTRING, LONGOPTS, nullptr))) {
		switch (opt) {
			case 'c':
				config = optarg;
				break;
			case 'p':
				properties = optarg;
				break;
			case '?':
			default:
				std::cerr << argv[0] << " --config config.xml --properties properties.xml" << std::endl;
				exit(1);
				break;
		}
	}

	try {
		std::cout << "Load camera configuration..." << std::endl;
		Camera camera(properties, config);
		std::cout << "Starting RTSP server..." << std::endl;
		camera.startRtspServer();
		start_server(&camera);  // should block here
	} catch (std::exception *e) {
		std::cerr << e->what() << std::endl;
	}

	// We never exit happy in the normal course of events, as the server should block.
	return 1;
}
