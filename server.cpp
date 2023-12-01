// Copyright 2023 Morse Micro
// SPDX-License-Identifier: GPL-2.0-or-later

#include <iostream>

#include "soaplib/soapH.h"
#include "soaplib/httpget.h"
#include "httpgethandler.h"


static int fignore(struct soap *, const char *tag) {
	// We don't currently have any auth, so we don't care what auth you
	// present (as we're going to pass it).
	// This is naughty, as it ignores the 'mustUnderstand' attribute;
	// the right fix would be to not pass the mustUnderstand attribute in the
	// client.
	if (std::string("wsse:Security") == tag) {
		return SOAP_OK;
	}

	return SOAP_TAG_MISMATCH;
}


void start_server(int port, void *soap_user)
{
	struct soap *soap = soap_new();
	soap_register_plugin_arg(soap, http_get, (void *)http_get_handler);

	soap->user = soap_user;
	soap->bind_flags |= SO_REUSEADDR;

	soap->fignore = fignore;

	if (!soap_valid_socket(soap_bind(soap, NULL, port, 100)))
	{
		soap_print_fault(soap, stderr);
		soap_destroy(soap);
		soap_end(soap);
		soap_free(soap);
		return;
	}

	while (soap_valid_socket(soap_accept(soap))) {
		int result = soap_serve(soap);
		// result is overloaded - either a SOAP code (<100) or an HTTP code.
		if (result != SOAP_OK && (result <= SOAP_ERR || result >= 400)) {
			soap_print_fault(soap, stderr);
			soap_print_fault_location(soap, stderr);
		}
		soap_destroy(soap);
		soap_end(soap);
	}

	soap_print_fault(soap, stderr);
	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}
