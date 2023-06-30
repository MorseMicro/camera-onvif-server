#include <getopt.h>

#include <iostream>
#include <exception>

#include "camera.h"
#include "discovery.h"
#include "server.h"
#include "utils.h"

#include "soaplib/DeviceBinding.nsmap"


const char *OPTSTRING = "hr:c:";
const option LONGOPTS[] = {
	{"port", required_argument, nullptr, 'p'},
	{"properties", required_argument, nullptr, 'p'},
	{"config", required_argument, nullptr, 'c'},
	{"help", no_argument, nullptr, 'h'},
	{nullptr, no_argument, nullptr, 0},
};


void usage(char *cmd) {
	std::cerr << "Usage:" << std::endl;
	std::cerr << "  " << cmd << " 10.0.0.1 --config config.xml --properties properties.xml" << std::endl;
	exit(1);
}


int main(int argc, char * const argv[])
{
	const char *properties = "settings/camera_properties.xml";
	const char *config = "settings/camera_configuration.xml";
	const char *port = "8080";
	int opt;
	while (-1 != (opt = getopt_long(argc, argv, OPTSTRING, LONGOPTS, nullptr))) {
		switch (opt) {
			case 'p':
				port = optarg;
				break;
			case 'c':
				config = optarg;
				break;
			case 'r':
				properties = optarg;
				break;
			case 'h':
				usage(argv[0]);
				exit(0);
				break;
			case '?':
			default:
				usage(argv[0]);
				exit(1);
				break;
		}
	}

	if (argc == optind) {
		std::cerr << "Must provide exactly one positional argument: host ip to serve from" << std::endl;
		exit(1);
	}

	const char *ip = argv[optind];
	std::string onvif_url = std::string("http://") + ip + ":" + port;
	std::string rtsp_url = std::string("rtsp://") + ip + ":8554"; // TODO

	try {
		std::cout << "Loading camera configuration..." << std::endl;
		Camera camera(properties, config);
		std::cout << "Starting RTSP server: " << rtsp_url << std::endl;
		camera.startRtspServer();
		std::cout << "Starting WS-Discovery server: " << ip << ":3702" << std::endl;
		spawn_wsdd_server(ip, onvif_url.c_str());
		std::cout << "Starting ONVIF server: " << onvif_url << std::endl;
		start_server(&camera);  // should block here
	} catch (std::exception *e) {
		std::cerr << e->what() << std::endl;
	}

	// We never exit happy in the normal course of events, as the server should block.
	return 1;
}
