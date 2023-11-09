// Copyright 2023 Morse Micro
// SPDX-License-Identifier: GPL-2.0-or-later

// Hack to let us use to_string
// (some weird gcc 5.x issue using default T31 toolchain)
#define _GLIBCXX_USE_C99 1

#include <map>

#include "soaplib/soapH.h"

#include "camera.h"
#include "favicon.h"


static int soap_send_string(struct soap *soap, const std::string &s) {
	return soap_send(soap, s.c_str());
}

static const std::map<tt__H264Profile, std::string> H264ProfileMap = {
	{tt__H264Profile::Baseline, "Baseline"},
	{tt__H264Profile::Main, "Main"},
	{tt__H264Profile::Extended, "Extended"},
	{tt__H264Profile::High, "High"},
};

static const std::map<tt__Mpeg4Profile, std::string> Mpeg4ProfileMap = {
	{tt__Mpeg4Profile::SP, "Simple"},
	{tt__Mpeg4Profile::ASP, "Advanced"},
};

static const std::map<tt__AutoFocusMode, std::string> AutoFocusModeMap = {
	{tt__AutoFocusMode::MANUAL, "Manual"},
	{tt__AutoFocusMode::AUTO, "Auto"},
};

#define S(str) { soap_code = soap_send_string(soap, (str)); if (soap_code != SOAP_OK) return soap_code; }
#define TROW(a, b) S("<tr><td>"); S(a); S("</td><td>"); S(b); S("</tr>");
#define TROWNUM(a, b) S("<tr><td>"); S(a); S("</td><td>"); S(std::to_string(b)); S("</tr>");
#define TROWNUMOPT(a, b) if (b != nullptr) { S("<tr><td>"); S(a); S("</td><td>"); S(std::to_string(*b)); S("</tr>"); }


// Dump some of the current settings as the index page.
static int http_route_index(struct soap *soap) {
	int soap_code = soap_response(soap, SOAP_HTML);
	if (soap_code != SOAP_OK) {
		return soap_code;
	}

	S("<!DOCTYPE html>");
	S("<html><head><title>Camera ONVIF Server</title></head><body>");

	S("<h1>Camera ONVIF Server</h1>");

	auto *camera = static_cast<Camera *>(soap->user);

	auto *device_info = camera->getDeviceInformation();
	S("<h2>Device information</h2>");
	S("<table border=1 width=600>");
	TROW("Manufacturer", device_info->Manufacturer);
	TROW("Model", device_info->Model);
	TROW("FirmwareVersion", device_info->FirmwareVersion);
	TROW("SerialNumber", device_info->SerialNumber);
	TROW("HardwareId", device_info->HardwareId);
	S("</table>");

	auto *vec = camera->getCurrentVideoEncoderConfiguration();
	S("<h2>Encoder configuration</h2>");
	S("<table border=1 width=600>");
	switch (vec->Encoding) {
		case tt__VideoEncoding::H264:
			TROW("Encoding", "H264");
			if (vec->H264 != nullptr) {
				TROWNUM("GovLength", vec->H264->GovLength);
				TROW("Profile", H264ProfileMap.at(vec->H264->H264Profile));
			}
			break;
		case tt__VideoEncoding::MPEG4:
			TROW("Encoding", "MPEG4");
			if (vec->MPEG4 != nullptr) {
				TROWNUM("GovLength", vec->MPEG4->GovLength);
				TROW("Profile", Mpeg4ProfileMap.at(vec->MPEG4->Mpeg4Profile));
			}
			break;
		case tt__VideoEncoding::JPEG:
			TROW("Encoding", "JPEG");
			break;
	}
	TROW("Resolution", std::to_string(vec->Resolution->Width) + "x" + std::to_string(vec->Resolution->Height));
	TROWNUM("FrameRateLimit", vec->RateControl->FrameRateLimit);
	TROWNUM("BitrateLimit", vec->RateControl->BitrateLimit);
	S("</table>");

	auto *imaging_settings = camera->getCurrentImagingSettings();
	S("<h2>Imaging settings</h2>");
	S("<table border=1 width=600>");
	TROWNUMOPT("Brightness", imaging_settings->Brightness);
	TROWNUMOPT("Contrast", imaging_settings->Contrast);
	TROWNUMOPT("ColorSaturation", imaging_settings->ColorSaturation);
	TROWNUMOPT("Sharpness", imaging_settings->Sharpness);
	if (imaging_settings->Focus) {
		TROW("AutoFocusMode", AutoFocusModeMap.at(imaging_settings->Focus->AutoFocusMode));
	}
	S("</table>");

	S("</body></html>");


	return SOAP_OK;
}

// Include a favicon because otherwise we get too many spurious/cryptic 404s.
static int http_route_favicon(struct soap *soap) {
	soap->http_content = "application/binary";

	int soap_code = soap_response(soap, SOAP_FILE);
	if (soap_code != SOAP_OK) {
		return soap_code;
	}

	soap_code = soap_send_raw(soap, reinterpret_cast<const char *>(favicon), sizeof(favicon) / sizeof(favicon[0]));
	if (soap_code != SOAP_OK) {
		return soap_code;
	}

	return SOAP_OK;
}

static const std::map<std::string, int (*)(struct soap *)> http_routes = {
	{"/", http_route_index},
	{"/favicon.ico", http_route_favicon},
};


int http_get_handler(struct soap *soap) {
	if (http_routes.count(soap->path) == 0) {
		return 404;
	}

	if (http_routes.at(soap->path)(soap) != SOAP_OK) {
		return soap_closesock(soap);
	}

	soap_end_send(soap);
	return SOAP_OK;
}
