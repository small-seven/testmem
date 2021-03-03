#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/state_machine.h"
#include "utils/bitfield.h"
#include "common/ieee802_11_defs.h"
#include "common/ocv.h"
#include "crypto/aes.h"
#include "crypto/aes_wrap.h"
#include "crypto/aes_siv.h"
#include "crypto/crypto.h"
#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "crypto/sha384.h"
#include "crypto/random.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "drivers/driver.h"
#include "ap_config.h"
#include "ieee802_11.h"
#include "wpa_auth.h"
#include "pmksa_cache_auth.h"
#include "wpa_auth_i.h"
#include "wpa_auth_ie.h"
#define STATE_MACHINE_DATA struct wpa_state_machine
#define STATE_MACHINE_DEBUG_PREFIX "WPA"
#define STATE_MACHINE_ADDR sm->addr
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
static void wpa_auth_pmksa_free_cb(struct rsn_pmksa_cache_entry *entry,
				   void *ctx)
{
	struct wpa_authenticator *wpa_auth = ctx;
	wpa_auth_for_each_sta(wpa_auth, wpa_auth_pmksa_clear_cb, entry);
}
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
void wpa_deinit(struct wpa_authenticator *wpa_auth)
{
	struct wpa_group *group, *prev;

	eloop_cancel_timeout(wpa_rekey_gmk, wpa_auth, NULL);
	eloop_cancel_timeout(wpa_rekey_gtk, wpa_auth, NULL);

	pmksa_cache_auth_deinit(wpa_auth->pmksa);

#ifdef CONFIG_IEEE80211R_AP
	wpa_ft_pmk_cache_deinit(wpa_auth->ft_pmk_cache);
	wpa_auth->ft_pmk_cache = NULL;
	wpa_ft_deinit(wpa_auth);
#endif /* CONFIG_IEEE80211R_AP */

#ifdef CONFIG_P2P
	bitfield_free(wpa_auth->ip_pool);
#endif /* CONFIG_P2P */


	os_free(wpa_auth->wpa_ie);

	group = wpa_auth->group;
	while (group) {
		prev = group;
		group = group->next;
		os_free(prev);
	}

	os_free(wpa_auth);
}
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
static void wpa_free_sta_sm(struct wpa_state_machine *sm)
{
#ifdef CONFIG_P2P
	if (WPA_GET_BE32(sm->ip_addr)) {
		u32 start;
		wpa_printf(MSG_DEBUG, "P2P: Free assigned IP "
			   "address %u.%u.%u.%u from " MACSTR,
			   sm->ip_addr[0], sm->ip_addr[1],
			   sm->ip_addr[2], sm->ip_addr[3],
			   MAC2STR(sm->addr));
		start = WPA_GET_BE32(sm->wpa_auth->conf.ip_addr_start);
		bitfield_clear(sm->wpa_auth->ip_pool,
			       WPA_GET_BE32(sm->ip_addr) - start);
	}
#endif /* CONFIG_P2P */
	if (sm->GUpdateStationKeys) {
		sm->group->GKeyDoneStations--;
		sm->GUpdateStationKeys = FALSE;
	}
#ifdef CONFIG_IEEE80211R_AP
	os_free(sm->assoc_resp_ftie);
	wpabuf_free(sm->ft_pending_req_ies);
#endif /* CONFIG_IEEE80211R_AP */
	os_free(sm->last_rx_eapol_key);
	os_free(sm->wpa_ie);
	wpa_group_put(sm->wpa_auth, sm->group);
#ifdef CONFIG_DPP2
	wpabuf_clear_free(sm->dpp_z);
#endif /* CONFIG_DPP2 */
	bin_clear_free(sm, sizeof(*sm));
}
void wpa_auth_sta_deinit(struct wpa_state_machine *sm)
{
	if (sm == NULL)
		return;

	if (sm->wpa_auth->conf.wpa_strict_rekey && sm->has_GTK) {
		wpa_auth_logger(sm->wpa_auth, sm->addr, LOGGER_DEBUG,
				"strict rekeying - force GTK rekey since STA "
				"is leaving");
		if (eloop_deplete_timeout(0, 500000, wpa_rekey_gtk,
					  sm->wpa_auth, NULL) == -1)
			eloop_register_timeout(0, 500000, wpa_rekey_gtk, sm->wpa_auth,
					       NULL);
	}

	eloop_cancel_timeout(wpa_send_eapol_timeout, sm->wpa_auth, sm);
	sm->pending_1_of_4_timeout = 0;
	eloop_cancel_timeout(wpa_sm_call_step, sm, NULL);
	eloop_cancel_timeout(wpa_rekey_ptk, sm->wpa_auth, sm);
#ifdef CONFIG_IEEE80211R_AP
	wpa_ft_sta_deinit(sm);
#endif /* CONFIG_IEEE80211R_AP */
	if (sm->in_step_loop) {
		/* Must not free state machine while wpa_sm_step() is running.
		 * Freeing will be completed in the end of wpa_sm_step(). */
		wpa_printf(MSG_DEBUG, "WPA: Registering pending STA state "
			   "machine deinit for " MACSTR, MAC2STR(sm->addr));
		sm->pending_deinit = 1;
	} else
		wpa_free_sta_sm(sm);
}
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef CONFIG_FILS
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#endif /* CONFIG_FILS */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
#ifdef CONFIG_SHA384
#else /* CONFIG_SHA384 */
#ifdef CONFIG_SHA256
#else /* CONFIG_SHA256 */
#endif /* CONFIG_SHA256 */
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifndef CONFIG_NO_RC4
#endif /* CONFIG_NO_RC4 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef TEST_FUZZ
#endif /* TEST_FUZZ */
void wpa_remove_ptk(struct wpa_state_machine *sm)
{
	if (sm == NULL)
		return;

	sm->PTK_valid = FALSE;
	os_memset(&sm->PTK, 0, sizeof(sm->PTK));
	if (wpa_auth_set_key(sm->wpa_auth, 0, WPA_ALG_NONE, sm->addr, 0, NULL,
			     0))
		wpa_printf(MSG_DEBUG,
			   "RSN: PTK removal from the driver failed");
	sm->pairwise_set = FALSE;
	eloop_cancel_timeout(wpa_rekey_ptk, sm->wpa_auth, sm);
}
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211R_AP
#else /* CONFIG_IEEE80211R_AP */
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#else /* CONFIG_FILS */
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_SAE
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#endif /* CONFIG_FILS */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211W
#else /* CONFIG_IEEE80211W */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#else /* CONFIG_OCV */
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WNM_AP
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_WNM_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#define RSN_SUITE "%02x-%02x-%02x-%d"
#define RSN_SUITE_ARG(s) \
#ifdef CONFIG_RSN_PREAUTH
#else /* CONFIG_RSN_PREAUTH */
#endif /* CONFIG_RSN_PREAUTH */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
void wpa_auth_pmksa_remove(struct wpa_authenticator *wpa_auth,
			   const u8 *sta_addr)
{
	struct rsn_pmksa_cache_entry *pmksa;

	if (wpa_auth == NULL || wpa_auth->pmksa == NULL)
		return;
	pmksa = pmksa_cache_auth_get(wpa_auth->pmksa, sta_addr, NULL);
	if (pmksa) {
		wpa_printf(MSG_DEBUG, "WPA: Remove PMKSA cache entry for "
			   MACSTR " based on request", MAC2STR(sta_addr));
		pmksa_cache_free_entry(wpa_auth->pmksa, pmksa);
	}
}
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
static void wpa_group_free(struct wpa_authenticator *wpa_auth,
			   struct wpa_group *group)
{
	struct wpa_group *prev = wpa_auth->group;

