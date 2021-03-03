#include "utils/includes.h"
#include "utils/common.h"
#include "pae/ieee802_1x_key.h"
#include "pae/ieee802_1x_kay.h"
#include "hostapd.h"
#include "sta_info.h"
#include "wpa_auth_kay.h"
#include "ieee802_1x.h"
#define DEFAULT_KEY_LEN		16
#define DEFAULT_CKN_LEN		16
int ieee802_1x_alloc_kay_sm_hapd(struct hostapd_data *hapd,
				 struct sta_info *sta)
{
	struct ieee802_1x_kay_ctx *kay_ctx;
	struct ieee802_1x_kay *res = NULL;
	enum macsec_policy policy;

	ieee802_1x_dealloc_kay_sm_hapd(hapd);

	if (!hapd->conf || hapd->conf->macsec_policy == 0)
		return 0;

	if (hapd->conf->macsec_policy == 1) {
		if (hapd->conf->macsec_integ_only == 1)
			policy = SHOULD_SECURE;
		else
			policy = SHOULD_ENCRYPT;
	} else {
		policy = DO_NOT_SECURE;
	}

	wpa_printf(MSG_DEBUG, "%s: if_name=%s", __func__, hapd->conf->iface);
	kay_ctx = os_zalloc(sizeof(*kay_ctx));
	if (!kay_ctx)
		return -1;

	kay_ctx->ctx = hapd;

	kay_ctx->macsec_init = hapd_macsec_init;
	kay_ctx->macsec_deinit = hapd_macsec_deinit;
	kay_ctx->macsec_get_capability = hapd_macsec_get_capability;
	kay_ctx->enable_protect_frames = hapd_enable_protect_frames;
	kay_ctx->enable_encrypt = hapd_enable_encrypt;
	kay_ctx->set_replay_protect = hapd_set_replay_protect;
	kay_ctx->set_current_cipher_suite = hapd_set_current_cipher_suite;
	kay_ctx->enable_controlled_port = hapd_enable_controlled_port;
	kay_ctx->get_receive_lowest_pn = hapd_get_receive_lowest_pn;
	kay_ctx->get_transmit_next_pn = hapd_get_transmit_next_pn;
	kay_ctx->set_transmit_next_pn = hapd_set_transmit_next_pn;
	kay_ctx->create_receive_sc = hapd_create_receive_sc;
	kay_ctx->delete_receive_sc = hapd_delete_receive_sc;
	kay_ctx->create_receive_sa = hapd_create_receive_sa;
	kay_ctx->delete_receive_sa = hapd_delete_receive_sa;
	kay_ctx->enable_receive_sa = hapd_enable_receive_sa;
	kay_ctx->disable_receive_sa = hapd_disable_receive_sa;
	kay_ctx->create_transmit_sc = hapd_create_transmit_sc;
	kay_ctx->delete_transmit_sc = hapd_delete_transmit_sc;
	kay_ctx->create_transmit_sa = hapd_create_transmit_sa;
	kay_ctx->delete_transmit_sa = hapd_delete_transmit_sa;
	kay_ctx->enable_transmit_sa = hapd_enable_transmit_sa;
	kay_ctx->disable_transmit_sa = hapd_disable_transmit_sa;

	res = ieee802_1x_kay_init(kay_ctx, policy,
				  hapd->conf->macsec_replay_protect,
				  hapd->conf->macsec_replay_window,
				  hapd->conf->macsec_port,
				  hapd->conf->mka_priority, hapd->conf->iface,
				  hapd->own_addr);
	/* ieee802_1x_kay_init() frees kay_ctx on failure */
	if (!res)
		return -1;

	hapd->kay = res;

	return 0;
}
void ieee802_1x_dealloc_kay_sm_hapd(struct hostapd_data *hapd)
{
	if (!hapd->kay)
		return;

	ieee802_1x_kay_deinit(hapd->kay);
	hapd->kay = NULL;
}
void * ieee802_1x_notify_create_actor_hapd(struct hostapd_data *hapd,
					   struct sta_info *sta)
{
	u8 *sid;
	size_t sid_len = 128;
	struct mka_key_name *ckn;
	struct mka_key *cak;
	struct mka_key *msk;
	void *res = NULL;

