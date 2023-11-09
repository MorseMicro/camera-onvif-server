// Copyright 2023 Morse Micro
// SPDX-License-Identifier: GPL-2.0-or-later

#include "catch.hpp"
#include "fakeit.hpp"
#include "../camera.h"
#include "../utils.h"
#include "../soaplib/soapStub.h"


TEST_CASE( "Fails with bad config", "[camera]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;

	REQUIRE_THROWS_AS(new Camera("http://localhost:8080", "localhost", "tests/camera_properties_invalid.xml", "tests/camera_configuration.xml", &(rtspServerMock.get())), SoapError);
}


TEST_CASE( "Fails with missing API details if mediamtxrpi type", "[camera]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;

	// Mostly, our bad config is handled by being invalid XML (i.e. gsoap explodes).
	// However, the RTSP server type implies optional sections depending on
	// whether it's an API or not.
	REQUIRE_THROWS_AS(new Camera("http://localhost:8080", "localhost", "tests/camera_properties_mediamtxrpi_noapi.xml", "tests/camera_configuration.xml"), InvalidConfigError);
}


TEST_CASE( "Fails with missing executable if t31rtspd or nvtrtspd type", "[camera]" ) {
	fakeit::Mock<RtspServer> rtspServerMock;

	// Mostly, our bad config is handled by being invalid XML (i.e. gsoap explodes).
	// However, the RTSP server type implies optional sections depending on
	// whether it's an API or not.
	REQUIRE_THROWS_AS(new Camera("http://localhost:8080", "localhost", "tests/camera_properties_nvtrtspd_noexec.xml", "tests/camera_configuration.xml"), InvalidConfigError);
	REQUIRE_THROWS_AS(new Camera("http://localhost:8080", "localhost", "tests/camera_properties_t31rtspd_noexec.xml", "tests/camera_configuration.xml"), InvalidConfigError);
}