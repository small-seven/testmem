#include "utils/includes.h"
#include "utils/common.h"
#include "crypto/tls.h"
#include "eap_server/eap.h"
#include "eap_server/eap_sim_db.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "radius/radius_server.h"
#include "hostapd.h"
#include "ap_config.h"
#include "sta_info.h"
#include "authsrv.h"
#if defined(EAP_SERVER_SIM) || defined(EAP_SERVER_AKA)
#define EAP_SIM_DB
#endif /* EAP_SERVER_SIM || EAP_SERVER_AKA */
#ifdef EAP_SIM_DB
#ifdef RADIUS_SERVER
#endif /* RADIUS_SERVER */
#endif /* EAP_SIM_DB */
#ifdef RADIUS_SERVER
#ifdef CONFIG_RADIUS_TEST
#endif /* CONFIG_RADIUS_TEST */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#endif /* RADIUS_SERVER */
#ifdef EAP_TLS_FUNCS
#endif /* EAP_TLS_FUNCS */
#ifdef EAP_TLS_FUNCS
#endif /* EAP_TLS_FUNCS */
#ifdef EAP_SIM_DB
#endif /* EAP_SIM_DB */
#ifdef RADIUS_SERVER
#endif /* RADIUS_SERVER */
void authsrv_deinit(struct hostapd_data *hapd)
{
#ifdef RADIUS_SERVER
	radius_server_deinit(hapd->radius_srv);
	hapd->radius_srv = NULL;
#endif /* RADIUS_SERVER */

#ifdef EAP_TLS_FUNCS
	if (hapd->ssl_ctx) {
		tls_deinit(hapd->ssl_ctx);
		hapd->ssl_ctx = NULL;
	}
#endif /* EAP_TLS_FUNCS */

#ifdef EAP_SIM_DB
	if (hapd->eap_sim_db_priv) {
		eap_sim_db_deinit(hapd->eap_sim_db_priv);
		hapd->eap_sim_db_priv = NULL;
	}
#endif /* EAP_SIM_DB */
}
