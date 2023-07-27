// Hack to let us use to_string (some weird gcc 5.x issue; thanks Ingenic).
#define _GLIBCXX_USE_C99 1

#include "soaplib/soapH.h"

#include "utils.h"
#include "camera.h"

#include <string>
#include <algorithm>
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
	soap = soap_new1(SOAP_XML_DEFAULTNS | SOAP_XML_STRICT | SOAP_XML_INDENT);
	soap_set_namespaces(soap, datafile_namespaces);
}

Camera::Camera(std::string onvif_url, std::string ip, std::string properties_filename, std::string config_filename)
		: onvif_url(onvif_url), ip(ip), config_filename(config_filename), rtsp_server_pid(0)
{
	soap = soap_new1(SOAP_XML_DEFAULTNS | SOAP_XML_STRICT);
	soap_set_namespaces(soap, datafile_namespaces);

	config = soap_new__tt__CameraConfiguration(soap);
	std::ifstream config_file(config_filename);
	soap->is = &config_file;
	SoapError::ifNotOk(soap, "Reading " + config_filename, soap_read__tt__CameraConfiguration(soap, config));
	config_file.close();

	properties = soap_new__tt__CameraProperties(soap);
	std::ifstream properties_file(properties_filename);
	soap->is = &properties_file;
	SoapError::ifNotOk(soap, "Reading " + config_filename, soap_read__tt__CameraProperties(soap, properties));
	properties_file.close();
}

Camera::~Camera() {
	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

void Camera::saveConfiguration() {
	std::ofstream camera_config_file(config_filename);
	saveConfiguration(camera_config_file);
	camera_config_file.close();
}

void Camera::saveConfiguration(std::ostream &camera_config_output) {
	soap->os = &camera_config_output;
	SoapError::ifNotOk(soap, "Saving camera config", soap_write__tt__CameraConfiguration(soap, config));
}

void Camera::stopRtspServerIfRunning() {
	if (rtsp_server_pid == 0) {
		return;
	}

	stop_child_process(rtsp_server_pid);
}

std::string Camera::getStreamUri() {
	return "rtsp://" + ip + ":" + properties->RTSPStream->Port + "/" + properties->RTSPStream->Path;
}

std::vector<std::string> Camera::buildRtspServerArguments() {
	auto *vce = getCurrentVideoEncoderConfiguration();

	switch (properties->RTSPStream->Type) {
		case tt__RTSPServerType::ingenic:
			return {
				properties->RTSPStream->ExecutablePath,
				"-h", std::to_string(vce->Resolution->Height),
				"-r", std::to_string(vce->RateControl->FrameRateLimit),
				"-b", std::to_string(vce->RateControl->BitrateLimit),
				"-g", std::to_string(vce->H264->GovLength),
				getStreamUri(),
			};
		default:
			throw new std::runtime_error(std::string("No support for rtsp server type ") + soap_tt__RTSPServerType2s(soap, properties->RTSPStream->Type));
	}
}

void Camera::startRtspServer() {
	stopRtspServerIfRunning();
	rtsp_server_pid = start_child_process(properties->RTSPStream->ExecutablePath, buildRtspServerArguments());
}