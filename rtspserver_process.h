#pragma once

#include "soaplib/soapH.h"

#include "rtspserver.h"

#include <vector>
#include <string>


class RtspServerProcess : public RtspServer {
	private:
		pid_t rtsp_server_pid;

	protected:
		std::string executable_path;
		std::string port;
		std::string stream_path;

	public:
		explicit RtspServerProcess(const std::string executable_path, const std::string port, const std::string stream_path)
			: rtsp_server_pid(0), executable_path(executable_path), port(port), stream_path(stream_path) {}

		/* Make sure the stream exists at the appropriate path. */
		virtual void initialise(const tt__VideoEncoderConfiguration *);

		virtual void setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *);

		virtual std::vector<std::string> buildArguments(const tt__VideoEncoderConfiguration *) = 0;
};


class RtspServerT31rtspd : public RtspServerProcess {
	using RtspServerProcess::RtspServerProcess;

	public:
		virtual std::vector<std::string> buildArguments(const tt__VideoEncoderConfiguration *);
};


class RtspServerNvtrtspd : public RtspServerProcess {
	using RtspServerProcess::RtspServerProcess;

	public:
		virtual std::vector<std::string> buildArguments(const tt__VideoEncoderConfiguration *);
};