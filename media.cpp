// Copyright 2023 Morse Micro
// SPDX-License-Identifier: GPL-2.0-or-later

#include "soaplib/soapH.h"

#include "camera.h"


int __trt__GetVideoEncoderConfigurations(struct soap *soap, _trt__GetVideoEncoderConfigurations *request, _trt__GetVideoEncoderConfigurationsResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	response.Configurations = camera->getVideoEncoderConfigurations();

	return SOAP_OK;
}

int __trt__GetVideoEncoderConfiguration(struct soap *soap, _trt__GetVideoEncoderConfiguration *request, _trt__GetVideoEncoderConfigurationResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	auto *vec = camera->getVideoEncoderConfiguration(request->ConfigurationToken);

	if (vec == nullptr) {
		// TODO: how to handle errors properly?
		return SOAP_ERR;
	} else {
		response.Configuration = vec;
		return SOAP_OK;
	}
}

int __trt__SetVideoEncoderConfiguration(struct soap *soap, _trt__SetVideoEncoderConfiguration *request, _trt__SetVideoEncoderConfigurationResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	return camera->setVideoEncoderConfiguration(request->Configuration) ? SOAP_OK : SOAP_ERR;
}

int __trt__GetVideoEncoderConfigurationOptions(struct soap *soap, _trt__GetVideoEncoderConfigurationOptions *request, _trt__GetVideoEncoderConfigurationOptionsResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	response.Options = camera->getVideoEncoderConfigurationOptions();
	return SOAP_OK;
}

int __trt__GetVideoSources(struct soap *soap, _trt__GetVideoSources *request, _trt__GetVideoSourcesResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	response.VideoSources = camera->getVideoSources();
	return SOAP_OK;
}

int __trt__GetVideoSourceConfigurations(struct soap *soap, _trt__GetVideoSourceConfigurations *request, _trt__GetVideoSourceConfigurationsResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	response.Configurations = camera->getVideoSourceConfigurations();
	return SOAP_OK;
}

int __trt__SetVideoSourceConfiguration(struct soap *soap, _trt__SetVideoSourceConfiguration *request, _trt__SetVideoSourceConfigurationResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	return camera->setVideoSourceConfiguration(request->Configuration) ? SOAP_OK : SOAP_ERR;
}

int __trt__GetVideoSourceConfigurationOptions(struct soap *soap, _trt__GetVideoSourceConfigurationOptions *request, _trt__GetVideoSourceConfigurationOptionsResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	response.Options = camera->getVideoSourceConfigurationOptions(request->ConfigurationToken, request->ProfileToken);
	return SOAP_OK;
}

int __trt__GetProfiles(struct soap *soap, _trt__GetProfiles *request, _trt__GetProfilesResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	auto min_profiles = camera->getMinimumProfiles();
	for (auto mp_it : min_profiles) {
		auto *profile = soap_new_tt__Profile(soap);
		profile->Name = mp_it->Name;
		profile->token = mp_it->ProfileToken;
		profile->VideoEncoderConfiguration = camera->getVideoEncoderConfiguration(*mp_it->VideoEncoderConfigurationToken);
		profile->VideoSourceConfiguration = camera->getVideoSourceConfiguration(*mp_it->VideoSourceConfigurationToken);
		response.Profiles.push_back(profile);
	}
	return SOAP_OK;
}

int __trt__GetStreamUri(struct soap *soap, _trt__GetStreamUri *request, _trt__GetStreamUriResponse &response) {
	// We only have one stream, so for now just change the profile to whatever was requested
	// and return that URI.
	Camera *camera = static_cast<Camera *>(soap->user);
	if (!camera->setCurrentProfile(request->ProfileToken)) {
		// TODO
		return SOAP_ERR;
	}
	response.MediaUri = soap_new_tt__MediaUri(soap);
	response.MediaUri->Uri = camera->getStreamUri();
	response.MediaUri->InvalidAfterConnect = false;
	response.MediaUri->InvalidAfterReboot = false;
	response.MediaUri->Timeout = "PT0S";
	return SOAP_OK;
}