	if (!hapd->kay || hapd->kay->policy == DO_NOT_SECURE)
		return NULL;

	wpa_printf(MSG_DEBUG,
		   "IEEE 802.1X: External notification - Create MKA for "
		   MACSTR, MAC2STR(sta->addr));

	msk = os_zalloc(sizeof(*msk));
	sid = os_zalloc(sid_len);
	ckn = os_zalloc(sizeof(*ckn));
	cak = os_zalloc(sizeof(*cak));
	if (!msk || !sid || !ckn || !cak)
		goto fail;

	msk->len = DEFAULT_KEY_LEN;
	if (ieee802_1x_auth_get_msk(hapd, sta, msk->key, &msk->len)) {
		wpa_printf(MSG_ERROR, "IEEE 802.1X: Could not get MSK");
		goto fail;
	}

	if (ieee802_1x_auth_get_session_id(hapd, sta, sid, &sid_len))
	{
		wpa_printf(MSG_ERROR,
			   "IEEE 802.1X: Could not get EAP Session Id");
		goto fail;
	}

	wpa_hexdump(MSG_DEBUG, "own_addr", hapd->own_addr, ETH_ALEN);
	wpa_hexdump(MSG_DEBUG, "sta_addr", sta->addr, ETH_ALEN);

	/* Derive CAK from MSK */
	cak->len = DEFAULT_KEY_LEN;
	if (ieee802_1x_cak_aes_cmac(msk->key, msk->len, hapd->own_addr,
				    sta->addr, cak->key, cak->len)) {
		wpa_printf(MSG_ERROR, "IEEE 802.1X: Deriving CAK failed");
		goto fail;
	}
	wpa_hexdump_key(MSG_DEBUG, "Derived CAK", cak->key, cak->len);

	/* Derive CKN from MSK */
	ckn->len = DEFAULT_CKN_LEN;
	if (ieee802_1x_ckn_aes_cmac(msk->key, msk->len, hapd->own_addr,
				    sta->addr, sid, sid_len, ckn->name)) {
		wpa_printf(MSG_ERROR, "IEEE 802.1X: Deriving CKN failed");
		goto fail;
	}
	wpa_hexdump(MSG_DEBUG, "Derived CKN", ckn->name, ckn->len);

	res = ieee802_1x_kay_create_mka(hapd->kay, ckn, cak, 0, EAP_EXCHANGE,
					TRUE);

fail:
	bin_clear_free(msk, sizeof(*msk));
	os_free(sid);
	os_free(ckn);
	bin_clear_free(cak, sizeof(*cak));

	return res;
}
void * ieee802_1x_create_preshared_mka_hapd(struct hostapd_data *hapd,
					    struct sta_info *sta)
{
	struct mka_key *cak;
	struct mka_key_name *ckn;
	void *res = NULL;

	if ((hapd->conf->mka_psk_set & MKA_PSK_SET) != MKA_PSK_SET)
		goto end;

	ckn = os_zalloc(sizeof(*ckn));
	if (!ckn)
		goto end;

	cak = os_zalloc(sizeof(*cak));
	if (!cak)
		goto free_ckn;

	if (ieee802_1x_alloc_kay_sm_hapd(hapd, sta) < 0 || !hapd->kay)
		goto free_cak;

	if (hapd->kay->policy == DO_NOT_SECURE)
		goto dealloc;

	cak->len = hapd->conf->mka_cak_len;
	os_memcpy(cak->key, hapd->conf->mka_cak, cak->len);

	ckn->len = hapd->conf->mka_ckn_len;;
	os_memcpy(ckn->name, hapd->conf->mka_ckn, ckn->len);

	res = ieee802_1x_kay_create_mka(hapd->kay, ckn, cak, 0, PSK, TRUE);
	if (res)
		goto free_cak;

dealloc:
	/* Failed to create MKA */
	ieee802_1x_dealloc_kay_sm_hapd(hapd);
free_cak:
	os_free(cak);
free_ckn:
	os_free(ckn);
end:
	return res;
}
