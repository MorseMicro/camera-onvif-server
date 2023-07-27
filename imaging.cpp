#include "soaplib/soapH.h"

#include "camera.h"

int __timg__GetImagingSettings(struct soap *soap, _timg__GetImagingSettings *request, _timg__GetImagingSettingsResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	auto *settings = camera->getImagingSettings(request->VideoSourceToken);
	if (settings == nullptr) {
		return SOAP_ERR;
	}
	response.ImagingSettings = settings;
	return SOAP_OK;
}

int __timg__GetOptions(struct soap *soap, _timg__GetOptions *request, _timg__GetOptionsResponse &response) {
	Camera *camera = static_cast<Camera *>(soap->user);
	auto *options = camera->getImagingOptions(request->VideoSourceToken);
	if (options == nullptr) {
		return SOAP_ERR;
	}
	response.ImagingOptions = options;
	return SOAP_OK;
}
