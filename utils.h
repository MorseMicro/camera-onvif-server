/*
 * Copyright 2023 Morse Micro
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include "soaplib/soapH.h"

#include <sys/types.h>

#include <vector>
#include <string>
#include <sstream>


extern pid_t start_child_process(std::string path, std::vector<std::string> arguments);


extern void stop_child_process(pid_t pid);


/* Currently, this is primarily used on startup when 'something bad' happens which means we're
 * not going to be able to function. i.e. it will log and then blow up the program.
 */
class SoapError: public std::runtime_error {
	public:
		explicit SoapError(const std::string &what_arg) : std::runtime_error(what_arg) {}

		static soap_status ifNotOk(struct soap *soap, const std::string &msg, soap_status status) {
			if (status == SOAP_OK) {
				return SOAP_OK;
			}
			
			std::stringstream ss;
			ss << msg << "\n";
			soap_stream_fault(soap, ss);
			soap_stream_fault_location(soap, ss);

			soap_destroy(soap);
			soap_end(soap);
			soap_free(soap);
			throw SoapError(ss.str());
			return status;  // Keep the compiler happy.
		}
};


class InvalidConfigError: public std::runtime_error {
	public:
		explicit InvalidConfigError(const std::string &what_arg) : std::runtime_error(what_arg) {}
};