	wpa_printf(MSG_DEBUG, "WPA: Remove group state machine for VLAN-ID %d",
		   group->vlan_id);

	while (prev) {
		if (prev->next == group) {
			/* This never frees the special first group as needed */
			prev->next = group->next;
			os_free(group);
			break;
		}
		prev = prev->next;
	}

}
int wpa_auth_release_group(struct wpa_authenticator *wpa_auth, int vlan_id)
{
	struct wpa_group *group;
	int ret = 0;

	if (wpa_auth == NULL)
		return 0;

	group = wpa_auth->group;
	while (group) {
		if (group->vlan_id == vlan_id)
			break;
		group = group->next;
	}

	if (group == NULL)
		return -1;

	wpa_printf(MSG_DEBUG,
		   "WPA: Try stopping group state machine for VLAN ID %d",
		   vlan_id);

	if (group->num_setup_iface <= 0) {
		wpa_printf(MSG_ERROR,
			   "WPA: wpa_auth_release_group called more often than wpa_auth_ensure_group for VLAN ID %d, skipping.",
			   vlan_id);
		return -1;
	}
	group->num_setup_iface--;

	if (group->wpa_group_state == WPA_GROUP_FATAL_FAILURE)
		ret = -1;

	if (group->references > 1) {
		wpa_printf(MSG_DEBUG,
			   "WPA: Cannot stop group state machine for VLAN ID %d as references are still hold",
			   vlan_id);
		ret = -2;
	}

	wpa_group_put(wpa_auth, group);

	return ret;
}
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#endif /* CONFIG_FILS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_TESTING_OPTIONS */
