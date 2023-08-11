#pragma once

#include "soaplib/soapH.h"

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
		pid_t rtsp_server_pid;

		std::vector<std::string> buildRtspServerArguments();

	public:
		Camera(std::string onvif_url, std::string ip, _tt__CameraProperties *properties, _tt__CameraConfiguration *config);
		Camera(std::string onvif_url, std::string ip, std::string properties_filename, std::string config_filename);
		~Camera();

		void saveConfiguration();
		void saveConfiguration(std::ostream &camera_config_output);

		void startRtspServer();
		void stopRtspServerIfRunning();

		std::string getStreamUri();

		// Simple accessors.

		inline std::string getOnvifURL() {
			return this->onvif_url;
		}

		inline tt__DeviceInformation *getDeviceInformation() {
			return properties->DeviceManagementService->DeviceInformation;
		}

		inline const std::vector<tt__MinimumProfile *> getMinimumProfiles() {
			return config->MediaService->Profile;
		}

		inline const tt__MinimumProfile *getMinimumProfile(std::string &token) {
			auto &profiles = config->MediaService->Profile;
			auto profile_it = std::find_if(profiles.begin(), profiles.end(),
				[token] (tt__MinimumProfile *p) { return p->ProfileToken == token; });
			return profile_it == profiles.end() ? nullptr : *profile_it;
		}

		inline const tt__MinimumProfile *getCurrentMinimumProfile() {
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

		inline const std::vector<tt__VideoEncoderConfiguration *> getVideoEncoderConfigurations() {
			return config->MediaService->VideoEncoderConfiguration;
		}

		inline tt__VideoEncoderConfiguration *getVideoEncoderConfiguration(const std::string &vec_token) {
			auto &vecs = config->MediaService->VideoEncoderConfiguration;
			auto vec_it = std::find_if(vecs.begin(), vecs.end(),
				[vec_token] (tt__VideoEncoderConfiguration *vec) { return vec->token == vec_token; });
			return vec_it == vecs.end() ? nullptr : *vec_it;
		}

		inline bool setVideoEncoderConfiguration(tt__VideoEncoderConfiguration *new_vec) {
			auto &vecs = config->MediaService->VideoEncoderConfiguration;
			auto vec_it = std::find_if(vecs.begin(), vecs.end(),
				[new_vec] (tt__VideoEncoderConfiguration *vec) { return vec->token == new_vec->token; });
			if (vec_it == vecs.end()) {
				return false;
			}
			(*vec_it)->soap_del();
			*vec_it = new_vec->soap_dup();
			saveConfiguration();
			startRtspServer();
			return true;
		}

		inline const tt__VideoEncoderConfiguration *getCurrentVideoEncoderConfiguration() {
			return getVideoEncoderConfiguration(*(getCurrentMinimumProfile()->VideoEncoderConfigurationToken));
		}

		inline tt__VideoEncoderConfigurationOptions *getVideoEncoderConfigurationOptions() {
			return properties->MediaService->VideoEncoderConfigurationOptions;
		}

		inline std::vector<tt__VideoSource *> getVideoSources() {
			return properties->MediaService->VideoSource;
		}

		inline tt__VideoSourceConfiguration *getVideoSourceConfiguration(const std::string &vsc_token) {
			auto &vscs = config->MediaService->VideoSourceConfiguration;
			auto vsc_it = std::find_if(vscs.begin(), vscs.end(),
				[vsc_token] (tt__VideoSourceConfiguration *vsc) { return vsc->token == vsc_token; });
			return vsc_it == vscs.end() ? nullptr : *vsc_it;
		}

		inline std::vector<tt__VideoSourceConfiguration *> getVideoSourceConfigurations() {
			return config->MediaService->VideoSourceConfiguration;
		}

		inline tt__ImagingSettings20 *getImagingSettings(std::string &vsc_token) {
			auto &sources = config->ImagingService->ImagingVideoSource;
			auto sources_it = std::find_if(sources.begin(), sources.end(),
				[vsc_token] (tt__ImagingVideoSource *ivs) { return ivs->VideoSourceToken == vsc_token; });
			return sources_it == sources.end() ? nullptr : (*sources_it)->ImagingSettings;
		}

		inline tt__ImagingOptions20 *getImagingOptions(std::string &vsc_token) {
			auto &sources = properties->ImagingService->ImagingVideoSourceOptions;
			auto sources_it = std::find_if(sources.begin(), sources.end(),
				[vsc_token] (tt__ImagingVideoSourceOptions *ivs) { return ivs->VideoSourceToken == vsc_token; });
			return sources_it == sources.end() ? nullptr : (*sources_it)->ImagingOptions;
		}
};