#pragma once

#include "soaplib/soapH.h"


/* Every time we start an ONVIF server, it starts knowing about exactly one RtspServer.
 * Which RtspServer class is used is selected via the properties.xml file;
 * if it's a simple 'start a new process' model with no RPC it extends from
 * RtspServerProcess.
 */
class RtspServer {
	public:
		/* Make sure the stream exists at the appropriate path. */
		virtual void initialise(const tt__VideoEncoderConfiguration *) = 0;

		virtual void setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *) = 0;
};


class RtspServerDummy : public RtspServer {
	public:
		RtspServerDummy() {}

		virtual void initialise(const tt__VideoEncoderConfiguration *) {
			std::cout << "Initialising the rtsp server!" << std::endl;
		};

		virtual void setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *) {
			std::cout << "Setting the video encoder config!" << std::endl;
		};
};
