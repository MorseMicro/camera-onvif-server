#include "catch.hpp"
#include "fakeit.hpp"
#include "../camera.h"
#include "../soaplib/soapStub.h"


TEST_CASE( "GetVideoEncoderConfigurations returns correct info", "[media]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__trt__GetVideoEncoderConfigurations(soap);
	auto *resp = soap_new__trt__GetVideoEncoderConfigurationsResponse(soap);

	REQUIRE(__trt__GetVideoEncoderConfigurations(soap, req, *resp) == SOAP_OK);
	REQUIRE(resp->Configurations.size() == 1);

	auto *vec = resp->Configurations.at(0);
	REQUIRE(vec->Name == "Default");
	REQUIRE(vec->token == "video_encoder_configuration_token");
	REQUIRE(vec->Encoding == tt__VideoEncoding::H264);

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetVideoEncoderConfiguration returns correct info", "[media]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__trt__GetVideoEncoderConfiguration(soap);
	auto *resp = soap_new__trt__GetVideoEncoderConfigurationResponse(soap);

	SECTION( "if the token exists, we get a valid config" ) {
		req->ConfigurationToken = "video_encoder_configuration_token";
		REQUIRE(__trt__GetVideoEncoderConfiguration(soap, req, *resp) == SOAP_OK);
		auto *vec = resp->Configuration;
		REQUIRE(vec->Name == "Default");
		REQUIRE(vec->token == "video_encoder_configuration_token");
		REQUIRE(vec->Encoding == tt__VideoEncoding::H264);
	}

	SECTION( "if the token doesn't exist, we get an error" ) {
		req->ConfigurationToken = "no_such_video_encoder_configuration_token";
		REQUIRE(__trt__GetVideoEncoderConfiguration(soap, req, *resp) == SOAP_ERR);
	}

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetVideoEncoderConfigurationOptions returns correct info", "[media]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__trt__GetVideoEncoderConfigurationOptions(soap);
	auto *resp = soap_new__trt__GetVideoEncoderConfigurationOptionsResponse(soap);

	REQUIRE(__trt__GetVideoEncoderConfigurationOptions(soap, req, *resp) == SOAP_OK);
	auto *veco = resp->Options;
	REQUIRE(veco->QualityRange->Min == 0);
	REQUIRE(veco->QualityRange->Max == 1);
	REQUIRE(veco->H264->H264ProfilesSupported.at(0) == tt__H264Profile::High);

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetVideoSources returns correct info", "[media]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__trt__GetVideoSources(soap);
	auto *resp = soap_new__trt__GetVideoSourcesResponse(soap);

	REQUIRE(__trt__GetVideoSources(soap, req, *resp) == SOAP_OK);
	REQUIRE(resp->VideoSources.size() == 1);
	auto *vs = resp->VideoSources.at(0);
	REQUIRE(vs->Framerate == 30);

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetVideoSourceConfigurations returns correct info", "[media]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__trt__GetVideoSourceConfigurations(soap);
	auto *resp = soap_new__trt__GetVideoSourceConfigurationsResponse(soap);

	REQUIRE(__trt__GetVideoSourceConfigurations(soap, req, *resp) == SOAP_OK);
	REQUIRE(resp->Configurations.size() == 1);
	auto *vsc = resp->Configurations.at(0);
	REQUIRE(vsc->Name == "Default");
	REQUIRE(vsc->SourceToken == "video_source_token");

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetProfiles returns correct info", "[media]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__trt__GetProfiles(soap);
	auto *resp = soap_new__trt__GetProfilesResponse(soap);

	REQUIRE(__trt__GetProfiles(soap, req, *resp) == SOAP_OK);
	REQUIRE(resp->Profiles.size() == 1);
	auto *profile = resp->Profiles.at(0);
	REQUIRE(profile->Name == "Default profile");
	REQUIRE(profile->token == "profile_token");
	REQUIRE(profile->VideoSourceConfiguration->token == "video_source_configuration_token");
	REQUIRE(profile->VideoEncoderConfiguration->token == "video_encoder_configuration_token");

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "GetStreamUri returns correct info", "[media]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__trt__GetStreamUri(soap);
	auto *resp = soap_new__trt__GetStreamUriResponse(soap);

	SECTION( "if the profile exists, we get a stream" ) {
		req->ProfileToken = "profile_token";
		REQUIRE(__trt__GetStreamUri(soap, req, *resp) == SOAP_OK);
		REQUIRE(resp->MediaUri->InvalidAfterConnect == false);
		REQUIRE(resp->MediaUri->InvalidAfterReboot == false);
		REQUIRE(resp->MediaUri->Timeout == "PT0S");
		REQUIRE(resp->MediaUri->Uri == "rtsp://localhost:8554/stream");
	}

	SECTION( "if the token doesn't exist, we get an error" ) {
		req->ProfileToken = "no such token";
		REQUIRE(__trt__GetStreamUri(soap, req, *resp) == SOAP_ERR);
	}

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}

TEST_CASE( "SetVideoEncoderConfiguration correctly mutates config", "[media]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;
	fakeit::Fake(Method(rtspServerMock, setVideoEncoderConfiguration));
	Camera c("localhost", "localhost", "tests/camera_properties.xml", "tests/camera_configuration.xml", &(rtspServerMock.get()));

	auto soap = soap_new1(SOAP_XML_STRICT|SOAP_XML_INDENT);
	soap->user = &c;
	auto *req = soap_new__trt__SetVideoEncoderConfiguration(soap);
	auto *resp = soap_new__trt__SetVideoEncoderConfigurationResponse(soap);
	auto *vce = c.getVideoEncoderConfiguration("video_encoder_configuration_token")->soap_dup();

	SECTION( "can mutate video encoder config" ) {
		req->Configuration = vce;
		vce->Resolution->Height = 999;
		REQUIRE(__trt__SetVideoEncoderConfiguration(soap, req, *resp) == SOAP_OK);
		auto *new_vce = c.getVideoEncoderConfiguration("video_encoder_configuration_token");
		REQUIRE(new_vce->Resolution->Height == 999);
		REQUIRE(new_vce->Resolution->Width == vce->Resolution->Width);
	}

	SECTION( "fails if token doesn't exist" ) {
		req->Configuration = vce;
		vce->token = "foo";
		vce->Resolution->Height = 999;
		REQUIRE(__trt__SetVideoEncoderConfiguration(soap, req, *resp) == SOAP_ERR);
		auto *new_vce = c.getVideoEncoderConfiguration("video_encoder_configuration_token");
		REQUIRE(new_vce->Resolution->Height != 999);
	}

	SECTION( "calls out to RtspServer" ) {
		req->Configuration = vce;
		vce->Resolution->Height = 999;
		REQUIRE(__trt__SetVideoEncoderConfiguration(soap, req, *resp) == SOAP_OK);
		fakeit::Verify(Method(rtspServerMock, setVideoEncoderConfiguration).Using(vce)).Once();
	}

	vce->soap_del();
	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}