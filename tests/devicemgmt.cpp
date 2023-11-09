// Copyright 2023 Morse Micro
// SPDX-License-Identifier: GPL-2.0-or-later

#include "catch.hpp"
#include "fakeit.hpp"
#include "../camera.h"
#include "../soaplib/soapStub.h"


TEST_CASE( "GetDeviceInformation returns correct info", "[devicemgmt]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("http://localhost:8080", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__tds__GetDeviceInformation(soap);
	auto *resp = soap_new__tds__GetDeviceInformationResponse(soap);

	REQUIRE(__tds__GetDeviceInformation(soap, req, *resp) == SOAP_OK);
	REQUIRE(resp->Manufacturer == "Morse Micro");
	REQUIRE(resp->Model == "RD02");
	REQUIRE(resp->FirmwareVersion == "1");
	REQUIRE(resp->SerialNumber == "1");
	REQUIRE(resp->HardwareId == "abcdefgh");

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetServices returns correct info", "[devicemgmt]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("http://localhost:8080", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__tds__GetServices(soap);
	auto *resp = soap_new__tds__GetServicesResponse(soap);

	REQUIRE(__tds__GetServices(soap, req, *resp) == SOAP_OK);
	// We rely on returning these in a particular order. Not a valid
	// test, but also easy to fix if we break.
	REQUIRE(!resp->Service.empty());
	tds__Service *imaging_service = resp->Service.back();
	REQUIRE(imaging_service->Namespace == SOAP_NAMESPACE_OF_timg);
	REQUIRE(imaging_service->XAddr == "http://localhost:8080");
	resp->Service.pop_back();

	REQUIRE(!resp->Service.empty());
	tds__Service *media_service = resp->Service.back();
	REQUIRE(media_service->Namespace == SOAP_NAMESPACE_OF_trt);
	REQUIRE(media_service->XAddr == "http://localhost:8080");
	resp->Service.pop_back();

	REQUIRE(!resp->Service.empty());
	tds__Service *device_service = resp->Service.back();
	REQUIRE(device_service->Namespace == SOAP_NAMESPACE_OF_tds);
	REQUIRE(device_service->XAddr == "http://localhost:8080");
	resp->Service.pop_back();

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetHostname returns correct info", "[devicemgmt]" ) {
	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	auto *req = soap_new__tds__GetHostname(soap);
	auto *resp = soap_new__tds__GetHostnameResponse(soap);

	char hostname[HOST_NAME_MAX];
	gethostname(hostname, HOST_NAME_MAX);

	REQUIRE(__tds__GetHostname(soap, req, *resp) == SOAP_OK);
	REQUIRE(!resp->HostnameInformation->FromDHCP);
	REQUIRE(*resp->HostnameInformation->Name == hostname);

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}