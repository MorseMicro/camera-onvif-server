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
	rtsp_server->initialise(getCurrentVideoEncoderConfiguration(), getCurrentImagingSettings(), getCurrentVideoSourceConfiguration());
}


bool Camera::setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *new_vec) {
	auto &vecs = config->MediaService->VideoEncoderConfiguration;
	auto vecs_it = std::find_if(vecs.begin(), vecs.end(),
		[new_vec] (tt__VideoEncoderConfiguration *vec) { return vec->token == new_vec->token; });
	if (vecs_it == vecs.end()) {
		return false;
	}
	(*vecs_it)->soap_del();
	*vecs_it = new_vec->soap_dup();

	saveConfiguration();

	if (new_vec->token == *(getCurrentMinimumProfile()->VideoEncoderConfigurationToken)) {
		rtsp_server->setVideoEncoderConfiguration(new_vec);
	}
	return true;
}


bool Camera::setImagingSettings(const std::string &vs_token, const tt__ImagingSettings20 *new_imaging_settings) {
	auto &sources = config->ImagingService->ImagingVideoSource;
	auto sources_it = std::find_if(sources.begin(), sources.end(),
		[vs_token] (tt__ImagingVideoSource *ivs) { return ivs->VideoSourceToken == vs_token; });
	if (sources_it == sources.end()) {
		return false;
	}
	(*sources_it)->ImagingSettings->soap_del();
	(*sources_it)->ImagingSettings = new_imaging_settings->soap_dup();

	saveConfiguration();

	getVideoSourceConfiguration(*(getCurrentMinimumProfile()->VideoSourceConfigurationToken));

	if (vs_token == getCurrentVideoSourceConfiguration()->SourceToken) {
		rtsp_server->setImagingSettings(new_imaging_settings);
	}
	return true;
}


bool Camera::setVideoSourceConfiguration(const tt__VideoSourceConfiguration *new_vsc) {
	auto &vscs = config->MediaService->VideoSourceConfiguration;
	auto vsc_it = std::find_if(vscs.begin(), vscs.end(),
		[new_vsc] (tt__VideoSourceConfiguration *vsc) { return vsc->token == new_vsc->token; });
	if (vsc_it == vscs.end()) {
		return false;
	}

	auto *existing_vsc = *vsc_it;

	if (existing_vsc->SourceToken != new_vsc->SourceToken) {
		// Refuse to allow physical input changes on a configuration.
		// At the moment, none of our servers support more than one physical input,
		// and it would be cleaner to create a new VideoSourceConfiguration for another
		// physical input anyway.
		return false;
	}

	// We copy only the mutable fields across to the existing object.

	existing_vsc->Name = new_vsc->Name;
	existing_vsc->Bounds->soap_del();
	existing_vsc->Bounds = new_vsc->Bounds->soap_dup();

	if (existing_vsc->Extension != nullptr) {
		existing_vsc->Extension->soap_del();
	}
	if (new_vsc->Extension) {
		existing_vsc->Extension = new_vsc->Extension->soap_dup();
	}

	saveConfiguration();

	if (new_vsc->token == getCurrentVideoSourceConfiguration()->token) {
		rtsp_server->setVideoSourceConfiguration(new_vsc);
	}

	return true;
}