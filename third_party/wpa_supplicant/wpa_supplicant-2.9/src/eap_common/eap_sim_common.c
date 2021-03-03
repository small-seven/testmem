#include "includes.h"
#include "common.h"
#include "wpabuf.h"
#include "crypto/aes_wrap.h"
#include "crypto/crypto.h"
#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "crypto/random.h"
#include "eap_common/eap_defs.h"
#include "eap_common/eap_sim_common.h"
#if defined(EAP_AKA_PRIME) || defined(EAP_SERVER_AKA_PRIME)
#endif /* EAP_AKA_PRIME || EAP_SERVER_AKA_PRIME */
#if defined(EAP_AKA_PRIME) || defined(EAP_SERVER_AKA_PRIME)
#endif /* EAP_AKA_PRIME || EAP_SERVER_AKA_PRIME */
#ifdef TEST_FUZZ
#else /* TEST_FUZZ */
#endif /* TEST_FUZZ */
#define EAP_SIM_INIT_LEN 128
#if defined(EAP_AKA_PRIME) || defined(EAP_SERVER_AKA_PRIME)
#endif /* EAP_AKA_PRIME || EAP_SERVER_AKA_PRIME */
void eap_sim_msg_free(struct eap_sim_msg *msg)
{
	if (msg) {
		wpabuf_free(msg->buf);
		os_free(msg);
	}
}
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
