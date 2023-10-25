#pragma once

#include "soaplib/soapH.h"

#include "rtspserver.h"

#include <vector>
#include <string>


class RtspServerProcess : public RtspServer {
	private:
		pid_t rtsp_server_pid;

		void start();

	protected:
		std::string executable_path;
		std::string port;
		std::string stream_path;
		tt__VideoEncoderConfiguration *video_encoder_configuration;
		tt__ImagingSettings20 *imaging_settings;
		tt__VideoSourceConfiguration *video_source_configuration;

	public:
		explicit RtspServerProcess(const std::string executable_path, const std::string port, const std::string stream_path)
			: rtsp_server_pid(0), executable_path(executable_path), port(port), stream_path(stream_path) {}

		/* Make sure the stream exists at the appropriate path. */
		virtual void initialise(const tt__VideoEncoderConfiguration *, const tt__ImagingSettings20 *, const tt__VideoSourceConfiguration *);


		virtual void setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *);

		virtual void setImagingSettings(const tt__ImagingSettings20 *);

		virtual void setVideoSourceConfiguration(const tt__VideoSourceConfiguration *);

		virtual std::vector<std::string> buildArguments() = 0;
};


class RtspServerT31rtspd : public RtspServerProcess {
	using RtspServerProcess::RtspServerProcess;

	public:
		virtual std::vector<std::string> buildArguments();
};


class RtspServerNvtrtspd : public RtspServerProcess {
	using RtspServerProcess::RtspServerProcess;

	public:
		virtual std::vector<std::string> buildArguments();
};