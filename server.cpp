#include <iostream>

#include "camera.h"

#include "soaplib/soap.nsmap"


void start_server(void *soap_user)
{
	struct soap *soap = soap_new();
	soap_set_namespaces(soap, soap_namespaces);

	soap->user = (void*)soap_user;
	soap->bind_flags |= SO_REUSEADDR;

	if (!soap_valid_socket(soap_bind(soap, NULL, 8080, 100)))
	{
		soap_print_fault(soap, stderr);
		soap_destroy(soap);
		soap_end(soap);
		soap_free(soap);
		return;
	}

	while (soap_valid_socket(soap_accept(soap))) {
		if (soap_serve(soap) != SOAP_OK) {
			soap_print_fault(soap, stderr);
			soap_print_fault_location(soap, stderr);
			soap_destroy(soap);
			soap_end(soap);
		}
	}

	soap_print_fault(soap, stderr);
	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
}
