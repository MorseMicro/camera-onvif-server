#include "rtspserver_mediamtxrpi.h"
#include "utils.h"

#include "soaplib/json.h"

#include <map>


static const std::map<tt__H264Profile, std::string> profileMap = {
	{tt__H264Profile::Baseline, "baseline"},
	{tt__H264Profile::Main, "main"},
	{tt__H264Profile::Extended, "main"},
	{tt__H264Profile::High, "high"},
};


// This is a copy of json_call from json.cpp (as of 2.8.127) with a customisable method parameter
// so we can make PATCH calls.
static int json_call_method(struct soap *soap, const char *endpoint, soap_http_command method, const struct json::value *in, struct json::value *out)
{
	if (out)
		json::soap_default_value(soap, out);
	soap->http_content = "application/json; charset=utf-8";
	if (soap_begin_count(soap)
		|| ((soap->mode & SOAP_IO_LENGTH) && json_send(soap, in))
		|| soap_end_count(soap)
		|| soap_connect_command(soap, method, endpoint, NULL) // <--- should be the only change
		|| json_send(soap, in)
		|| soap_end_send(soap)
		|| soap_begin_recv(soap)
		|| json_recv(soap, out)
		|| soap_end_recv(soap))
	{
		if (out)
			json_error(soap, out);
		else if (soap->error == 200 || soap->error == 201 || soap->error == 202 || soap->error == SOAP_EOF)
			soap->error = SOAP_OK;
	}

	return soap_closesock(soap);
}


static void videoEncoderConfigurationToJson(json::value *v, const tt__VideoEncoderConfiguration *vec) {
	(*v)["rpiCameraWidth"] = vec->Resolution->Width;
	(*v)["rpiCameraHeight"] = vec->Resolution->Height;
	(*v)["rpiCameraFPS"] = vec->RateControl->FrameRateLimit;
	(*v)["rpiCameraBitrate"] = vec->RateControl->BitrateLimit * 1000;
	(*v)["rpiCameraProfile"] = vec->H264 != nullptr ? profileMap.at(vec->H264->H264Profile) : "main";
	(*v)["rpiCameraIDRPeriod"] = vec->H264 != nullptr ? vec->H264->GovLength : 60;
}


void RtspServerMediaMtxRpi::initialise(const tt__VideoEncoderConfiguration *vec) {
	// The MediaMTX API is very 'RPC-y', and confusingly use http verbs AND the path to
	// indicate the actions. There's also nothing even close to an idempotent PUT, so we
	// have to first add the configuration, and if that fails, PATCH it.
	soap *soap = soap_new1(SOAP_C_UTFSTRING);
	json::value request(soap);
	request["source"] = "rpiCamera";
	videoEncoderConfigurationToJson(&request, vec);

	// WARNING: this will fail (400) if the RPI camera is already configured on a different
	// path, and will end up aborting (see SoapError below).
	const std::string endpoint = url + "/v3/config/paths/add/" + streamPath;

	if (json_call_method(soap, endpoint.c_str(), SOAP_POST_FILE, &request, nullptr)) {
		const std::string patch_endpoint = url + "/v3/config/paths/patch/" + streamPath;

		SoapError::ifNotOk(soap, "Initialising video encoder stream", 
		                   json_call_method(soap, patch_endpoint.c_str(), SOAP_PATCH, &request, nullptr));
	}

	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}


void RtspServerMediaMtxRpi::setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *vec) {
	soap *soap = soap_new1(SOAP_C_UTFSTRING);
	json::value request(soap);
	videoEncoderConfigurationToJson(&request, vec);

	const std::string endpoint = url + "/v3/config/paths/patch/" + streamPath;

	if (json_call_method(soap, endpoint.c_str(), SOAP_PATCH, &request, nullptr)) {
		std::cerr << "Error when updating video encoder configuration via " << endpoint << ":" << std::endl;
		soap_print_fault(soap, stderr);
	}

	soap_end(soap);
	soap_free(soap);
}

