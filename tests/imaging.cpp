#include "catch.hpp"
#include "../camera.h"
#include "../soaplib/soapStub.h"


TEST_CASE( "GetImagingSettings returns correct info", "[imaging]" ) {
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml");

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__timg__GetImagingSettings(soap);
	auto *resp = soap_new__timg__GetImagingSettingsResponse(soap);

	SECTION( "if the token exists, we get a valid settings object" ) {
		req->VideoSourceToken = "video_source_token";
		REQUIRE(__timg__GetImagingSettings(soap, req, *resp) == SOAP_OK);
		auto *settings = resp->ImagingSettings;
		// We don't actually have any settings available...
		REQUIRE(settings->Brightness == nullptr);
	}

	SECTION( "if the token doesn't exist, we get an error" ) {
		req->VideoSourceToken = "no_such_video_source_token";
		REQUIRE(__timg__GetImagingSettings(soap, req, *resp) == SOAP_ERR);
	}

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetOptions returns correct info", "[imaging]" ) {
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml");

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__timg__GetOptions(soap);
	auto *resp = soap_new__timg__GetOptionsResponse(soap);

	SECTION( "if the token exists, we get a valid options object" ) {
		req->VideoSourceToken = "video_source_token";
		REQUIRE(__timg__GetOptions(soap, req, *resp) == SOAP_OK);
		auto *settings = resp->ImagingOptions;
		REQUIRE(settings->Brightness->Min == 0);
		REQUIRE(settings->Brightness->Max == 0);
	}

	SECTION( "if the token doesn't exist, we get an error" ) {
		req->VideoSourceToken = "no_such_video_source_token";
		REQUIRE(__timg__GetOptions(soap, req, *resp) == SOAP_ERR);
	}

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}