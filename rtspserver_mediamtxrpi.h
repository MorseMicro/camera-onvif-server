/*
 * Copyright 2023 Morse Micro
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "soaplib/soapH.h"

#include "rtspserver.h"

#include <string>


class RtspServerMediaMtxRpi : public RtspServer {
	private:
		std::string url;
		std::string streamPath;

	public:
		explicit RtspServerMediaMtxRpi(std::string url, std::string streamPath)
			: url(url), streamPath(streamPath) {}

		/* Make sure the stream exists at the appropriate path. */
		virtual void initialise(const tt__VideoEncoderConfiguration *, const tt__ImagingSettings20 *, const tt__VideoSourceConfiguration *);

		virtual void setVideoEncoderConfiguration(const tt__VideoEncoderConfiguration *);

		virtual void setImagingSettings(const tt__ImagingSettings20 *);

		virtual void setVideoSourceConfiguration(const tt__VideoSourceConfiguration *);
};
