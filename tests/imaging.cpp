// Copyright 2023 Morse Micro
// SPDX-License-Identifier: GPL-2.0-or-later

#include "catch.hpp"
#include "fakeit.hpp"
#include "../camera.h"
#include "../soaplib/soapStub.h"


TEST_CASE( "GetImagingSettings returns correct info", "[imaging]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__timg__GetImagingSettings(soap);
	auto *resp = soap_new__timg__GetImagingSettingsResponse(soap);

	SECTION( "if the token exists, we get a valid settings object" ) {
		req->VideoSourceToken = "video_source_token";
		REQUIRE(__timg__GetImagingSettings(soap, req, *resp) == SOAP_OK);
		auto *settings = resp->ImagingSettings;
		REQUIRE(settings->Brightness != nullptr);
		REQUIRE(*(settings->Brightness) != 0);
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
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__timg__GetOptions(soap);
	auto *resp = soap_new__timg__GetOptionsResponse(soap);

	SECTION( "if the token exists, we get a valid options object" ) {
		req->VideoSourceToken = "video_source_token";
		REQUIRE(__timg__GetOptions(soap, req, *resp) == SOAP_OK);
		auto *settings = resp->ImagingOptions;
		REQUIRE(settings->Brightness->Min == 0);
		REQUIRE(settings->Brightness->Max == 1);
	}

	SECTION( "if the token doesn't exist, we get an error" ) {
		req->VideoSourceToken = "no_such_video_source_token";
		REQUIRE(__timg__GetOptions(soap, req, *resp) == SOAP_ERR);
	}

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "SetImagingSettings returns correct info", "[imaging]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	fakeit::Fake(Method(rtspServerMock, setImagingSettings));
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__timg__SetImagingSettings(soap);
	auto *resp = soap_new__timg__SetImagingSettingsResponse(soap);
	auto *imaging_settings = c.getImagingSettings("video_source_token")->soap_dup();

	SECTION( "can mutate imaging settings" ) {
		req->ImagingSettings = imaging_settings;
		req->VideoSourceToken = "video_source_token";
		*(imaging_settings->Brightness) = 1.0;
		REQUIRE(__timg__SetImagingSettings(soap, req, *resp) == SOAP_OK);
		REQUIRE(*(c.getImagingSettings(req->VideoSourceToken)->Brightness) == 1.0);
	}

	SECTION( "if the token doesn't exist, we get an error and nothing changes" ) {
		req->ImagingSettings = imaging_settings;
		req->VideoSourceToken = "no_such_video_source_token";
		REQUIRE(__timg__SetImagingSettings(soap, req, *resp) == SOAP_ERR);
		REQUIRE(*(c.getImagingSettings("video_source_token")->Brightness) != 1.0);
	}

	SECTION( "calls out to RtspServer" ) {
		req->ImagingSettings = imaging_settings;
		req->VideoSourceToken = "video_source_token";
		REQUIRE(__timg__SetImagingSettings(soap, req, *resp) == SOAP_OK);
		fakeit::Verify(Method(rtspServerMock, setImagingSettings).Using(imaging_settings)).Once();
	}

	imaging_settings->soap_del();
	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}