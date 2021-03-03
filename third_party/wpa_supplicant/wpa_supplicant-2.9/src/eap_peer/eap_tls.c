#include "includes.h"
#include "common.h"
#include "crypto/tls.h"
#include "eap_i.h"
#include "eap_tls_common.h"
#include "eap_config.h"
#ifdef EAP_UNAUTH_TLS
#endif /* EAP_UNAUTH_TLS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
static void eap_tls_deinit(struct eap_sm *sm, void *priv)
{
	struct eap_tls_data *data = priv;
	if (data == NULL)
		return;
	eap_peer_tls_ssl_deinit(sm, &data->ssl);
	eap_tls_free_key(data);
	os_free(data->session_id);
	wpabuf_free(data->pending_resp);
	os_free(data);
}
#ifdef EAP_UNAUTH_TLS
#endif /* EAP_UNAUTH_TLS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
