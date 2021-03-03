#include "utils/includes.h"
#include "utils/common.h"
#include "eap_peer/eap.h"
#include "eap_peer/eap_i.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "pae/ieee802_1x_key.h"
#include "pae/ieee802_1x_kay.h"
#include "wpa_supplicant_i.h"
#include "config.h"
#include "config_ssid.h"
#include "driver_i.h"
#include "wpas_kay.h"
#define DEFAULT_KEY_LEN		16
#define DEFAULT_CKN_LEN		16
int ieee802_1x_alloc_kay_sm(struct wpa_supplicant *wpa_s, struct wpa_ssid *ssid)
{
	struct ieee802_1x_kay_ctx *kay_ctx;
	struct ieee802_1x_kay *res = NULL;
	enum macsec_policy policy;

	ieee802_1x_dealloc_kay_sm(wpa_s);

	if (!ssid || ssid->macsec_policy == 0)
		return 0;

	if (ssid->macsec_policy == 1) {
		if (ssid->macsec_integ_only == 1)
			policy = SHOULD_SECURE;
		else
			policy = SHOULD_ENCRYPT;
	} else {
		policy = DO_NOT_SECURE;
	}

	kay_ctx = os_zalloc(sizeof(*kay_ctx));
	if (!kay_ctx)
		return -1;

	kay_ctx->ctx = wpa_s;

	kay_ctx->macsec_init = wpas_macsec_init;
	kay_ctx->macsec_deinit = wpas_macsec_deinit;
	kay_ctx->macsec_get_capability = wpas_macsec_get_capability;
	kay_ctx->enable_protect_frames = wpas_enable_protect_frames;
	kay_ctx->enable_encrypt = wpas_enable_encrypt;
	kay_ctx->set_replay_protect = wpas_set_replay_protect;
	kay_ctx->set_current_cipher_suite = wpas_set_current_cipher_suite;
	kay_ctx->enable_controlled_port = wpas_enable_controlled_port;
	kay_ctx->get_receive_lowest_pn = wpas_get_receive_lowest_pn;
	kay_ctx->get_transmit_next_pn = wpas_get_transmit_next_pn;
	kay_ctx->set_transmit_next_pn = wpas_set_transmit_next_pn;
	kay_ctx->set_receive_lowest_pn = wpas_set_receive_lowest_pn;
	kay_ctx->create_receive_sc = wpas_create_receive_sc;
	kay_ctx->delete_receive_sc = wpas_delete_receive_sc;
	kay_ctx->create_receive_sa = wpas_create_receive_sa;
	kay_ctx->delete_receive_sa = wpas_delete_receive_sa;
	kay_ctx->enable_receive_sa = wpas_enable_receive_sa;
	kay_ctx->disable_receive_sa = wpas_disable_receive_sa;
	kay_ctx->create_transmit_sc = wpas_create_transmit_sc;
	kay_ctx->delete_transmit_sc = wpas_delete_transmit_sc;
	kay_ctx->create_transmit_sa = wpas_create_transmit_sa;
	kay_ctx->delete_transmit_sa = wpas_delete_transmit_sa;
	kay_ctx->enable_transmit_sa = wpas_enable_transmit_sa;
	kay_ctx->disable_transmit_sa = wpas_disable_transmit_sa;

	res = ieee802_1x_kay_init(kay_ctx, policy, ssid->macsec_replay_protect,
				  ssid->macsec_replay_window, ssid->macsec_port,
				  ssid->mka_priority, wpa_s->ifname,
				  wpa_s->own_addr);
	/* ieee802_1x_kay_init() frees kay_ctx on failure */
	if (res == NULL)
		return -1;

	wpa_s->kay = res;

	return 0;
}
void ieee802_1x_dealloc_kay_sm(struct wpa_supplicant *wpa_s)
{
	if (!wpa_s->kay)
		return;

	ieee802_1x_kay_deinit(wpa_s->kay);
	wpa_s->kay = NULL;
}
void * ieee802_1x_notify_create_actor(struct wpa_supplicant *wpa_s,
				      const u8 *peer_addr)
{
	u8 *sid;
	size_t sid_len = 128;
	struct mka_key_name *ckn;
	struct mka_key *cak;
	struct mka_key *msk;
	void *res = NULL;

	if (!wpa_s->kay || wpa_s->kay->policy == DO_NOT_SECURE)
		return NULL;

	wpa_printf(MSG_DEBUG,
		   "IEEE 802.1X: External notification - Create MKA for "
		   MACSTR, MAC2STR(peer_addr));

	msk = os_zalloc(sizeof(*msk));
	sid = os_zalloc(sid_len);
	ckn = os_zalloc(sizeof(*ckn));
	cak = os_zalloc(sizeof(*cak));
	if (!msk || !sid || !ckn || !cak)
		goto fail;

	msk->len = DEFAULT_KEY_LEN;
	if (ieee802_1x_auth_get_msk(wpa_s, wpa_s->bssid, msk->key, &msk->len)) {
		wpa_printf(MSG_ERROR, "IEEE 802.1X: Could not get MSK");
		goto fail;
	}

	if (ieee802_1x_auth_get_session_id(wpa_s, wpa_s->bssid, sid, &sid_len))
	{
		wpa_printf(MSG_ERROR,
			   "IEEE 802.1X: Could not get EAP Session Id");
		goto fail;
	}

	/* Derive CAK from MSK */
	cak->len = DEFAULT_KEY_LEN;
	if (ieee802_1x_cak_aes_cmac(msk->key, msk->len, wpa_s->own_addr,
				    peer_addr, cak->key, cak->len)) {
		wpa_printf(MSG_ERROR,
			   "IEEE 802.1X: Deriving CAK failed");
		goto fail;
	}
	wpa_hexdump_key(MSG_DEBUG, "Derived CAK", cak->key, cak->len);

	/* Derive CKN from MSK */
	ckn->len = DEFAULT_CKN_LEN;
	if (ieee802_1x_ckn_aes_cmac(msk->key, msk->len, wpa_s->own_addr,
				    peer_addr, sid, sid_len, ckn->name)) {
		wpa_printf(MSG_ERROR,
			   "IEEE 802.1X: Deriving CKN failed");
		goto fail;
	}
	wpa_hexdump(MSG_DEBUG, "Derived CKN", ckn->name, ckn->len);

	res = ieee802_1x_kay_create_mka(wpa_s->kay, ckn, cak, 0,
					EAP_EXCHANGE, FALSE);

fail:
	if (msk) {
		os_memset(msk, 0, sizeof(*msk));
		os_free(msk);
	}
	os_free(sid);
	os_free(ckn);
	if (cak) {
		os_memset(cak, 0, sizeof(*cak));
		os_free(cak);
	}

	return res;
}
void * ieee802_1x_create_preshared_mka(struct wpa_supplicant *wpa_s,
				       struct wpa_ssid *ssid)
{
	struct mka_key *cak;
	struct mka_key_name *ckn;
	void *res = NULL;

	if ((ssid->mka_psk_set & MKA_PSK_SET) != MKA_PSK_SET)
		goto end;

	ckn = os_zalloc(sizeof(*ckn));
	if (!ckn)
		goto end;

	cak = os_zalloc(sizeof(*cak));
	if (!cak)
		goto free_ckn;

	if (ieee802_1x_alloc_kay_sm(wpa_s, ssid) < 0 || !wpa_s->kay)
		goto free_cak;

	if (wpa_s->kay->policy == DO_NOT_SECURE)
		goto dealloc;

	cak->len = ssid->mka_cak_len;
	os_memcpy(cak->key, ssid->mka_cak, cak->len);

	ckn->len = ssid->mka_ckn_len;
	os_memcpy(ckn->name, ssid->mka_ckn, ckn->len);

	res = ieee802_1x_kay_create_mka(wpa_s->kay, ckn, cak, 0, PSK, FALSE);
	if (res)
		goto free_cak;

dealloc:
	/* Failed to create MKA */
	ieee802_1x_dealloc_kay_sm(wpa_s);
free_cak:
	os_free(cak);
free_ckn:
	os_free(ckn);
end:
	return res;
}
