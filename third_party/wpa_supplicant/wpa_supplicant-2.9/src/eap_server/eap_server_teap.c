#include "includes.h"
#include "common.h"
#include "crypto/aes_wrap.h"
#include "crypto/tls.h"
#include "crypto/random.h"
#include "eap_common/eap_teap_common.h"
#include "eap_i.h"
#include "eap_tls_common.h"
#define PAC_OPAQUE_TYPE_PAD 0
#define PAC_OPAQUE_TYPE_KEY 1
#define PAC_OPAQUE_TYPE_LIFETIME 2
#define PAC_OPAQUE_TYPE_IDENTITY 3
#ifdef EAP_SERVER_TNC
#endif /* EAP_SERVER_TNC */
#ifdef EAP_SERVER_TNC
#endif /* EAP_SERVER_TNC */
