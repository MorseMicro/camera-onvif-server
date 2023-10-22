// Hack to let us use to_string (some weird gcc 5.x issue; thanks Ingenic).
#define _GLIBCXX_USE_C99 1

#include "soaplib/soapH.h"

#include "camera.h"
#include "utils.h"

#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>


static const struct Namespace datafile_namespaces[] = { 
	{ "tt", "http://www.onvif.org/ver10/schema", nullptr, nullptr },
	{ "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", nullptr },
	{ nullptr, nullptr, nullptr, nullptr}
};


Camera::Camera(std::string onvif_url, std::string ip, std::string properties_filename, std::string config_filename, RtspServer *rtsp_server)
		: onvif_url(onvif_url), ip(ip), config_filename(config_filename), rtsp_server(rtsp_server)
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

	if (!rtsp_server) {
		switch (properties->RTSPStream->Type) {
			case tt__RTSPServerType::mediaMtxRpi:
				this->rtsp_server = new RtspServerMediaMtxRpi(std::string("http://localhost:") + properties->RTSPStream->API->Port, properties->RTSPStream->Path);
				break;
			case tt__RTSPServerType::nvtrtspd:
				this->rtsp_server = new RtspServerNvtrtspd(properties->RTSPStream->Executable->Path, properties->RTSPStream->Port, properties->RTSPStream->Path);
				break;
			case tt__RTSPServerType::t31rtspd:
				this->rtsp_server = new RtspServerT31rtspd(properties->RTSPStream->Executable->Path, properties->RTSPStream->Port, properties->RTSPStream->Path);
				break;
			case tt__RTSPServerType::dummy:
			default:
				this->rtsp_server = new RtspServerDummy();
				break;
		}
	}

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
		// Do nothing. Used for testing/development.
		return;
	}

	std::ofstream camera_config_file(config_filename);
	saveConfiguration(camera_config_file);
	camera_config_file.close();
}
	

void Camera::applyVideoEncoderConfiguration(tt__VideoEncoderConfiguration *vec) {
	rtsp_server->setVideoEncoderConfiguration(vec);
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


std::string Camera::getStreamUri() {
	return "rtsp://" + ip + ":" + properties->RTSPStream->Port + "/" + properties->RTSPStream->Path;
}


void Camera::initialiseRtspServer() {
	rtsp_server->initialise(getCurrentVideoEncoderConfiguration());
}


bool Camera::setVideoEncoderConfiguration(tt__VideoEncoderConfiguration *new_vec) {
	auto &vecs = config->MediaService->VideoEncoderConfiguration;
	auto vec_it = std::find_if(vecs.begin(), vecs.end(),
		[new_vec] (tt__VideoEncoderConfiguration *vec) { return vec->token == new_vec->token; });
	if (vec_it == vecs.end()) {
		return false;
	}
	(*vec_it)->soap_del();
	*vec_it = new_vec->soap_dup();

	saveConfiguration();

	if (new_vec->token == *(getCurrentMinimumProfile()->VideoEncoderConfigurationToken)) {
		applyVideoEncoderConfiguration(new_vec);
	}
	return true;
}