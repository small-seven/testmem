#include "includes.h"
#include "common.h"
#include "crypto/aes.h"
#include "crypto/aes_wrap.h"
#include "crypto/crypto.h"
#include "crypto/random.h"
#include "crypto/aes_siv.h"
#include "crypto/sha256.h"
#include "crypto/sha384.h"
#include "crypto/sha512.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/ocv.h"
#include "eap_common/eap_defs.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "drivers/driver.h"
#include "wpa.h"
#include "eloop.h"
#include "preauth.h"
#include "pmksa_cache.h"
#include "wpa_i.h"
#include "wpa_ie.h"
#ifdef CONFIG_FILS
#else /* CONFIG_FILS */
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#else /* CONFIG_IEEE80211W */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_NO_RC4
#else /* CONFIG_NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef CONFIG_NO_RC4
#else /* CONFIG_NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_IEEE80211W)
#endif /* CONFIG_IEEE80211R || CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_CTRL_IFACE
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#define RSN_SUITE "%02x-%02x-%02x-%d"
#define RSN_SUITE_ARG(s) \
#endif /* CONFIG_CTRL_IFACE */
static void wpa_sm_pmksa_free_cb(struct rsn_pmksa_cache_entry *entry,
				 void *ctx, enum pmksa_free_reason reason)
{
	struct wpa_sm *sm = ctx;
	int deauth = 0;

	wpa_dbg(sm->ctx->msg_ctx, MSG_DEBUG, "RSN: PMKSA cache entry free_cb: "
		MACSTR " reason=%d", MAC2STR(entry->aa), reason);

	if (sm->cur_pmksa == entry) {
		wpa_dbg(sm->ctx->msg_ctx, MSG_DEBUG,
			"RSN: %s current PMKSA entry",
			reason == PMKSA_REPLACE ? "replaced" : "removed");
		pmksa_cache_clear_current(sm);

		/*
		 * If an entry is simply being replaced, there's no need to
		 * deauthenticate because it will be immediately re-added.
		 * This happens when EAP authentication is completed again
		 * (reauth or failed PMKSA caching attempt).
		 */
		if (reason != PMKSA_REPLACE)
			deauth = 1;
	}

	if (reason == PMKSA_EXPIRE &&
	    (sm->pmk_len == entry->pmk_len &&
	     os_memcmp(sm->pmk, entry->pmk, sm->pmk_len) == 0)) {
		wpa_dbg(sm->ctx->msg_ctx, MSG_DEBUG,
			"RSN: deauthenticating due to expired PMK");
		pmksa_cache_clear_current(sm);
		deauth = 1;
	}

	if (deauth) {
		sm->pmk_len = 0;
		os_memset(sm->pmk, 0, sizeof(sm->pmk));
		wpa_sm_deauthenticate(sm, WLAN_REASON_UNSPECIFIED);
	}
}
void wpa_sm_deinit(struct wpa_sm *sm)
{
	if (sm == NULL)
		return;
	pmksa_cache_deinit(sm->pmksa);
	eloop_cancel_timeout(wpa_sm_start_preauth, sm, NULL);
	eloop_cancel_timeout(wpa_sm_rekey_ptk, sm, NULL);
	os_free(sm->assoc_wpa_ie);
	os_free(sm->ap_wpa_ie);
	os_free(sm->ap_rsn_ie);
	wpa_sm_drop_sa(sm);
	os_free(sm->ctx);
#ifdef CONFIG_IEEE80211R
	os_free(sm->assoc_resp_ies);
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_TESTING_OPTIONS
	wpabuf_free(sm->test_assoc_ie);
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_FILS_SK_PFS
	crypto_ecdh_deinit(sm->fils_ecdh);
#endif /* CONFIG_FILS_SK_PFS */
#ifdef CONFIG_FILS
	wpabuf_free(sm->fils_ft_ies);
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
	crypto_ecdh_deinit(sm->owe_ecdh);
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP2
	wpabuf_clear_free(sm->dpp_z);
#endif /* CONFIG_DPP2 */
	os_free(sm);
}
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_WNM
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_WNM */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_FILS
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#endif /* CONFIG_FILS */
#ifdef CONFIG_FILS
#else /* CONFIG_FILS */
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
