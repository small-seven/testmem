#include "includes.h"
#include "common.h"
#include "crypto/tls.h"
#include "eap_common/eap_teap_common.h"
#include "eap_i.h"
#include "eap_tls_common.h"
#include "eap_config.h"
#include "eap_teap_pac.h"
#ifdef EAP_TEAP_DYNAMIC
#include "eap_teap_pac.c"
#endif /* EAP_TEAP_DYNAMIC */
#define EAP_TEAP_PROV_UNAUTH 1
#define EAP_TEAP_PROV_AUTH 2
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef EAP_TNC
#endif /* EAP_TNC */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#if 0 /* TODO */
#endif
#if 0 /* TODO */
#endif
