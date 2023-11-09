// Copyright 2023 Morse Micro
// SPDX-License-Identifier: GPL-2.0-or-later

#include <getopt.h>
#include <arpa/inet.h>

#include <iostream>
#include <exception>

#include "camera.h"
#include "discovery.h"
#include "server.h"
#include "utils.h"

#include "soaplib/DeviceBinding.nsmap"


const char *OPTSTRING = "hp:r:c:";
const option LONGOPTS[] = {
	{"port", required_argument, nullptr, 'p'},
	{"properties", required_argument, nullptr, 'r'},
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
	const char *properties = "properties.xml";
	const char *config = "config.xml";
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
		usage(argv[0]);
		exit(1);
	}

	const char *ip = argv[optind];
	unsigned char tmpbuf[sizeof(struct in_addr)];
	if (inet_pton(AF_INET, ip, tmpbuf) <= 0) {
		std::cerr << "Must provide valid IPv4 address, not: " << ip << std::endl;
		usage(argv[0]);
		exit(1);
	}

	std::string onvif_url = std::string("http://") + ip + ":" + port;

	try {
		std::cout << "Loading camera configuration..." << std::endl;
		Camera camera(onvif_url, ip, properties, config);
		std::cout << "Initialising RTSP stream: " << camera.getStreamUri() << std::endl;
		camera.initialiseRtspServer();
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
