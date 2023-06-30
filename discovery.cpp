#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <unistd.h>
#include <string.h>

#include "soaplib/wsddapi.h"


const char *TYPES = "tdn:NetworkVideoTransmitter";
const char *SCOPES = "onvif://www.onvif.org/type/video_encoder";
const char *MULTICAST_IP = "239.255.255.250";
const int MULTICAST_PORT = 3702;

struct WsddConfig {
	const char *endpoint_uuid;
	const char *service_url;
};


static void start_wsdd_server(const char *listen_ip, const char *service_url) {
	struct soap *soap = soap_new1(SOAP_IO_UDP);
	WsddConfig wsdd_conf = {soap_wsa_rand_uuid(soap), service_url};

	soap->user = &wsdd_conf;
	soap->bind_flags |= SO_REUSEADDR;
	soap->connect_flags |= SO_BROADCAST;
	in_addr_t multicast_addr = inet_addr(MULTICAST_IP);
	soap->ipv4_multicast_if = reinterpret_cast<char *>(&multicast_addr);
	soap->ipv6_multicast_if = multicast_addr;
	soap->ipv4_multicast_ttl = 1;

	std::cout << "Broadcasting hello via WS-Discovery..." << std::endl;
	// Best effort, ignore failure here.
	soap_wsdd_Hello(soap, SOAP_WSDD_ADHOC, "soap.udp://239.255.255.250:3702",
					soap_wsa_rand_uuid(soap), NULL, wsdd_conf.endpoint_uuid,
					TYPES, SCOPES, NULL, service_url, 1);

	if (!soap_valid_socket(soap_bind(soap, NULL, MULTICAST_PORT, 1000))) {
		std::cerr << "Error binding to port 3702 for discovery." << std::endl;
		soap_print_fault(soap, stderr);
		soap_destroy(soap);
		soap_end(soap);
		soap_free(soap);
		return;
	}

	// Heavily inspired my mpromonet/ws-discovery/gsoap/wsd-server.cpp, since
	// the official docs are terrible for server side ops.
	ip_mreq mcast; 
	mcast.imr_multiaddr.s_addr = multicast_addr;
	mcast.imr_interface.s_addr = inet_addr(listen_ip);
	if (setsockopt(soap->master, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mcast, sizeof(mcast)) != 0) {
		std::cerr << "Unable to become member of 239.255.255.250: " << strerror(errno) << std::endl;
	}

	std::cout << "Starting WS-Discovery listener..." << std::endl;
	while (true) {
		if (soap_wsdd_listen(soap, 0) != SOAP_OK) {
			// It's not clear to me how to distinguish here between terminal and non-terminal
			// issues... cf start_server, where if soap_accept fails we abort.
			// Here, we simply busy-loop :(
			// The code is wsdd_listen looks particularly strange as it returns
			// both on starture AND on a request failure (but then returns
			// the status of whether we managed to close the socket at the end
			// of transmitting the failure back to the client (?)).
			std::cerr << "Error when listening for discovery messages: " << std::endl;
			soap_print_fault(soap, stderr);
			soap_destroy(soap);
			soap_end(soap);
		}
	}
}

pid_t spawn_wsdd_server(const char *listen_ip, const char *service_url) {
	pid_t parent_pid = getpid();
	pid_t pid = fork();

	if (pid == -1) {
		throw new std::runtime_error("Unable to fork to start WS-Discovery server");
	} else if (pid == 0) {
		if (-1 == prctl(PR_SET_PDEATHSIG, SIGTERM)) {
			std::cerr << "Failed to prctl(PR_SET_PDEATHSIG) for rtsp server: " << strerror(errno) << std::endl;
			exit(1);
		}
		if (getppid() != parent_pid) { // In case parent already exited...
			exit(1);
		}

		start_wsdd_server(listen_ip, service_url);
	}

	return pid;
}

soap_wsdd_mode wsdd_event_Probe(struct soap *soap, const char *MessageID, const char *ReplyTo, const char *Types, const char *Scopes, const char *MatchBy, struct wsdd__ProbeMatchesType *ProbeMatches)
{
	std::cout << "Responding to probe: " << MessageID << std::endl;
	auto *wsdd_conf = static_cast<WsddConfig *>(soap->user);
	soap_wsdd_init_ProbeMatches(soap, ProbeMatches);
	soap_wsdd_add_ProbeMatch(
		soap, ProbeMatches, wsdd_conf->endpoint_uuid,
		TYPES, SCOPES, NULL, wsdd_conf->service_url, 1);
	soap_wsdd_ProbeMatches(soap, NULL, soap_wsa_rand_uuid(soap) , MessageID, ReplyTo, ProbeMatches);
	return SOAP_WSDD_ADHOC;
}

int SOAP_ENV__Fault(struct soap *soap, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail)
{
	/* populate the fault struct from the operation arguments to print it */
	soap_fault(soap);
	/* SOAP 1.1 */
	soap->fault->faultcode = faultcode;
	soap->fault->faultstring = faultstring;
	soap->fault->faultactor = faultactor;
	soap->fault->detail = detail;
	/* SOAP 1.2 */
	soap->fault->SOAP_ENV__Code = SOAP_ENV__Code;
	soap->fault->SOAP_ENV__Reason = SOAP_ENV__Reason;
	soap->fault->SOAP_ENV__Node = SOAP_ENV__Node;
	soap->fault->SOAP_ENV__Role = SOAP_ENV__Role;
	soap->fault->SOAP_ENV__Detail = SOAP_ENV__Detail;
	/* set error */
	soap->error = SOAP_FAULT;
	/* handle or display the fault here with soap_stream_fault(soap, std::cerr); */
	/* return HTTP 202 Accepted */
	return soap_send_empty_response(soap, SOAP_OK);
}
