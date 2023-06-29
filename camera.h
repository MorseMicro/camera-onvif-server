#include "soaplib/soapH.h"

#include <iostream>


class Camera {
	private:
		_tt__CameraProperties *properties;
		_tt__CameraConfiguration *config;
		std::string config_filename;
		struct soap *soap;
		pid_t rtsp_server_pid;

		tt__VideoEncoderConfiguration *getCurrentVideoEncoderConfiguration();
		std::string getStreamUri();
		std::vector<std::string> buildRtspServerArguments();

	public:
		Camera(_tt__CameraProperties *properties, _tt__CameraConfiguration *config);
		Camera(std::string properties_filename, std::string config_filename);
		~Camera();

		inline tt__DeviceInformation *getDeviceInformation() {
			return properties->DeviceManagementService->DeviceInformation;
		}

		void saveConfiguration();
		void saveConfiguration(std::ostream &camera_config_output);

		void startRtspServer();
		void stopRtspServerIfRunning();

};