#include "includes.h"
#ifdef CONFIG_DYNAMIC_EAP_METHODS
#include <dlfcn.h>
#endif /* CONFIG_DYNAMIC_EAP_METHODS */
#include "common.h"
#include "eap_i.h"
#include "eap_methods.h"
#ifdef CONFIG_DYNAMIC_EAP_METHODS
#endif /* CONFIG_DYNAMIC_EAP_METHODS */
struct eap_method * eap_peer_method_alloc(int version, int vendor,
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
static void eap_peer_method_free(struct eap_method *method)
{
	os_free(method);
}
#ifdef CONFIG_DYNAMIC_EAP_METHODS
#endif /* CONFIG_DYNAMIC_EAP_METHODS */
#ifdef CONFIG_DYNAMIC_EAP_METHODS
#endif /* CONFIG_DYNAMIC_EAP_METHODS */
#ifdef CONFIG_DYNAMIC_EAP_METHODS
#endif /* CONFIG_DYNAMIC_EAP_METHODS */
