#include "includes.h"
#include "common.h"
#include "eap_i.h"
#include "eap_methods.h"
struct eap_method * eap_server_method_alloc(int version, int vendor,
					    EapType method, const char *name)
{
	struct eap_method *eap;
	eap = os_zalloc(sizeof(*eap));
	if (eap == NULL)
		return NULL;
	eap->version = version;
	eap->vendor = vendor;
	eap->method = method;
	eap->name = name;
	return eap;
}
static void eap_server_method_free(struct eap_method *method)
{
	os_free(method);
}
