/*
 * Copyright 2023 Morse Micro
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include "soaplib/soapH.h"

#include "rtspserver.h"
#include "rtspserver_process.h"
#include "rtspserver_mediamtxrpi.h"

#include <algorithm>
#include <iostream>
#include <cassert>


class Camera {
	private:
		std::string onvif_url;
		std::string ip;
		_tt__CameraProperties *properties;
		_tt__CameraConfiguration *config;
		std::string config_filename;
		RtspServer *rtsp_server;

	public:
		explicit Camera(std::string onvif_url, std::string ip, std::string properties_filename, std::string config_filename, RtspServer *rtsp_server=nullptr);
		~Camera();

		void initialiseRtspServer();

		void saveConfiguration();
		void saveConfiguration(std::ostream &camera_config_output);

		std::string getStreamUri();

		// Simple accessors.

		std::string getOnvifURL() {
			return this->onvif_url;
		}

		tt__DeviceInformation *getDeviceInformation() {
			return properties->DeviceManagementService->DeviceInformation;
		}

		tt__HTMLWebServer *getHTMLWebServerSettings() {
			return properties->HTMLWebServer;
		}

		const std::vector<tt__MinimumProfile *> getMinimumProfiles() {
			return config->MediaService->Profile;
		}

		const tt__MinimumProfile *getMinimumProfile(std::string &token) {
			auto &profiles = config->MediaService->Profile;
			auto profile_it = std::find_if(profiles.begin(), profiles.end(),
				[token] (tt__MinimumProfile *p) { return p->ProfileToken == token; });
			return profile_it == profiles.end() ? nullptr : *profile_it;
		}

		const tt__MinimumProfile *getCurrentMinimumProfile() {
			auto *mp = getMinimumProfile(config->MediaService->CurrentProfile);
			assert(mp != nullptr);
			return mp;
		}

		bool setCurrentProfile(std::string &token) {
			auto *mp = getMinimumProfile(token);
			if (mp != nullptr) {
				config->MediaService->CurrentProfile = token;
			}

			return mp != nullptr;
		}

		const std::vector<tt__VideoEncoderConfiguration *> getVideoEncoderConfigurations() {
			return config->MediaService->VideoEncoderConfiguration;
		}

		tt__VideoEncoderConfiguration *getVideoEncoderConfiguration(const std::string &vec_token) {
			auto &vecs = config->MediaService->VideoEncoderConfiguration;
			auto vec_it = std::find_if(vecs.begin(), vecs.end(),
				[vec_token] (tt__VideoEncoderConfiguration *vec) { return vec->token == vec_token; });
			return vec_it == vecs.end() ? nullptr : *vec_it;
		}

		bool setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *new_vec);

		const tt__VideoEncoderConfiguration *getCurrentVideoEncoderConfiguration() {
			auto *vec = getVideoEncoderConfiguration(*(getCurrentMinimumProfile()->VideoEncoderConfigurationToken));
			assert(vec != nullptr);
			return vec;
		}

		tt__VideoEncoderConfigurationOptions *getVideoEncoderConfigurationOptions() {
			return properties->MediaService->VideoEncoderConfigurationOptions;
		}

		std::vector<tt__VideoSource *> getVideoSources() {
			return properties->MediaService->VideoSource;
		}

		tt__VideoSourceConfiguration *getVideoSourceConfiguration(const std::string &vsc_token) {
			auto &vscs = config->MediaService->VideoSourceConfiguration;
			auto vsc_it = std::find_if(vscs.begin(), vscs.end(),
				[vsc_token] (tt__VideoSourceConfiguration *vsc) { return vsc->token == vsc_token; });
			return vsc_it == vscs.end() ? nullptr : *vsc_it;
		}

		std::vector<tt__VideoSourceConfiguration *> getVideoSourceConfigurations() {
			return config->MediaService->VideoSourceConfiguration;
		}

		const tt__VideoSourceConfiguration *getCurrentVideoSourceConfiguration() {
			auto *vsc = getVideoSourceConfiguration(*(getCurrentMinimumProfile()->VideoSourceConfigurationToken));
			assert(vsc != nullptr);
			return vsc;
		}

		bool setVideoSourceConfiguration(const tt__VideoSourceConfiguration *vsc);

		tt__VideoSourceConfigurationOptions *getVideoSourceConfigurationOptions(std::string *vsc_token, std::string *profile_token) {
			// WARNING: we only support one set of options, so we ignore vsc_token/profile_token for now.
			return properties->MediaService->VideoSourceConfigurationOptions;
		}

		tt__ImagingSettings20 *getImagingSettings(const std::string &vs_token) {
			auto &sources = config->ImagingService->ImagingVideoSource;
			auto sources_it = std::find_if(sources.begin(), sources.end(),
				[vs_token] (tt__ImagingVideoSource *ivs) { return ivs->VideoSourceToken == vs_token; });
			return sources_it == sources.end() ? nullptr : (*sources_it)->ImagingSettings;
		}

		tt__ImagingSettings20 *getCurrentImagingSettings() {
			auto *imaging_settings = getImagingSettings(getCurrentVideoSourceConfiguration()->SourceToken);
			assert(imaging_settings != nullptr);
			return imaging_settings;
		}

		bool setImagingSettings(const std::string &vsc_token, const tt__ImagingSettings20 *new_imaging_settings);

		tt__ImagingOptions20 *getImagingOptions(std::string &vs_token) {
			auto &sources = properties->ImagingService->ImagingVideoSourceOptions;
			auto sources_it = std::find_if(sources.begin(), sources.end(),
				[vs_token] (tt__ImagingVideoSourceOptions *ivs) { return ivs->VideoSourceToken == vs_token; });
			return sources_it == sources.end() ? nullptr : (*sources_it)->ImagingOptions;
		}
};