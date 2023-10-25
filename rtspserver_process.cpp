// Hack to let us use to_string (some weird gcc 5.x issue; thanks Ingenic).
#define _GLIBCXX_USE_C99 1

#include "soaplib/soapH.h"

#include "utils.h"
#include "rtspserver_process.h"

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>


void RtspServerProcess::start() {
	if (rtsp_server_pid != 0) {
		std::cout << "Stopping RTSP server (" << rtsp_server_pid << ")" << std::endl;
		stop_child_process(rtsp_server_pid);
		rtsp_server_pid = 0;
	}

	auto args = buildArguments();
	std::ostringstream string_args;
	std::copy(args.begin(), args.end(), std::ostream_iterator<std::string>(string_args, " "));
	std::cout << "Starting RTSP server: " << string_args.str() << std::endl;
	rtsp_server_pid = start_child_process(executable_path, args);
}


void RtspServerProcess::setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *vec) {
	this->video_encoder_configuration->soap_del();
	this->video_encoder_configuration = vec->soap_dup();
	start();
}


void RtspServerProcess::setImagingSettings(const tt__ImagingSettings20 *imaging_settings) {
	this->imaging_settings->soap_del();
	this->imaging_settings = imaging_settings->soap_dup();
	start();
}


void RtspServerProcess::setVideoSourceConfiguration(const tt__VideoSourceConfiguration *vsc) {
	this->video_source_configuration->soap_del();
	this->video_source_configuration = vsc->soap_dup();
	start();
}


void RtspServerProcess::initialise(const tt__VideoEncoderConfiguration *vec, const tt__ImagingSettings20 *imaging_settings, const tt__VideoSourceConfiguration *vsc) {
	this->video_encoder_configuration = vec->soap_dup();
	this->imaging_settings = imaging_settings->soap_dup();
	start();
}


static const std::map<tt__H264Profile, std::string> t31rtspdProfileMap = {
	{tt__H264Profile::Baseline, "baseline"},
	{tt__H264Profile::Main, "main"},
	{tt__H264Profile::Extended, "main"},
	{tt__H264Profile::High, "high"},
};


std::vector<std::string> RtspServerT31rtspd::buildArguments() {
	auto *vec = this->video_encoder_configuration;

	return {
		executable_path,
		"-p", port,
		"-n", stream_path,
		"--profile", vec->H264 != nullptr ? t31rtspdProfileMap.at(vec->H264->H264Profile) : "main",
		// Usually quality would be something saner (e.g. we could be setting fixqp),
		// but as with rpos (raspberry pi onvif server) the most useful thing to do
		// here is to choose between CBR and VBR (since there's no proper ONVIF
		// way to do this).
		"-m", vec->Quality < 0.6 ? "cbr" : "vbr",
		"-h", std::to_string(vec->Resolution->Height),
		"-w", std::to_string(vec->Resolution->Width),
		"-f", vec->RateControl != nullptr ? std::to_string(vec->RateControl->FrameRateLimit) : "30",
		"-b", vec->RateControl != nullptr ? std::to_string(vec->RateControl->BitrateLimit) : "1000",
		"-g", vec->H264 != nullptr ? std::to_string(vec->H264->GovLength) : "60",
	};
}


std::vector<std::string> RtspServerNvtrtspd::buildArguments() {
	auto *vec = this->video_encoder_configuration;

	// nvtrtspd doesn't support much at all that's useful to us...
	//
	// Usage: <3DNR> <shdr_mode> <enc_type> <enc_bitrate> <data_mode> <data2_mode>.
	// Help:
	//  <3DNR>        : 0(disable), 1(enable)
	//  <shdr_mode>   : 0(disable), 1(enable)
	//  <enc_type>    : 0(H265), 1(H264)
	//  <enc_bitrate> : Mbps
	//  <data_mode>   : 0(D2D), 1(Direct)
	//  <data2_mode>   : 0(D2D), 1(LowLatency)
	//  <Audio type>   : 0(PCM), 1(AAC), 2(ULAW), 2(ALAW) 

	int bitrate_kbps = vec->RateControl != nullptr ? vec->RateControl->BitrateLimit : 1000;
	int bitrate_mbps = round(fmax(1, static_cast<float>(bitrate_kbps) / 1000));

	return {
		executable_path,
		"1", // 3DNR
		"0", // shdr
		"1", // H264
		std::to_string(bitrate_mbps), // Mbps
		"0", // data_mode
		"0", // data_mode
		"1", // Audio type
	};
}