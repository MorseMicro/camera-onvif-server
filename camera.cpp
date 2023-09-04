// Hack to let us use to_string (some weird gcc 5.x issue; thanks Ingenic).
#define _GLIBCXX_USE_C99 1

#include "soaplib/soapH.h"

#include "utils.h"
#include "camera.h"

#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>


class SoapError: public std::runtime_error {
	public:
		explicit SoapError(const std::string &what_arg) : std::runtime_error(what_arg) {}

		static soap_status ifNotOk(struct soap *soap, const std::string &msg, soap_status status) {
			if (status == SOAP_OK) {
				return SOAP_OK;
			}
			
			std::stringstream ss;
			ss << msg << "\n";
			soap_stream_fault(soap, ss);
			soap_stream_fault_location(soap, ss);
			throw new SoapError(ss.str());
			return status;  // Keep the compiler happy.
		}
};


static const struct Namespace datafile_namespaces[] = { 
	{ "tt", "http://www.onvif.org/ver10/schema", nullptr, nullptr },
	{ "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", nullptr },
	{ nullptr, nullptr, nullptr, nullptr}
};


Camera::Camera(std::string onvif_url, std::string ip, _tt__CameraProperties *properties, _tt__CameraConfiguration *config)
		: onvif_url(onvif_url), ip(ip), properties(properties), config(config), config_filename("camera_configuration.xml"),
		  rtsp_server_pid(0)
{
}

Camera::Camera(std::string onvif_url, std::string ip, std::string properties_filename, std::string config_filename)
		: onvif_url(onvif_url), ip(ip), config_filename(config_filename), rtsp_server_pid(0)
{
	struct soap *soap = soap_new1(SOAP_XML_DEFAULTNS | SOAP_XML_STRICT);
	soap_set_namespaces(soap, datafile_namespaces);

	config = soap_new__tt__CameraConfiguration(soap);
	std::ifstream config_file(config_filename);
	soap->is = &config_file;
	SoapError::ifNotOk(soap, "Reading " + config_filename, soap_read__tt__CameraConfiguration(soap, config));
	config_file.close();
	config = config->soap_dup();

	properties = soap_new__tt__CameraProperties(soap);
	std::ifstream properties_file(properties_filename);
	soap->is = &properties_file;
	SoapError::ifNotOk(soap, "Reading " + config_filename, soap_read__tt__CameraProperties(soap, properties));
	properties_file.close();
	properties = properties->soap_dup();

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}


Camera::~Camera() {
	properties->soap_del();
	config->soap_del();
}

void Camera::saveConfiguration() {
	if (properties->RTSPStream->Type == tt__RTSPServerType::dummy) {
		return;
	}

	std::ofstream camera_config_file(config_filename);
	saveConfiguration(camera_config_file);
	camera_config_file.close();
}

void Camera::saveConfiguration(std::ostream &camera_config_output) {
	struct soap *soap = soap_new1(SOAP_XML_DEFAULTNS | SOAP_XML_STRICT | SOAP_XML_INDENT);
	soap_set_namespaces(soap, datafile_namespaces);
	soap->os = &camera_config_output;
	SoapError::ifNotOk(soap, "Saving camera config", soap_write__tt__CameraConfiguration(soap, config));
	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

void Camera::stopRtspServerIfRunning() {
	if (rtsp_server_pid == 0) {
		return;
	}

	std::cout << "Stopping RTSP server (" << rtsp_server_pid << ")" << std::endl;

	stop_child_process(rtsp_server_pid);
}

std::string Camera::getStreamUri() {
	return "rtsp://" + ip + ":" + properties->RTSPStream->Port + "/" + properties->RTSPStream->Path;
}

static const std::map<tt__H264Profile, std::string> t31rtspdProfileMap = {
	{tt__H264Profile::Baseline, "baseline"},
	{tt__H264Profile::Main, "main"},
	{tt__H264Profile::Extended, "main"},
	{tt__H264Profile::High, "high"},
};

std::vector<std::string> Camera::buildRtspServerArguments() {
	auto *vce = getCurrentVideoEncoderConfiguration();

	switch (properties->RTSPStream->Type) {
		case tt__RTSPServerType::t31rtspd:
			// Currently, only H264, so we ignore encoding for now.
			return {
				properties->RTSPStream->ExecutablePath,
				"-p", properties->RTSPStream->Port,
				"-n", properties->RTSPStream->Path,
				"--profile", vce->H264 != nullptr ? t31rtspdProfileMap.at(vce->H264->H264Profile) : "main",
				// Usually quality would be something saner (e.g. we could be setting fixqp),
				// but as with rpos (raspberry pi onvif server) the most useful thing to do
				// here is to choose between CBR and VBR (since there's no proper ONVIF
				// way to do this).
				"-m", vce->Quality < 0.6 ? "cbr" : "vbr",
				"-h", std::to_string(vce->Resolution->Height),
				"-w", std::to_string(vce->Resolution->Width),
				"-f", vce->RateControl != nullptr ? std::to_string(vce->RateControl->FrameRateLimit) : "30",
				"-b", vce->RateControl != nullptr ? std::to_string(vce->RateControl->BitrateLimit) : "1000",
				"-g", vce->H264 != nullptr ? std::to_string(vce->H264->GovLength) : "60",
			};
		case tt__RTSPServerType::nvtrtspd: {
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

			int bitrate_kbps = vce->RateControl != nullptr ? vce->RateControl->BitrateLimit : 1000;
			int bitrate_mbps = round(fmax(1, static_cast<float>(bitrate_kbps) / 1000));

			return {
				properties->RTSPStream->ExecutablePath,
				"1", // 3DNR
				"0", // shdr
				"1", // H264
				std::to_string(bitrate_mbps), // Mbps
				"0", // data_mode
				"0", // data_mode
				"1", // Audio type
			};
		};
		case tt__RTSPServerType::dummy:
			return {properties->RTSPStream->ExecutablePath};
		default:
			// It would be nice to do this here, but loading an entire new soap context seems excessive.
			// std::string type = soap_tt__RTSPServerType2s(soap, properties->RTSPStream->Type);
			throw new std::runtime_error(std::string("No support for rtsp server type ") + std::to_string(static_cast<int>(properties->RTSPStream->Type)));

	}
}

void Camera::startRtspServer() {
	stopRtspServerIfRunning();
	auto args = buildRtspServerArguments();
	std::ostringstream string_args;
	std::copy(args.begin(), args.end(), std::ostream_iterator<std::string>(string_args, " "));
	std::cout << "Starting RTSP server: " << string_args.str() << std::endl;

	if (properties->RTSPStream->Type == tt__RTSPServerType::dummy) {
		return;
	}

	rtsp_server_pid = start_child_process(properties->RTSPStream->ExecutablePath, args);
}