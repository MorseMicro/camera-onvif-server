#include "soaplib/soapH.h"
#include "soaplib/wsddapi.h"

#include "camera.h"

/** Web service operation '__tdn__Hello' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tdn__Hello(struct soap*, struct wsdd__HelloType tdn__Hello, struct wsdd__ResolveType &tdn__HelloResponse) {
	return SOAP_OK;
}

/** Web service operation '__tdn__Bye' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tdn__Bye(struct soap*, struct wsdd__ByeType tdn__Bye, struct wsdd__ResolveType &tdn__ByeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tdn__Probe' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tdn__Probe(struct soap*, struct wsdd__ProbeType tdn__Probe, struct wsdd__ProbeMatchesType &tdn__ProbeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetServiceCapabilities(struct soap*, _tds__GetServiceCapabilities *tds__GetServiceCapabilities, _tds__GetServiceCapabilitiesResponse &tds__GetServiceCapabilitiesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetSystemDateAndTime' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetSystemDateAndTime(struct soap*, _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, _tds__SetSystemDateAndTimeResponse &tds__SetSystemDateAndTimeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetSystemDateAndTime' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemDateAndTime(struct soap*, _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, _tds__GetSystemDateAndTimeResponse &tds__GetSystemDateAndTimeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetSystemFactoryDefault' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetSystemFactoryDefault(struct soap*, _tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, _tds__SetSystemFactoryDefaultResponse &tds__SetSystemFactoryDefaultResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__UpgradeSystemFirmware' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__UpgradeSystemFirmware(struct soap*, _tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, _tds__UpgradeSystemFirmwareResponse &tds__UpgradeSystemFirmwareResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SystemReboot' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SystemReboot(struct soap*, _tds__SystemReboot *tds__SystemReboot, _tds__SystemRebootResponse &tds__SystemRebootResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__RestoreSystem' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RestoreSystem(struct soap*, _tds__RestoreSystem *tds__RestoreSystem, _tds__RestoreSystemResponse &tds__RestoreSystemResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetSystemBackup' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemBackup(struct soap*, _tds__GetSystemBackup *tds__GetSystemBackup, _tds__GetSystemBackupResponse &tds__GetSystemBackupResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetSystemLog' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemLog(struct soap*, _tds__GetSystemLog *tds__GetSystemLog, _tds__GetSystemLogResponse &tds__GetSystemLogResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetSystemSupportInformation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemSupportInformation(struct soap*, _tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, _tds__GetSystemSupportInformationResponse &tds__GetSystemSupportInformationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetScopes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetScopes(struct soap*, _tds__GetScopes *tds__GetScopes, _tds__GetScopesResponse &tds__GetScopesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetScopes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetScopes(struct soap*, _tds__SetScopes *tds__SetScopes, _tds__SetScopesResponse &tds__SetScopesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__AddScopes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__AddScopes(struct soap*, _tds__AddScopes *tds__AddScopes, _tds__AddScopesResponse &tds__AddScopesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__RemoveScopes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RemoveScopes(struct soap*, _tds__RemoveScopes *tds__RemoveScopes, _tds__RemoveScopesResponse &tds__RemoveScopesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetDiscoveryMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDiscoveryMode(struct soap*, _tds__GetDiscoveryMode *tds__GetDiscoveryMode, _tds__GetDiscoveryModeResponse &tds__GetDiscoveryModeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetDiscoveryMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDiscoveryMode(struct soap*, _tds__SetDiscoveryMode *tds__SetDiscoveryMode, _tds__SetDiscoveryModeResponse &tds__SetDiscoveryModeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetRemoteDiscoveryMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRemoteDiscoveryMode(struct soap*, _tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, _tds__GetRemoteDiscoveryModeResponse &tds__GetRemoteDiscoveryModeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetRemoteDiscoveryMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRemoteDiscoveryMode(struct soap*, _tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, _tds__SetRemoteDiscoveryModeResponse &tds__SetRemoteDiscoveryModeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetDPAddresses' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDPAddresses(struct soap*, _tds__GetDPAddresses *tds__GetDPAddresses, _tds__GetDPAddressesResponse &tds__GetDPAddressesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetEndpointReference' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetEndpointReference(struct soap*, _tds__GetEndpointReference *tds__GetEndpointReference, _tds__GetEndpointReferenceResponse &tds__GetEndpointReferenceResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetRemoteUser' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRemoteUser(struct soap*, _tds__GetRemoteUser *tds__GetRemoteUser, _tds__GetRemoteUserResponse &tds__GetRemoteUserResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetRemoteUser' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRemoteUser(struct soap*, _tds__SetRemoteUser *tds__SetRemoteUser, _tds__SetRemoteUserResponse &tds__SetRemoteUserResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetUsers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetUsers(struct soap*, _tds__GetUsers *tds__GetUsers, _tds__GetUsersResponse &tds__GetUsersResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__CreateUsers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateUsers(struct soap*, _tds__CreateUsers *tds__CreateUsers, _tds__CreateUsersResponse &tds__CreateUsersResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__DeleteUsers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteUsers(struct soap*, _tds__DeleteUsers *tds__DeleteUsers, _tds__DeleteUsersResponse &tds__DeleteUsersResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetUser' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetUser(struct soap*, _tds__SetUser *tds__SetUser, _tds__SetUserResponse &tds__SetUserResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetWsdlUrl' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetWsdlUrl(struct soap*, _tds__GetWsdlUrl *tds__GetWsdlUrl, _tds__GetWsdlUrlResponse &tds__GetWsdlUrlResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetPasswordComplexityOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPasswordComplexityOptions(struct soap*, _tds__GetPasswordComplexityOptions *tds__GetPasswordComplexityOptions, _tds__GetPasswordComplexityOptionsResponse &tds__GetPasswordComplexityOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetPasswordComplexityConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPasswordComplexityConfiguration(struct soap*, _tds__GetPasswordComplexityConfiguration *tds__GetPasswordComplexityConfiguration, _tds__GetPasswordComplexityConfigurationResponse &tds__GetPasswordComplexityConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetPasswordComplexityConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetPasswordComplexityConfiguration(struct soap*, _tds__SetPasswordComplexityConfiguration *tds__SetPasswordComplexityConfiguration, _tds__SetPasswordComplexityConfigurationResponse &tds__SetPasswordComplexityConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetPasswordHistoryConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPasswordHistoryConfiguration(struct soap*, _tds__GetPasswordHistoryConfiguration *tds__GetPasswordHistoryConfiguration, _tds__GetPasswordHistoryConfigurationResponse &tds__GetPasswordHistoryConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetPasswordHistoryConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetPasswordHistoryConfiguration(struct soap*, _tds__SetPasswordHistoryConfiguration *tds__SetPasswordHistoryConfiguration, _tds__SetPasswordHistoryConfigurationResponse &tds__SetPasswordHistoryConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetAuthFailureWarningOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetAuthFailureWarningOptions(struct soap*, _tds__GetAuthFailureWarningOptions *tds__GetAuthFailureWarningOptions, _tds__GetAuthFailureWarningOptionsResponse &tds__GetAuthFailureWarningOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetAuthFailureWarningConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetAuthFailureWarningConfiguration(struct soap*, _tds__GetAuthFailureWarningConfiguration *tds__GetAuthFailureWarningConfiguration, _tds__GetAuthFailureWarningConfigurationResponse &tds__GetAuthFailureWarningConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetAuthFailureWarningConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetAuthFailureWarningConfiguration(struct soap*, _tds__SetAuthFailureWarningConfiguration *tds__SetAuthFailureWarningConfiguration, _tds__SetAuthFailureWarningConfigurationResponse &tds__SetAuthFailureWarningConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCapabilities(struct soap*, _tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse &tds__GetCapabilitiesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetDPAddresses' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDPAddresses(struct soap*, _tds__SetDPAddresses *tds__SetDPAddresses, _tds__SetDPAddressesResponse &tds__SetDPAddressesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetHostname' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHostname(struct soap*, _tds__SetHostname *tds__SetHostname, _tds__SetHostnameResponse &tds__SetHostnameResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetHostnameFromDHCP' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHostnameFromDHCP(struct soap*, _tds__SetHostnameFromDHCP *tds__SetHostnameFromDHCP, _tds__SetHostnameFromDHCPResponse &tds__SetHostnameFromDHCPResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetDNS' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDNS(struct soap*, _tds__GetDNS *tds__GetDNS, _tds__GetDNSResponse &tds__GetDNSResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetDNS' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDNS(struct soap*, _tds__SetDNS *tds__SetDNS, _tds__SetDNSResponse &tds__SetDNSResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetNTP' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNTP(struct soap*, _tds__GetNTP *tds__GetNTP, _tds__GetNTPResponse &tds__GetNTPResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetNTP' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNTP(struct soap*, _tds__SetNTP *tds__SetNTP, _tds__SetNTPResponse &tds__SetNTPResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetDynamicDNS' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDynamicDNS(struct soap*, _tds__GetDynamicDNS *tds__GetDynamicDNS, _tds__GetDynamicDNSResponse &tds__GetDynamicDNSResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetDynamicDNS' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDynamicDNS(struct soap*, _tds__SetDynamicDNS *tds__SetDynamicDNS, _tds__SetDynamicDNSResponse &tds__SetDynamicDNSResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetNetworkInterfaces' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkInterfaces(struct soap*, _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, _tds__GetNetworkInterfacesResponse &tds__GetNetworkInterfacesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetNetworkInterfaces' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkInterfaces(struct soap*, _tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, _tds__SetNetworkInterfacesResponse &tds__SetNetworkInterfacesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetNetworkProtocols' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkProtocols(struct soap*, _tds__GetNetworkProtocols *tds__GetNetworkProtocols, _tds__GetNetworkProtocolsResponse &tds__GetNetworkProtocolsResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetNetworkProtocols' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkProtocols(struct soap*, _tds__SetNetworkProtocols *tds__SetNetworkProtocols, _tds__SetNetworkProtocolsResponse &tds__SetNetworkProtocolsResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetNetworkDefaultGateway' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkDefaultGateway(struct soap*, _tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, _tds__GetNetworkDefaultGatewayResponse &tds__GetNetworkDefaultGatewayResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetNetworkDefaultGateway' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkDefaultGateway(struct soap*, _tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, _tds__SetNetworkDefaultGatewayResponse &tds__SetNetworkDefaultGatewayResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetZeroConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetZeroConfiguration(struct soap*, _tds__GetZeroConfiguration *tds__GetZeroConfiguration, _tds__GetZeroConfigurationResponse &tds__GetZeroConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetZeroConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetZeroConfiguration(struct soap*, _tds__SetZeroConfiguration *tds__SetZeroConfiguration, _tds__SetZeroConfigurationResponse &tds__SetZeroConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetIPAddressFilter' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetIPAddressFilter(struct soap*, _tds__GetIPAddressFilter *tds__GetIPAddressFilter, _tds__GetIPAddressFilterResponse &tds__GetIPAddressFilterResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetIPAddressFilter' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetIPAddressFilter(struct soap*, _tds__SetIPAddressFilter *tds__SetIPAddressFilter, _tds__SetIPAddressFilterResponse &tds__SetIPAddressFilterResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__AddIPAddressFilter' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__AddIPAddressFilter(struct soap*, _tds__AddIPAddressFilter *tds__AddIPAddressFilter, _tds__AddIPAddressFilterResponse &tds__AddIPAddressFilterResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__RemoveIPAddressFilter' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RemoveIPAddressFilter(struct soap*, _tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, _tds__RemoveIPAddressFilterResponse &tds__RemoveIPAddressFilterResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetAccessPolicy' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetAccessPolicy(struct soap*, _tds__GetAccessPolicy *tds__GetAccessPolicy, _tds__GetAccessPolicyResponse &tds__GetAccessPolicyResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetAccessPolicy' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetAccessPolicy(struct soap*, _tds__SetAccessPolicy *tds__SetAccessPolicy, _tds__SetAccessPolicyResponse &tds__SetAccessPolicyResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__CreateCertificate' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateCertificate(struct soap*, _tds__CreateCertificate *tds__CreateCertificate, _tds__CreateCertificateResponse &tds__CreateCertificateResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetCertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificates(struct soap*, _tds__GetCertificates *tds__GetCertificates, _tds__GetCertificatesResponse &tds__GetCertificatesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetCertificatesStatus' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificatesStatus(struct soap*, _tds__GetCertificatesStatus *tds__GetCertificatesStatus, _tds__GetCertificatesStatusResponse &tds__GetCertificatesStatusResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetCertificatesStatus' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetCertificatesStatus(struct soap*, _tds__SetCertificatesStatus *tds__SetCertificatesStatus, _tds__SetCertificatesStatusResponse &tds__SetCertificatesStatusResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__DeleteCertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteCertificates(struct soap*, _tds__DeleteCertificates *tds__DeleteCertificates, _tds__DeleteCertificatesResponse &tds__DeleteCertificatesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetPkcs10Request' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPkcs10Request(struct soap*, _tds__GetPkcs10Request *tds__GetPkcs10Request, _tds__GetPkcs10RequestResponse &tds__GetPkcs10RequestResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__LoadCertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCertificates(struct soap*, _tds__LoadCertificates *tds__LoadCertificates, _tds__LoadCertificatesResponse &tds__LoadCertificatesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetClientCertificateMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetClientCertificateMode(struct soap*, _tds__GetClientCertificateMode *tds__GetClientCertificateMode, _tds__GetClientCertificateModeResponse &tds__GetClientCertificateModeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetClientCertificateMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetClientCertificateMode(struct soap*, _tds__SetClientCertificateMode *tds__SetClientCertificateMode, _tds__SetClientCertificateModeResponse &tds__SetClientCertificateModeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetRelayOutputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRelayOutputs(struct soap*, _tds__GetRelayOutputs *tds__GetRelayOutputs, _tds__GetRelayOutputsResponse &tds__GetRelayOutputsResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetRelayOutputSettings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRelayOutputSettings(struct soap*, _tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, _tds__SetRelayOutputSettingsResponse &tds__SetRelayOutputSettingsResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetRelayOutputState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRelayOutputState(struct soap*, _tds__SetRelayOutputState *tds__SetRelayOutputState, _tds__SetRelayOutputStateResponse &tds__SetRelayOutputStateResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SendAuxiliaryCommand' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SendAuxiliaryCommand(struct soap*, _tds__SendAuxiliaryCommand *tds__SendAuxiliaryCommand, _tds__SendAuxiliaryCommandResponse &tds__SendAuxiliaryCommandResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetCACertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCACertificates(struct soap*, _tds__GetCACertificates *tds__GetCACertificates, _tds__GetCACertificatesResponse &tds__GetCACertificatesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__LoadCertificateWithPrivateKey' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCertificateWithPrivateKey(struct soap*, _tds__LoadCertificateWithPrivateKey *tds__LoadCertificateWithPrivateKey, _tds__LoadCertificateWithPrivateKeyResponse &tds__LoadCertificateWithPrivateKeyResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetCertificateInformation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificateInformation(struct soap*, _tds__GetCertificateInformation *tds__GetCertificateInformation, _tds__GetCertificateInformationResponse &tds__GetCertificateInformationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__LoadCACertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCACertificates(struct soap*, _tds__LoadCACertificates *tds__LoadCACertificates, _tds__LoadCACertificatesResponse &tds__LoadCACertificatesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__CreateDot1XConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateDot1XConfiguration(struct soap*, _tds__CreateDot1XConfiguration *tds__CreateDot1XConfiguration, _tds__CreateDot1XConfigurationResponse &tds__CreateDot1XConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetDot1XConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDot1XConfiguration(struct soap*, _tds__SetDot1XConfiguration *tds__SetDot1XConfiguration, _tds__SetDot1XConfigurationResponse &tds__SetDot1XConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetDot1XConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot1XConfiguration(struct soap*, _tds__GetDot1XConfiguration *tds__GetDot1XConfiguration, _tds__GetDot1XConfigurationResponse &tds__GetDot1XConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetDot1XConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot1XConfigurations(struct soap*, _tds__GetDot1XConfigurations *tds__GetDot1XConfigurations, _tds__GetDot1XConfigurationsResponse &tds__GetDot1XConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__DeleteDot1XConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteDot1XConfiguration(struct soap*, _tds__DeleteDot1XConfiguration *tds__DeleteDot1XConfiguration, _tds__DeleteDot1XConfigurationResponse &tds__DeleteDot1XConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetDot11Capabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot11Capabilities(struct soap*, _tds__GetDot11Capabilities *tds__GetDot11Capabilities, _tds__GetDot11CapabilitiesResponse &tds__GetDot11CapabilitiesResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetDot11Status' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot11Status(struct soap*, _tds__GetDot11Status *tds__GetDot11Status, _tds__GetDot11StatusResponse &tds__GetDot11StatusResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__ScanAvailableDot11Networks' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__ScanAvailableDot11Networks(struct soap*, _tds__ScanAvailableDot11Networks *tds__ScanAvailableDot11Networks, _tds__ScanAvailableDot11NetworksResponse &tds__ScanAvailableDot11NetworksResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetSystemUris' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemUris(struct soap*, _tds__GetSystemUris *tds__GetSystemUris, _tds__GetSystemUrisResponse &tds__GetSystemUrisResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__StartFirmwareUpgrade' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__StartFirmwareUpgrade(struct soap*, _tds__StartFirmwareUpgrade *tds__StartFirmwareUpgrade, _tds__StartFirmwareUpgradeResponse &tds__StartFirmwareUpgradeResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__StartSystemRestore' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__StartSystemRestore(struct soap*, _tds__StartSystemRestore *tds__StartSystemRestore, _tds__StartSystemRestoreResponse &tds__StartSystemRestoreResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetStorageConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetStorageConfigurations(struct soap*, _tds__GetStorageConfigurations *tds__GetStorageConfigurations, _tds__GetStorageConfigurationsResponse &tds__GetStorageConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__CreateStorageConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateStorageConfiguration(struct soap*, _tds__CreateStorageConfiguration *tds__CreateStorageConfiguration, _tds__CreateStorageConfigurationResponse &tds__CreateStorageConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetStorageConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetStorageConfiguration(struct soap*, _tds__GetStorageConfiguration *tds__GetStorageConfiguration, _tds__GetStorageConfigurationResponse &tds__GetStorageConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetStorageConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetStorageConfiguration(struct soap*, _tds__SetStorageConfiguration *tds__SetStorageConfiguration, _tds__SetStorageConfigurationResponse &tds__SetStorageConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__DeleteStorageConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteStorageConfiguration(struct soap*, _tds__DeleteStorageConfiguration *tds__DeleteStorageConfiguration, _tds__DeleteStorageConfigurationResponse &tds__DeleteStorageConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__GetGeoLocation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetGeoLocation(struct soap*, _tds__GetGeoLocation *tds__GetGeoLocation, _tds__GetGeoLocationResponse &tds__GetGeoLocationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetGeoLocation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetGeoLocation(struct soap*, _tds__SetGeoLocation *tds__SetGeoLocation, _tds__SetGeoLocationResponse &tds__SetGeoLocationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__DeleteGeoLocation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteGeoLocation(struct soap*, _tds__DeleteGeoLocation *tds__DeleteGeoLocation, _tds__DeleteGeoLocationResponse &tds__DeleteGeoLocationResponse) {
	return SOAP_OK;
}

/** Web service operation '__tds__SetHashingAlgorithm' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHashingAlgorithm(struct soap*, _tds__SetHashingAlgorithm *tds__SetHashingAlgorithm, _tds__SetHashingAlgorithmResponse &tds__SetHashingAlgorithmResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetServiceCapabilities(struct soap*, _timg__GetServiceCapabilities *timg__GetServiceCapabilities, _timg__GetServiceCapabilitiesResponse &timg__GetServiceCapabilitiesResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__GetImagingSettings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetImagingSettings(struct soap*, _timg__GetImagingSettings *timg__GetImagingSettings, _timg__GetImagingSettingsResponse &timg__GetImagingSettingsResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__SetImagingSettings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__SetImagingSettings(struct soap*, _timg__SetImagingSettings *timg__SetImagingSettings, _timg__SetImagingSettingsResponse &timg__SetImagingSettingsResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__GetOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetOptions(struct soap*, _timg__GetOptions *timg__GetOptions, _timg__GetOptionsResponse &timg__GetOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__Move' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__Move(struct soap*, _timg__Move *timg__Move, _timg__MoveResponse &timg__MoveResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__Stop' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__Stop(struct soap*, _timg__Stop *timg__Stop, _timg__StopResponse &timg__StopResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__GetStatus' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetStatus(struct soap*, _timg__GetStatus *timg__GetStatus, _timg__GetStatusResponse &timg__GetStatusResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__GetMoveOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetMoveOptions(struct soap*, _timg__GetMoveOptions *timg__GetMoveOptions, _timg__GetMoveOptionsResponse &timg__GetMoveOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__GetPresets' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetPresets(struct soap*, _timg__GetPresets *timg__GetPresets, _timg__GetPresetsResponse &timg__GetPresetsResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__GetCurrentPreset' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetCurrentPreset(struct soap*, _timg__GetCurrentPreset *timg__GetCurrentPreset, _timg__GetCurrentPresetResponse &timg__GetCurrentPresetResponse) {
	return SOAP_OK;
}

/** Web service operation '__timg__SetCurrentPreset' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__SetCurrentPreset(struct soap*, _timg__SetCurrentPreset *timg__SetCurrentPreset, _timg__SetCurrentPresetResponse &timg__SetCurrentPresetResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetServiceCapabilities(struct soap*, _trt__GetServiceCapabilities *trt__GetServiceCapabilities, _trt__GetServiceCapabilitiesResponse &trt__GetServiceCapabilitiesResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoSources' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSources(struct soap*, _trt__GetVideoSources *trt__GetVideoSources, _trt__GetVideoSourcesResponse &trt__GetVideoSourcesResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioSources' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSources(struct soap*, _trt__GetAudioSources *trt__GetAudioSources, _trt__GetAudioSourcesResponse &trt__GetAudioSourcesResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioOutputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputs(struct soap*, _trt__GetAudioOutputs *trt__GetAudioOutputs, _trt__GetAudioOutputsResponse &trt__GetAudioOutputsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__CreateProfile' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__CreateProfile(struct soap*, _trt__CreateProfile *trt__CreateProfile, _trt__CreateProfileResponse &trt__CreateProfileResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetProfile' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetProfile(struct soap*, _trt__GetProfile *trt__GetProfile, _trt__GetProfileResponse &trt__GetProfileResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetProfiles' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetProfiles(struct soap*, _trt__GetProfiles *trt__GetProfiles, _trt__GetProfilesResponse &trt__GetProfilesResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddVideoEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoEncoderConfiguration(struct soap*, _trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, _trt__AddVideoEncoderConfigurationResponse &trt__AddVideoEncoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoSourceConfiguration(struct soap*, _trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, _trt__AddVideoSourceConfigurationResponse &trt__AddVideoSourceConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddAudioEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioEncoderConfiguration(struct soap*, _trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, _trt__AddAudioEncoderConfigurationResponse &trt__AddAudioEncoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioSourceConfiguration(struct soap*, _trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, _trt__AddAudioSourceConfigurationResponse &trt__AddAudioSourceConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddPTZConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddPTZConfiguration(struct soap*, _trt__AddPTZConfiguration *trt__AddPTZConfiguration, _trt__AddPTZConfigurationResponse &trt__AddPTZConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoAnalyticsConfiguration(struct soap*, _trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, _trt__AddVideoAnalyticsConfigurationResponse &trt__AddVideoAnalyticsConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddMetadataConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddMetadataConfiguration(struct soap*, _trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, _trt__AddMetadataConfigurationResponse &trt__AddMetadataConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioOutputConfiguration(struct soap*, _trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, _trt__AddAudioOutputConfigurationResponse &trt__AddAudioOutputConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__AddAudioDecoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioDecoderConfiguration(struct soap*, _trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, _trt__AddAudioDecoderConfigurationResponse &trt__AddAudioDecoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemoveVideoEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoEncoderConfiguration(struct soap*, _trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, _trt__RemoveVideoEncoderConfigurationResponse &trt__RemoveVideoEncoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemoveVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoSourceConfiguration(struct soap*, _trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, _trt__RemoveVideoSourceConfigurationResponse &trt__RemoveVideoSourceConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemoveAudioEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioEncoderConfiguration(struct soap*, _trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, _trt__RemoveAudioEncoderConfigurationResponse &trt__RemoveAudioEncoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemoveAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioSourceConfiguration(struct soap*, _trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, _trt__RemoveAudioSourceConfigurationResponse &trt__RemoveAudioSourceConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemovePTZConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemovePTZConfiguration(struct soap*, _trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, _trt__RemovePTZConfigurationResponse &trt__RemovePTZConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemoveVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoAnalyticsConfiguration(struct soap*, _trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, _trt__RemoveVideoAnalyticsConfigurationResponse &trt__RemoveVideoAnalyticsConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemoveMetadataConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveMetadataConfiguration(struct soap*, _trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, _trt__RemoveMetadataConfigurationResponse &trt__RemoveMetadataConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemoveAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioOutputConfiguration(struct soap*, _trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, _trt__RemoveAudioOutputConfigurationResponse &trt__RemoveAudioOutputConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__RemoveAudioDecoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioDecoderConfiguration(struct soap*, _trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, _trt__RemoveAudioDecoderConfigurationResponse &trt__RemoveAudioDecoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__DeleteProfile' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__DeleteProfile(struct soap*, _trt__DeleteProfile *trt__DeleteProfile, _trt__DeleteProfileResponse &trt__DeleteProfileResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoSourceConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfigurations(struct soap*, _trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, _trt__GetVideoSourceConfigurationsResponse &trt__GetVideoSourceConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoEncoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfigurations(struct soap*, _trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, _trt__GetVideoEncoderConfigurationsResponse &trt__GetVideoEncoderConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioSourceConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfigurations(struct soap*, _trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, _trt__GetAudioSourceConfigurationsResponse &trt__GetAudioSourceConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioEncoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfigurations(struct soap*, _trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, _trt__GetAudioEncoderConfigurationsResponse &trt__GetAudioEncoderConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoAnalyticsConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoAnalyticsConfigurations(struct soap*, _trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, _trt__GetVideoAnalyticsConfigurationsResponse &trt__GetVideoAnalyticsConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetMetadataConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfigurations(struct soap*, _trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, _trt__GetMetadataConfigurationsResponse &trt__GetMetadataConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioOutputConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfigurations(struct soap*, _trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, _trt__GetAudioOutputConfigurationsResponse &trt__GetAudioOutputConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioDecoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfigurations(struct soap*, _trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, _trt__GetAudioDecoderConfigurationsResponse &trt__GetAudioDecoderConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfiguration(struct soap*, _trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, _trt__GetVideoSourceConfigurationResponse &trt__GetVideoSourceConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfiguration(struct soap*, _trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, _trt__GetVideoEncoderConfigurationResponse &trt__GetVideoEncoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfiguration(struct soap*, _trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, _trt__GetAudioSourceConfigurationResponse &trt__GetAudioSourceConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfiguration(struct soap*, _trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, _trt__GetAudioEncoderConfigurationResponse &trt__GetAudioEncoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoAnalyticsConfiguration(struct soap*, _trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, _trt__GetVideoAnalyticsConfigurationResponse &trt__GetVideoAnalyticsConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetMetadataConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfiguration(struct soap*, _trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, _trt__GetMetadataConfigurationResponse &trt__GetMetadataConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfiguration(struct soap*, _trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, _trt__GetAudioOutputConfigurationResponse &trt__GetAudioOutputConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioDecoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfiguration(struct soap*, _trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, _trt__GetAudioDecoderConfigurationResponse &trt__GetAudioDecoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetCompatibleVideoEncoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoEncoderConfigurations(struct soap*, _trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, _trt__GetCompatibleVideoEncoderConfigurationsResponse &trt__GetCompatibleVideoEncoderConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetCompatibleVideoSourceConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoSourceConfigurations(struct soap*, _trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, _trt__GetCompatibleVideoSourceConfigurationsResponse &trt__GetCompatibleVideoSourceConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetCompatibleAudioEncoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioEncoderConfigurations(struct soap*, _trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, _trt__GetCompatibleAudioEncoderConfigurationsResponse &trt__GetCompatibleAudioEncoderConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetCompatibleAudioSourceConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioSourceConfigurations(struct soap*, _trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, _trt__GetCompatibleAudioSourceConfigurationsResponse &trt__GetCompatibleAudioSourceConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetCompatibleVideoAnalyticsConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoAnalyticsConfigurations(struct soap*, _trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, _trt__GetCompatibleVideoAnalyticsConfigurationsResponse &trt__GetCompatibleVideoAnalyticsConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetCompatibleMetadataConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleMetadataConfigurations(struct soap*, _trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, _trt__GetCompatibleMetadataConfigurationsResponse &trt__GetCompatibleMetadataConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetCompatibleAudioOutputConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioOutputConfigurations(struct soap*, _trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, _trt__GetCompatibleAudioOutputConfigurationsResponse &trt__GetCompatibleAudioOutputConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetCompatibleAudioDecoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioDecoderConfigurations(struct soap*, _trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, _trt__GetCompatibleAudioDecoderConfigurationsResponse &trt__GetCompatibleAudioDecoderConfigurationsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoSourceConfiguration(struct soap*, _trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, _trt__SetVideoSourceConfigurationResponse &trt__SetVideoSourceConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetVideoEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoEncoderConfiguration(struct soap*, _trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, _trt__SetVideoEncoderConfigurationResponse &trt__SetVideoEncoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioSourceConfiguration(struct soap*, _trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, _trt__SetAudioSourceConfigurationResponse &trt__SetAudioSourceConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetAudioEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioEncoderConfiguration(struct soap*, _trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, _trt__SetAudioEncoderConfigurationResponse &trt__SetAudioEncoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoAnalyticsConfiguration(struct soap*, _trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, _trt__SetVideoAnalyticsConfigurationResponse &trt__SetVideoAnalyticsConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetMetadataConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetMetadataConfiguration(struct soap*, _trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, _trt__SetMetadataConfigurationResponse &trt__SetMetadataConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioOutputConfiguration(struct soap*, _trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, _trt__SetAudioOutputConfigurationResponse &trt__SetAudioOutputConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetAudioDecoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioDecoderConfiguration(struct soap*, _trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, _trt__SetAudioDecoderConfigurationResponse &trt__SetAudioDecoderConfigurationResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoSourceConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfigurationOptions(struct soap*, _trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, _trt__GetVideoSourceConfigurationOptionsResponse &trt__GetVideoSourceConfigurationOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoEncoderConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfigurationOptions(struct soap*, _trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, _trt__GetVideoEncoderConfigurationOptionsResponse &trt__GetVideoEncoderConfigurationOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioSourceConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfigurationOptions(struct soap*, _trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, _trt__GetAudioSourceConfigurationOptionsResponse &trt__GetAudioSourceConfigurationOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioEncoderConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfigurationOptions(struct soap*, _trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, _trt__GetAudioEncoderConfigurationOptionsResponse &trt__GetAudioEncoderConfigurationOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetMetadataConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfigurationOptions(struct soap*, _trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, _trt__GetMetadataConfigurationOptionsResponse &trt__GetMetadataConfigurationOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioOutputConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfigurationOptions(struct soap*, _trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, _trt__GetAudioOutputConfigurationOptionsResponse &trt__GetAudioOutputConfigurationOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetAudioDecoderConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfigurationOptions(struct soap*, _trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, _trt__GetAudioDecoderConfigurationOptionsResponse &trt__GetAudioDecoderConfigurationOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetGuaranteedNumberOfVideoEncoderInstances' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetGuaranteedNumberOfVideoEncoderInstances(struct soap*, _trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse &trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetStreamUri' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetStreamUri(struct soap*, _trt__GetStreamUri *trt__GetStreamUri, _trt__GetStreamUriResponse &trt__GetStreamUriResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__StartMulticastStreaming' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__StartMulticastStreaming(struct soap*, _trt__StartMulticastStreaming *trt__StartMulticastStreaming, _trt__StartMulticastStreamingResponse &trt__StartMulticastStreamingResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__StopMulticastStreaming' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__StopMulticastStreaming(struct soap*, _trt__StopMulticastStreaming *trt__StopMulticastStreaming, _trt__StopMulticastStreamingResponse &trt__StopMulticastStreamingResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetSynchronizationPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetSynchronizationPoint(struct soap*, _trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, _trt__SetSynchronizationPointResponse &trt__SetSynchronizationPointResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetSnapshotUri' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetSnapshotUri(struct soap*, _trt__GetSnapshotUri *trt__GetSnapshotUri, _trt__GetSnapshotUriResponse &trt__GetSnapshotUriResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetVideoSourceModes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceModes(struct soap*, _trt__GetVideoSourceModes *trt__GetVideoSourceModes, _trt__GetVideoSourceModesResponse &trt__GetVideoSourceModesResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetVideoSourceMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoSourceMode(struct soap*, _trt__SetVideoSourceMode *trt__SetVideoSourceMode, _trt__SetVideoSourceModeResponse &trt__SetVideoSourceModeResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetOSDs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSDs(struct soap*, _trt__GetOSDs *trt__GetOSDs, _trt__GetOSDsResponse &trt__GetOSDsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetOSD' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSD(struct soap*, _trt__GetOSD *trt__GetOSD, _trt__GetOSDResponse &trt__GetOSDResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__GetOSDOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSDOptions(struct soap*, _trt__GetOSDOptions *trt__GetOSDOptions, _trt__GetOSDOptionsResponse &trt__GetOSDOptionsResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__SetOSD' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetOSD(struct soap*, _trt__SetOSD *trt__SetOSD, _trt__SetOSDResponse &trt__SetOSDResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__CreateOSD' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__CreateOSD(struct soap*, _trt__CreateOSD *trt__CreateOSD, _trt__CreateOSDResponse &trt__CreateOSDResponse) {
	return SOAP_OK;
}

/** Web service operation '__trt__DeleteOSD' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__DeleteOSD(struct soap*, _trt__DeleteOSD *trt__DeleteOSD, _trt__DeleteOSDResponse &trt__DeleteOSDResponse) {
	return SOAP_OK;
}

/** WSDD events */
void wsdd_event_Hello(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, const char *EndpointReference, const char *Types, const char *Scopes, const char *MatchBy, const char *XAddrs, unsigned int MetadataVersion)
{ }

void wsdd_event_Bye(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, const char *EndpointReference, const char *Types, const char *Scopes, const char *MatchBy, const char *XAddrs, unsigned int *MetadataVersion)
{ }

void wsdd_event_ProbeMatches(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, struct wsdd__ProbeMatchesType *ProbeMatches)
{ }

soap_wsdd_mode wsdd_event_Resolve(struct soap *soap, const char *MessageID, const char *ReplyTo, const char *EndpointReference, struct wsdd__ResolveMatchType *match)
{
	return SOAP_WSDD_ADHOC;
}

void wsdd_event_ResolveMatches(struct soap *soap, unsigned int InstanceId, const char * SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, struct wsdd__ResolveMatchType *match)
{ }
