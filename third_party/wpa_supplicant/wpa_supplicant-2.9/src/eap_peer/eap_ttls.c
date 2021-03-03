#include "includes.h"
#include "common.h"
#include "crypto/ms_funcs.h"
#include "crypto/sha1.h"
#include "crypto/tls.h"
#include "eap_common/chap.h"
#include "eap_common/eap_ttls.h"
#include "mschapv2.h"
#include "eap_i.h"
#include "eap_tls_common.h"
#include "eap_config.h"
#define EAP_TTLS_VERSION 0
#ifdef EAP_TNC
#endif /* EAP_TNC */
static void eap_ttls_deinit(struct eap_sm *sm, void *priv)
{
	struct eap_ttls_data *data = priv;
	if (data == NULL)
		return;
	eap_ttls_phase2_eap_deinit(sm, data);
	os_free(data->phase2_eap_types);
	eap_peer_tls_ssl_deinit(sm, &data->ssl);
	eap_ttls_free_key(data);
	os_free(data->session_id);
	wpabuf_clear_free(data->pending_phase2_req);
	wpabuf_clear_free(data->pending_resp);
	os_free(data);
}
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifdef EAP_TNC
#endif /* EAP_TNC */
#ifdef CONFIG_FIPS
#else /* CONFIG_FIPS */
#ifdef EAP_MSCHAPv2
#else /* EAP_MSCHAPv2 */
#endif /* EAP_MSCHAPv2 */
#endif /* CONFIG_FIPS */
#ifdef CONFIG_FIPS
#else /* CONFIG_FIPS */
#endif /* CONFIG_FIPS */
#ifdef CONFIG_FIPS
#else /* CONFIG_FIPS */
#endif /* CONFIG_FIPS */
#ifdef EAP_TNC
#endif /* EAP_TNC */
#ifdef EAP_MSCHAPv2
#ifdef EAP_TNC
#endif /* EAP_TNC */
#else /* EAP_MSCHAPv2 */
#endif /* EAP_MSCHAPv2 */
#ifdef EAP_TNC
#endif /* EAP_TNC */
#ifdef EAP_TNC
#endif /* EAP_TNC */
#ifdef EAP_TNC
#endif /* EAP_TNC */
#ifdef EAP_TNC
#else /* EAP_TNC */
#endif /* EAP_TNC */
#ifdef EAP_TNC
#endif /* EAP_TNC */
#ifdef EAP_TNC
#endif /* EAP_TNC */
