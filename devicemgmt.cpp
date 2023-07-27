#include <unistd.h>
#include <limits.h>

#include "soaplib/soapH.h"

#include "camera.h"


int __tds__GetDeviceInformation(struct soap *soap, _tds__GetDeviceInformation *request, _tds__GetDeviceInformationResponse &response) {
	auto *device_info = static_cast<Camera *>(soap->user)->getDeviceInformation();
	response.Manufacturer = device_info->Manufacturer;
	response.Model = device_info->Model;
	response.FirmwareVersion = device_info->FirmwareVersion;
	response.SerialNumber = device_info->SerialNumber;
	response.HardwareId = device_info->HardwareId;

	return SOAP_OK;
}

int __tds__GetServices(struct soap *soap, _tds__GetServices *request, _tds__GetServicesResponse &response) {
	// TODO Should be able to extract the versions from the WSDL files...
	auto *camera = static_cast<Camera *>(soap->user);

	auto device_service = soap_new_tds__Service(soap);
	device_service->Namespace = SOAP_NAMESPACE_OF_tds;
	device_service->XAddr = camera->getOnvifURL();
	device_service->Version = soap_new_tt__OnvifVersion(soap);
	device_service->Version->Major = 23;
	device_service->Version->Minor = 06;
	response.Service.push_back(device_service);

	auto media_service = soap_new_tds__Service(soap);
	media_service->Namespace = SOAP_NAMESPACE_OF_trt;
	media_service->XAddr = camera->getOnvifURL();
	media_service->Version = soap_new_tt__OnvifVersion(soap);
	media_service->Version->Major = 21;
	media_service->Version->Minor = 6;
	response.Service.push_back(media_service);

	auto imaging_service = soap_new_tds__Service(soap);
	imaging_service->Namespace = SOAP_NAMESPACE_OF_timg;
	imaging_service->XAddr = camera->getOnvifURL();
	imaging_service->Version = soap_new_tt__OnvifVersion(soap);
	imaging_service->Version->Major = 19;
	imaging_service->Version->Minor = 6;
	response.Service.push_back(imaging_service);

	return SOAP_OK;
}

int __tds__GetHostname(struct soap *soap, _tds__GetHostname *request, _tds__GetHostnameResponse &response) {
	response.HostnameInformation = soap_new_tt__HostnameInformation(soap);

	response.HostnameInformation->FromDHCP = false;  // Not sure how I can tell.
	response.HostnameInformation->Name = soap_new_tt__Name(soap);
	char hostname[HOST_NAME_MAX];
	gethostname(hostname, HOST_NAME_MAX);
	*(response.HostnameInformation->Name) = hostname;
	return SOAP_OK;
}

// This is supposedly replaced by 'GetServices', but some Python onvif client I found likes to use it to
// discover the URLs and explodes if it can't.
int __tds__GetCapabilities(struct soap *soap, _tds__GetCapabilities *request, _tds__GetCapabilitiesResponse &response) {
	auto *camera = static_cast<Camera *>(soap->user);

	response.Capabilities = soap_new_tt__Capabilities(soap);
	response.Capabilities->Device = soap_new_tt__DeviceCapabilities(soap);
	response.Capabilities->Device->XAddr = camera->getOnvifURL();
	response.Capabilities->Imaging = soap_new_tt__ImagingCapabilities(soap);
	response.Capabilities->Imaging->XAddr = camera->getOnvifURL();
	response.Capabilities->Media = soap_new_tt__MediaCapabilities(soap);
	response.Capabilities->Media->XAddr = camera->getOnvifURL();
	response.Capabilities->Media->StreamingCapabilities = soap_new_tt__RealTimeStreamingCapabilities(soap);

	return SOAP_OK;
}
