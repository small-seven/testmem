#include "includes.h"
#include "common.h"
#include "crypto/tls.h"
#include "crypto/sha1.h"
#include "eap_common/eap_tlv_common.h"
#include "eap_i.h"
#include "eap_tls_common.h"
#include "eap_config.h"
#include "eap_fast_pac.h"
#ifdef EAP_FAST_DYNAMIC
#include "eap_fast_pac.c"
#endif /* EAP_FAST_DYNAMIC */
#define EAP_FAST_PROV_UNAUTH 1
#define EAP_FAST_PROV_AUTH 2
#ifdef EAP_TNC
#endif /* EAP_TNC */
#if 0 /* FIX */
#endif
#if 0
#endif
