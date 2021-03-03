#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "state_machine.h"
#include "common/eapol_common.h"
#include "eap_common/eap_defs.h"
#include "eap_common/eap_common.h"
#include "eap_server/eap.h"
#include "eapol_auth_sm.h"
#include "eapol_auth_sm_i.h"
#define STATE_MACHINE_DATA struct eapol_state_machine
#define STATE_MACHINE_DEBUG_PREFIX "IEEE 802.1X"
#define STATE_MACHINE_ADDR sm->addr
#define setPortAuthorized() \
#define setPortUnauthorized() \
#define txCannedFail() eapol_auth_tx_canned_eap(sm, 0)
#define txCannedSuccess() eapol_auth_tx_canned_eap(sm, 1)
#define txReq() eapol_auth_tx_req(sm)
#define abortAuth() sm->eapol->cb.abort_auth(sm->eapol->conf.ctx, sm->sta)
#define txKey() sm->eapol->cb.tx_key(sm->eapol->conf.ctx, sm->sta)
#define processKey() do { } while (0)
eapol_auth_alloc(struct eapol_authenticator *eapol, const u8 *addr,
		 int flags, const struct wpabuf *assoc_wps_ie,
		 const struct wpabuf *assoc_p2p_ie, void *sta_ctx,
		 const char *identity, const char *radius_cui)
{
	struct eapol_state_machine *sm;
	struct eap_config eap_conf;

	if (eapol == NULL)
		return NULL;

	sm = os_zalloc(sizeof(*sm));
	if (sm == NULL) {
		wpa_printf(MSG_DEBUG, "IEEE 802.1X state machine allocation "
			   "failed");
		return NULL;
	}
	sm->radius_identifier = -1;
	os_memcpy(sm->addr, addr, ETH_ALEN);
	sm->flags = flags;

	sm->eapol = eapol;
	sm->sta = sta_ctx;

	/* Set default values for state machine constants */
	sm->auth_pae_state = AUTH_PAE_INITIALIZE;
	sm->quietPeriod = AUTH_PAE_DEFAULT_quietPeriod;
	sm->reAuthMax = AUTH_PAE_DEFAULT_reAuthMax;

	sm->be_auth_state = BE_AUTH_INITIALIZE;
	sm->serverTimeout = BE_AUTH_DEFAULT_serverTimeout;

	sm->reauth_timer_state = REAUTH_TIMER_INITIALIZE;
	sm->reAuthPeriod = eapol->conf.eap_reauth_period;
	sm->reAuthEnabled = eapol->conf.eap_reauth_period > 0 ? TRUE : FALSE;

	sm->auth_key_tx_state = AUTH_KEY_TX_NO_KEY_TRANSMIT;

	sm->key_rx_state = KEY_RX_NO_KEY_RECEIVE;

	sm->ctrl_dir_state = CTRL_DIR_IN_OR_BOTH;

	sm->portControl = Auto;

	if (!eapol->conf.wpa &&
	    (eapol->default_wep_key || eapol->conf.individual_wep_key_len > 0))
		sm->keyTxEnabled = TRUE;
	else
		sm->keyTxEnabled = FALSE;
	if (eapol->conf.wpa)
		sm->portValid = FALSE;
	else
		sm->portValid = TRUE;

	os_memset(&eap_conf, 0, sizeof(eap_conf));
	eap_conf.eap_server = eapol->conf.eap_server;
	eap_conf.ssl_ctx = eapol->conf.ssl_ctx;
	eap_conf.msg_ctx = eapol->conf.msg_ctx;
	eap_conf.eap_sim_db_priv = eapol->conf.eap_sim_db_priv;
	eap_conf.pac_opaque_encr_key = eapol->conf.pac_opaque_encr_key;
	eap_conf.eap_fast_a_id = eapol->conf.eap_fast_a_id;
	eap_conf.eap_fast_a_id_len = eapol->conf.eap_fast_a_id_len;
	eap_conf.eap_fast_a_id_info = eapol->conf.eap_fast_a_id_info;
	eap_conf.eap_fast_prov = eapol->conf.eap_fast_prov;
	eap_conf.pac_key_lifetime = eapol->conf.pac_key_lifetime;
	eap_conf.pac_key_refresh_time = eapol->conf.pac_key_refresh_time;
	eap_conf.eap_teap_auth = eapol->conf.eap_teap_auth;
	eap_conf.eap_teap_pac_no_inner = eapol->conf.eap_teap_pac_no_inner;
	eap_conf.eap_sim_aka_result_ind = eapol->conf.eap_sim_aka_result_ind;
	eap_conf.eap_sim_id = eapol->conf.eap_sim_id;
	eap_conf.tnc = eapol->conf.tnc;
	eap_conf.wps = eapol->conf.wps;
	eap_conf.assoc_wps_ie = assoc_wps_ie;
	eap_conf.assoc_p2p_ie = assoc_p2p_ie;
	eap_conf.peer_addr = addr;
	eap_conf.fragment_size = eapol->conf.fragment_size;
	eap_conf.pwd_group = eapol->conf.pwd_group;
	eap_conf.pbc_in_m1 = eapol->conf.pbc_in_m1;
	eap_conf.server_id = eapol->conf.server_id;
	eap_conf.server_id_len = eapol->conf.server_id_len;
	eap_conf.erp = eapol->conf.erp;
	eap_conf.tls_session_lifetime = eapol->conf.tls_session_lifetime;
	eap_conf.tls_flags = eapol->conf.tls_flags;
	sm->eap = eap_server_sm_init(sm, &eapol_cb, &eap_conf);
	if (sm->eap == NULL) {
		eapol_auth_free(sm);
		return NULL;
	}
	sm->eap_if = eap_get_interface(sm->eap);

	eapol_auth_initialize(sm);

	if (identity) {
		sm->identity = (u8 *) os_strdup(identity);
		if (sm->identity)
			sm->identity_len = os_strlen(identity);
	}
	if (radius_cui)
		sm->radius_cui = wpabuf_alloc_copy(radius_cui,
						   os_strlen(radius_cui));

#ifndef CONFIG_NO_RADIUS
	if (radius_gen_session_id((u8 *) &sm->acct_multi_session_id,
				  sizeof(sm->acct_multi_session_id)) < 0) {
		eapol_auth_free(sm);
		return NULL;
	}
#endif /* CONFIG_NO_RADIUS */

	return sm;
}
void eapol_auth_free(struct eapol_state_machine *sm)
{
	if (sm == NULL)
		return;

	eloop_cancel_timeout(eapol_port_timers_tick, NULL, sm);
	eloop_cancel_timeout(eapol_sm_step_cb, sm, NULL);
	if (sm->eap)
		eap_server_sm_deinit(sm->eap);

	wpabuf_free(sm->radius_cui);
	os_free(sm->identity);
	os_free(sm);
}
static void eapol_auth_conf_free(struct eapol_auth_config *conf)
{
	os_free(conf->eap_req_id_text);
	conf->eap_req_id_text = NULL;
	os_free(conf->pac_opaque_encr_key);
	conf->pac_opaque_encr_key = NULL;
	os_free(conf->eap_fast_a_id);
	conf->eap_fast_a_id = NULL;
	os_free(conf->eap_fast_a_id_info);
	conf->eap_fast_a_id_info = NULL;
	os_free(conf->erp_domain);
	conf->erp_domain = NULL;
}
void eapol_auth_deinit(struct eapol_authenticator *eapol)
{
	if (eapol == NULL)
		return;

	eapol_auth_conf_free(&eapol->conf);
	os_free(eapol->default_wep_key);
	os_free(eapol);
}
