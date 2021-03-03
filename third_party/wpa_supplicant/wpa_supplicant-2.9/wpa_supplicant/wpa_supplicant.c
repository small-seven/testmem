#include "includes.h"
#ifdef CONFIG_MATCH_IFACE
#include <net/if.h>
#include <fnmatch.h>
#endif /* CONFIG_MATCH_IFACE */
#include "common.h"
#include "crypto/random.h"
#include "crypto/sha1.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "eap_peer/eap.h"
#include "eap_peer/eap_proxy.h"
#include "eap_server/eap_methods.h"
#include "rsn_supp/wpa.h"
#include "eloop.h"
#include "config.h"
#include "utils/ext_password.h"
#include "l2_packet/l2_packet.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "ctrl_iface.h"
#include "pcsc_funcs.h"
#include "common/version.h"
#include "rsn_supp/preauth.h"
#include "rsn_supp/pmksa_cache.h"
#include "common/wpa_ctrl.h"
#include "common/ieee802_11_common.h"
#include "common/ieee802_11_defs.h"
#include "common/hw_features_common.h"
#include "common/gas_server.h"
#include "common/dpp.h"
#include "p2p/p2p.h"
#include "fst/fst.h"
#include "blacklist.h"
#include "wpas_glue.h"
#include "wps_supplicant.h"
#include "ibss_rsn.h"
#include "sme.h"
#include "gas_query.h"
#include "ap.h"
#include "p2p_supplicant.h"
#include "wifi_display.h"
#include "notify.h"
#include "bgscan.h"
#include "autoscan.h"
#include "bss.h"
#include "scan.h"
#include "offchannel.h"
#include "hs20_supplicant.h"
#include "wnm_sta.h"
#include "wpas_kay.h"
#include "mesh.h"
#include "dpp_supplicant.h"
#ifdef CONFIG_MESH
#include "ap/ap_config.h"
#include "ap/hostapd.h"
#endif /* CONFIG_MESH */
#ifdef EAP_TLS_OPENSSL
#endif /* EAP_TLS_OPENSSL */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#if defined(CONFIG_FILS) && defined(IEEE8021X_EAPOL)
#endif /* CONFIG_FILS && IEEE8021X_EAPOL */
#ifdef IEEE8021X_EAPOL
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
void free_hw_features(struct wpa_supplicant *wpa_s)
{
	int i;
	if (wpa_s->hw.modes == NULL)
		return;

	for (i = 0; i < wpa_s->hw.num_modes; i++) {
		os_free(wpa_s->hw.modes[i].channels);
		os_free(wpa_s->hw.modes[i].rates);
	}

	os_free(wpa_s->hw.modes);
	wpa_s->hw.modes = NULL;
}
void free_bss_tmp_disallowed(struct wpa_supplicant *wpa_s)
{
	struct wpa_bss_tmp_disallowed *bss, *prev;

	dl_list_for_each_safe(bss, prev, &wpa_s->bss_tmp_disallowed,
			      struct wpa_bss_tmp_disallowed, list) {
		eloop_cancel_timeout(wpa_bss_tmp_disallow_timeout, wpa_s, bss);
		dl_list_del(&bss->list);
		os_free(bss);
	}
}
static void wpa_supplicant_cleanup(struct wpa_supplicant *wpa_s)
{
	int i;

	bgscan_deinit(wpa_s);
	autoscan_deinit(wpa_s);
	scard_deinit(wpa_s->scard);
	wpa_s->scard = NULL;
	wpa_sm_set_scard_ctx(wpa_s->wpa, NULL);
	eapol_sm_register_scard_ctx(wpa_s->eapol, NULL);
	l2_packet_deinit(wpa_s->l2);
	wpa_s->l2 = NULL;
	if (wpa_s->l2_br) {
		l2_packet_deinit(wpa_s->l2_br);
		wpa_s->l2_br = NULL;
	}
#ifdef CONFIG_TESTING_OPTIONS
	l2_packet_deinit(wpa_s->l2_test);
	wpa_s->l2_test = NULL;
	os_free(wpa_s->get_pref_freq_list_override);
	wpa_s->get_pref_freq_list_override = NULL;
	wpabuf_free(wpa_s->last_assoc_req_wpa_ie);
	wpa_s->last_assoc_req_wpa_ie = NULL;
#endif /* CONFIG_TESTING_OPTIONS */

	if (wpa_s->conf != NULL) {
		struct wpa_ssid *ssid;
		for (ssid = wpa_s->conf->ssid; ssid; ssid = ssid->next)
			wpas_notify_network_removed(wpa_s, ssid);
	}

	os_free(wpa_s->confname);
	wpa_s->confname = NULL;

	os_free(wpa_s->confanother);
	wpa_s->confanother = NULL;

	os_free(wpa_s->last_con_fail_realm);
	wpa_s->last_con_fail_realm = NULL;
	wpa_s->last_con_fail_realm_len = 0;

	wpa_sm_set_eapol(wpa_s->wpa, NULL);
	eapol_sm_deinit(wpa_s->eapol);
	wpa_s->eapol = NULL;

	rsn_preauth_deinit(wpa_s->wpa);

#ifdef CONFIG_TDLS
	wpa_tdls_deinit(wpa_s->wpa);
#endif /* CONFIG_TDLS */

	wmm_ac_clear_saved_tspecs(wpa_s);
	pmksa_candidate_free(wpa_s->wpa);
	wpa_sm_deinit(wpa_s->wpa);
	wpa_s->wpa = NULL;
	wpa_blacklist_clear(wpa_s);

	wpa_bss_deinit(wpa_s);

	wpa_supplicant_cancel_delayed_sched_scan(wpa_s);
	wpa_supplicant_cancel_scan(wpa_s);
	wpa_supplicant_cancel_auth_timeout(wpa_s);
	eloop_cancel_timeout(wpa_supplicant_stop_countermeasures, wpa_s, NULL);
#ifdef CONFIG_DELAYED_MIC_ERROR_REPORT
	eloop_cancel_timeout(wpa_supplicant_delayed_mic_error_report,
			     wpa_s, NULL);
#endif /* CONFIG_DELAYED_MIC_ERROR_REPORT */

	eloop_cancel_timeout(wpas_network_reenabled, wpa_s, NULL);

	wpas_wps_deinit(wpa_s);

	wpabuf_free(wpa_s->pending_eapol_rx);
	wpa_s->pending_eapol_rx = NULL;

#ifdef CONFIG_IBSS_RSN
	ibss_rsn_deinit(wpa_s->ibss_rsn);
	wpa_s->ibss_rsn = NULL;
#endif /* CONFIG_IBSS_RSN */

	sme_deinit(wpa_s);

#ifdef CONFIG_AP
	wpa_supplicant_ap_deinit(wpa_s);
#endif /* CONFIG_AP */

	wpas_p2p_deinit(wpa_s);

#ifdef CONFIG_OFFCHANNEL
	offchannel_deinit(wpa_s);
#endif /* CONFIG_OFFCHANNEL */

	wpa_supplicant_cancel_sched_scan(wpa_s);

	os_free(wpa_s->next_scan_freqs);
	wpa_s->next_scan_freqs = NULL;

	os_free(wpa_s->manual_scan_freqs);
	wpa_s->manual_scan_freqs = NULL;
	os_free(wpa_s->select_network_scan_freqs);
	wpa_s->select_network_scan_freqs = NULL;

	os_free(wpa_s->manual_sched_scan_freqs);
	wpa_s->manual_sched_scan_freqs = NULL;

	wpas_mac_addr_rand_scan_clear(wpa_s, MAC_ADDR_RAND_ALL);

	/*
	 * Need to remove any pending gas-query radio work before the
	 * gas_query_deinit() call because gas_query::work has not yet been set
	 * for works that have not been started. gas_query_free() will be unable
	 * to cancel such pending radio works and once the pending gas-query
	 * radio work eventually gets removed, the deinit notification call to
	 * gas_query_start_cb() would result in dereferencing freed memory.
	 */
	if (wpa_s->radio)
		radio_remove_works(wpa_s, "gas-query", 0);
	gas_query_deinit(wpa_s->gas);
	wpa_s->gas = NULL;
	gas_server_deinit(wpa_s->gas_server);
	wpa_s->gas_server = NULL;

	free_hw_features(wpa_s);

	ieee802_1x_dealloc_kay_sm(wpa_s);

	os_free(wpa_s->bssid_filter);
	wpa_s->bssid_filter = NULL;

	os_free(wpa_s->disallow_aps_bssid);
	wpa_s->disallow_aps_bssid = NULL;
	os_free(wpa_s->disallow_aps_ssid);
	wpa_s->disallow_aps_ssid = NULL;

	wnm_bss_keep_alive_deinit(wpa_s);
#ifdef CONFIG_WNM
	wnm_deallocate_memory(wpa_s);
#endif /* CONFIG_WNM */

	ext_password_deinit(wpa_s->ext_pw);
	wpa_s->ext_pw = NULL;

	wpabuf_free(wpa_s->last_gas_resp);
	wpa_s->last_gas_resp = NULL;
	wpabuf_free(wpa_s->prev_gas_resp);
	wpa_s->prev_gas_resp = NULL;

	os_free(wpa_s->last_scan_res);
	wpa_s->last_scan_res = NULL;

#ifdef CONFIG_HS20
	if (wpa_s->drv_priv)
		wpa_drv_configure_frame_filters(wpa_s, 0);
	hs20_deinit(wpa_s);
#endif /* CONFIG_HS20 */

	for (i = 0; i < NUM_VENDOR_ELEM_FRAMES; i++) {
		wpabuf_free(wpa_s->vendor_elem[i]);
		wpa_s->vendor_elem[i] = NULL;
	}

	wmm_ac_notify_disassoc(wpa_s);

	wpa_s->sched_scan_plans_num = 0;
	os_free(wpa_s->sched_scan_plans);
	wpa_s->sched_scan_plans = NULL;

#ifdef CONFIG_MBO
	wpa_s->non_pref_chan_num = 0;
	os_free(wpa_s->non_pref_chan);
	wpa_s->non_pref_chan = NULL;
#endif /* CONFIG_MBO */

	free_bss_tmp_disallowed(wpa_s);

	wpabuf_free(wpa_s->lci);
	wpa_s->lci = NULL;
	wpas_clear_beacon_rep_data(wpa_s);

#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#ifdef CONFIG_MESH
	{
		struct external_pmksa_cache *entry;

		while ((entry = dl_list_last(&wpa_s->mesh_external_pmksa_cache,
					     struct external_pmksa_cache,
					     list)) != NULL) {
			dl_list_del(&entry->list);
			os_free(entry->pmksa_cache);
			os_free(entry);
		}
	}
#endif /* CONFIG_MESH */
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */

	wpas_flush_fils_hlp_req(wpa_s);

	wpabuf_free(wpa_s->ric_ies);
	wpa_s->ric_ies = NULL;

#ifdef CONFIG_DPP
	wpas_dpp_deinit(wpa_s);
	dpp_global_deinit(wpa_s->dpp);
	wpa_s->dpp = NULL;
#endif /* CONFIG_DPP */
}
#ifdef CONFIG_IEEE80211W
#else /* CONFIG_IEEE80211W */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_BGSCAN
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#endif /* CONFIG_BGSCAN */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#if defined(CONFIG_CTRL_IFACE) || !defined(CONFIG_NO_STDOUT_DEBUG)
#endif /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#ifndef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#if defined(CONFIG_FILS) && defined(IEEE8021X_EAPOL)
#endif /* CONFIG_FILS && IEEE8021X_EAPOL */
#ifndef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_BGSCAN
#endif /* CONFIG_BGSCAN */
#ifdef CONFIG_WPS
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#endif /* CONFIG_WPS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_NO_WPA
#else /* CONFIG_NO_WPA */
#endif /* CONFIG_NO_WPA */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifndef CONFIG_NO_PBKDF2
#endif /* CONFIG_NO_PBKDF2 */
#ifdef CONFIG_EXT_PASSWORD
#ifndef CONFIG_NO_PBKDF2
#endif /* CONFIG_NO_PBKDF2 */
#endif /* CONFIG_EXT_PASSWORD */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
void wpas_connect_work_free(struct wpa_connect_work *cwork)
{
	if (cwork == NULL)
		return;
	os_free(cwork);
}
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_IBSS_RSN
#else /* CONFIG_IBSS_RSN */
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_MESH
#else /* CONFIG_MESH */
#endif /* CONFIG_MESH */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_FILS
#ifdef CONFIG_FILS_SK_PFS
#else /* CONFIG_FILS_SK_PFS */
#endif /* CONFIG_FILS_SK_PFS */
#endif /* CONFIG_FILS */
#ifdef CONFIG_MBO
#endif
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef IEEE8021X_EAPOL
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#endif /* CONFIG_IEEE80211R */
#if defined(CONFIG_FILS) && defined(IEEE8021X_EAPOL)
#endif /* CONFIG_FILS && IEEE8021X_EAPOL */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_IEEE80211W
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
int wpa_supplicant_remove_network(struct wpa_supplicant *wpa_s, int id)
{
	struct wpa_ssid *ssid;
	int was_disabled;

	ssid = wpa_config_get_network(wpa_s->conf, id);
	if (!ssid)
		return -1;
	wpas_notify_network_removed(wpa_s, ssid);

	if (wpa_s->last_ssid == ssid)
		wpa_s->last_ssid = NULL;

	if (ssid == wpa_s->current_ssid || !wpa_s->current_ssid) {
#ifdef CONFIG_SME
		wpa_s->sme.prev_bssid_set = 0;
#endif /* CONFIG_SME */
		/*
		 * Invalidate the EAP session cache if the current or
		 * previously used network is removed.
		 */
		eapol_sm_invalidate_cached_session(wpa_s->eapol);
	}

	if (ssid == wpa_s->current_ssid) {
		wpa_sm_set_config(wpa_s->wpa, NULL);
		eapol_sm_notify_config(wpa_s->eapol, NULL, NULL);

		if (wpa_s->wpa_state >= WPA_AUTHENTICATING)
			wpa_s->own_disconnect_req = 1;
		wpa_supplicant_deauthenticate(wpa_s,
					      WLAN_REASON_DEAUTH_LEAVING);
	}

	was_disabled = ssid->disabled;

	if (wpa_config_remove_network(wpa_s->conf, id) < 0)
		return -2;

	if (!was_disabled && wpa_s->sched_scanning) {
		wpa_printf(MSG_DEBUG,
			   "Stop ongoing sched_scan to remove network from filters");
		wpa_supplicant_cancel_sched_scan(wpa_s);
		wpa_supplicant_req_scan(wpa_s, 0, 0);
	}

	return 0;
}
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifndef ANDROID
#endif /* ANDROID */
wpa_supplicant_alloc(struct wpa_supplicant *parent)
{
	struct wpa_supplicant *wpa_s;

	wpa_s = os_zalloc(sizeof(*wpa_s));
	if (wpa_s == NULL)
		return NULL;
	wpa_s->scan_req = INITIAL_SCAN_REQ;
	wpa_s->scan_interval = 5;
	wpa_s->new_connection = 1;
	wpa_s->parent = parent ? parent : wpa_s;
	wpa_s->p2pdev = wpa_s->parent;
	wpa_s->sched_scanning = 0;

	dl_list_init(&wpa_s->bss_tmp_disallowed);
	dl_list_init(&wpa_s->fils_hlp_req);

	return wpa_s;
}
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#define OVERRIDE_MCS(i)							\
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef PCSC_FUNCS
#endif /* PCSC_FUNCS */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
static void radio_work_free(struct wpa_radio_work *work)
{
	if (work->wpa_s->scan_work == work) {
		/* This should not really happen. */
		wpa_dbg(work->wpa_s, MSG_INFO, "Freeing radio work '%s'@%p (started=%d) that is marked as scan_work",
			work->type, work, work->started);
		work->wpa_s->scan_work = NULL;
	}

#ifdef CONFIG_P2P
	if (work->wpa_s->p2p_scan_work == work) {
		/* This should not really happen. */
		wpa_dbg(work->wpa_s, MSG_INFO, "Freeing radio work '%s'@%p (started=%d) that is marked as p2p_scan_work",
			work->type, work, work->started);
		work->wpa_s->p2p_scan_work = NULL;
	}
#endif /* CONFIG_P2P */

	if (work->started) {
		work->wpa_s->radio->num_active_works--;
		wpa_dbg(work->wpa_s, MSG_DEBUG,
			"radio_work_free('%s'@%p): num_active_works --> %u",
			work->type, work,
			work->wpa_s->radio->num_active_works);
	}

	dl_list_del(&work->list);
	os_free(work);
}
void radio_remove_works(struct wpa_supplicant *wpa_s,
			const char *type, int remove_all)
{
	struct wpa_radio_work *work, *tmp;
	struct wpa_radio *radio = wpa_s->radio;

	dl_list_for_each_safe(work, tmp, &radio->work, struct wpa_radio_work,
			      list) {
		if (type && os_strcmp(type, work->type) != 0)
			continue;

		/* skip other ifaces' works */
		if (!remove_all && work->wpa_s != wpa_s)
			continue;

		wpa_dbg(wpa_s, MSG_DEBUG, "Remove radio work '%s'@%p%s",
			work->type, work, work->started ? " (started)" : "");
		work->cb(work, 1);
		radio_work_free(work);
	}

	/* in case we removed the started work */
	radio_work_check_next(wpa_s);
}
void radio_remove_pending_work(struct wpa_supplicant *wpa_s, void *ctx)
{
	struct wpa_radio_work *work;
	struct wpa_radio *radio = wpa_s->radio;

	dl_list_for_each(work, &radio->work, struct wpa_radio_work, list) {
		if (work->ctx != ctx)
			continue;
		wpa_dbg(wpa_s, MSG_DEBUG, "Free pending radio work '%s'@%p%s",
			work->type, work, work->started ? " (started)" : "");
		radio_work_free(work);
		break;
	}
}
static void radio_remove_interface(struct wpa_supplicant *wpa_s)
{
	struct wpa_radio *radio = wpa_s->radio;

	if (!radio)
		return;

	wpa_printf(MSG_DEBUG, "Remove interface %s from radio %s",
		   wpa_s->ifname, radio->name);
	dl_list_del(&wpa_s->radio_list);
	radio_remove_works(wpa_s, NULL, 0);
	wpa_s->radio = NULL;
	if (!dl_list_empty(&radio->ifaces))
		return; /* Interfaces remain for this radio */

	wpa_printf(MSG_DEBUG, "Remove radio %s", radio->name);
	eloop_cancel_timeout(radio_start_next_work, radio, NULL);
	os_free(radio);
}
#ifdef CONFIG_GAS_SERVER
#endif /* CONFIG_GAS_SERVER */
#ifdef CONFIG_BACKEND_FILE
#else /* CONFIG_BACKEND_FILE */
#endif /* CONFIG_BACKEND_FILE */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_GAS_SERVER
#endif /* CONFIG_GAS_SERVER */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
static void wpa_supplicant_deinit_iface(struct wpa_supplicant *wpa_s,
					int notify, int terminate)
{
	struct wpa_global *global = wpa_s->global;
	struct wpa_supplicant *iface, *prev;

	if (wpa_s == wpa_s->parent)
		wpas_p2p_group_remove(wpa_s, "*");

	iface = global->ifaces;
	while (iface) {
		if (iface->p2pdev == wpa_s)
			iface->p2pdev = iface->parent;
		if (iface == wpa_s || iface->parent != wpa_s) {
			iface = iface->next;
			continue;
		}
		wpa_printf(MSG_DEBUG,
			   "Remove remaining child interface %s from parent %s",
			   iface->ifname, wpa_s->ifname);
		prev = iface;
		iface = iface->next;
		wpa_supplicant_remove_iface(global, prev, terminate);
	}

	wpa_s->disconnected = 1;
	if (wpa_s->drv_priv) {
		wpa_supplicant_deauthenticate(wpa_s,
					      WLAN_REASON_DEAUTH_LEAVING);

		wpa_drv_set_countermeasures(wpa_s, 0);
		wpa_clear_keys(wpa_s, NULL);
	}

	wpa_supplicant_cleanup(wpa_s);
	wpas_p2p_deinit_iface(wpa_s);

	wpas_ctrl_radio_work_flush(wpa_s);
	radio_remove_interface(wpa_s);

#ifdef CONFIG_FST
	if (wpa_s->fst) {
		fst_detach(wpa_s->fst);
		wpa_s->fst = NULL;
	}
	if (wpa_s->received_mb_ies) {
		wpabuf_free(wpa_s->received_mb_ies);
		wpa_s->received_mb_ies = NULL;
	}
#endif /* CONFIG_FST */

	if (wpa_s->drv_priv)
		wpa_drv_deinit(wpa_s);

	if (notify)
		wpas_notify_iface_removed(wpa_s);

	if (terminate)
		wpa_msg(wpa_s, MSG_INFO, WPA_EVENT_TERMINATING);

	if (wpa_s->ctrl_iface) {
		wpa_supplicant_ctrl_iface_deinit(wpa_s->ctrl_iface);
		wpa_s->ctrl_iface = NULL;
	}

#ifdef CONFIG_MESH
	if (wpa_s->ifmsh) {
		wpa_supplicant_mesh_iface_deinit(wpa_s, wpa_s->ifmsh);
		wpa_s->ifmsh = NULL;
	}
#endif /* CONFIG_MESH */

	if (wpa_s->conf != NULL) {
		wpa_config_free(wpa_s->conf);
		wpa_s->conf = NULL;
	}

	os_free(wpa_s->ssids_from_scan_req);

	os_free(wpa_s);
}
#ifdef CONFIG_MATCH_IFACE
#endif /* CONFIG_MATCH_IFACE */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
int wpa_supplicant_remove_iface(struct wpa_global *global,
				struct wpa_supplicant *wpa_s,
				int terminate)
{
	struct wpa_supplicant *prev;
#ifdef CONFIG_MESH
	unsigned int mesh_if_created = wpa_s->mesh_if_created;
	char *ifname = NULL;
	struct wpa_supplicant *parent = wpa_s->parent;
#endif /* CONFIG_MESH */

	/* Remove interface from the global list of interfaces */
	prev = global->ifaces;
	if (prev == wpa_s) {
		global->ifaces = wpa_s->next;
	} else {
		while (prev && prev->next != wpa_s)
			prev = prev->next;
		if (prev == NULL)
			return -1;
		prev->next = wpa_s->next;
	}

	wpa_dbg(wpa_s, MSG_DEBUG, "Removing interface %s", wpa_s->ifname);

#ifdef CONFIG_MESH
	if (mesh_if_created) {
		ifname = os_strdup(wpa_s->ifname);
		if (ifname == NULL) {
			wpa_dbg(wpa_s, MSG_ERROR,
				"mesh: Failed to malloc ifname");
			return -1;
		}
	}
#endif /* CONFIG_MESH */

	if (global->p2p_group_formation == wpa_s)
		global->p2p_group_formation = NULL;
	if (global->p2p_invite_group == wpa_s)
		global->p2p_invite_group = NULL;
	wpa_supplicant_deinit_iface(wpa_s, 1, terminate);

#ifdef CONFIG_MESH
	if (mesh_if_created) {
		wpa_drv_if_remove(parent, WPA_IF_MESH, ifname);
		os_free(ifname);
	}
#endif /* CONFIG_MESH */

	return 0;
}
#ifndef CONFIG_NO_WPA_MSG
#endif /* CONFIG_NO_WPA_MSG */
#ifndef WPA_SUPPLICANT_CLEANUP_INTERVAL
#define WPA_SUPPLICANT_CLEANUP_INTERVAL 10
#endif /* WPA_SUPPLICANT_CLEANUP_INTERVAL */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_DRIVER_NDIS
#endif /* CONFIG_DRIVER_NDIS */
#ifndef CONFIG_NO_WPA_MSG
#endif /* CONFIG_NO_WPA_MSG */
#ifdef CONFIG_MATCH_IFACE
#endif /* CONFIG_MATCH_IFACE */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_MATCH_IFACE
#endif
void wpa_supplicant_deinit(struct wpa_global *global)
{
	int i;

	if (global == NULL)
		return;

	eloop_cancel_timeout(wpas_periodic, global, NULL);

#ifdef CONFIG_WIFI_DISPLAY
	wifi_display_deinit(global);
#endif /* CONFIG_WIFI_DISPLAY */

	while (global->ifaces)
		wpa_supplicant_remove_iface(global, global->ifaces, 1);

	if (global->ctrl_iface)
		wpa_supplicant_global_ctrl_iface_deinit(global->ctrl_iface);

	wpas_notify_supplicant_deinitialized(global);

	eap_peer_unregister_methods();
#ifdef CONFIG_AP
	eap_server_unregister_methods();
#endif /* CONFIG_AP */

	for (i = 0; wpa_drivers[i] && global->drv_priv; i++) {
		if (!global->drv_priv[i])
			continue;
		wpa_drivers[i]->global_deinit(global->drv_priv[i]);
	}
	os_free(global->drv_priv);

	random_deinit();

	eloop_destroy();

	if (global->params.pid_file) {
		os_daemonize_terminate(global->params.pid_file);
		os_free(global->params.pid_file);
	}
	os_free(global->params.ctrl_interface);
	os_free(global->params.ctrl_interface_group);
	os_free(global->params.override_driver);
	os_free(global->params.override_ctrl_interface);
#ifdef CONFIG_MATCH_IFACE
	os_free(global->params.match_ifaces);
#endif /* CONFIG_MATCH_IFACE */
#ifdef CONFIG_P2P
	os_free(global->params.conf_p2p_dev);
#endif /* CONFIG_P2P */

	os_free(global->p2p_disallow_freq.range);
	os_free(global->p2p_go_avoid_freq.range);
	os_free(global->add_psk);

	os_free(global);
	wpa_debug_close_syslog();
	wpa_debug_close_file();
	wpa_debug_close_linux_tracing();
}
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#if defined(CONFIG_CTRL_IFACE) || defined(CONFIG_CTRL_IFACE_DBUS_NEW)
#ifdef IEEE8021X_EAPOL
#else /* IEEE8021X_EAPOL */
#endif /* IEEE8021X_EAPOL */
#endif /* CONFIG_CTRL_IFACE || CONFIG_CTRL_IFACE_DBUS_NEW */
#ifdef CONFIG_IEEE80211W
#else /* CONFIG_IEEE80211W */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
int wpas_vendor_elem_remove(struct wpa_supplicant *wpa_s, int frame,
			    const u8 *elem, size_t len)
{
	u8 *ie, *end;

	ie = wpabuf_mhead_u8(wpa_s->vendor_elem[frame]);
	end = ie + wpabuf_len(wpa_s->vendor_elem[frame]);

	for (; ie + 1 < end; ie += 2 + ie[1]) {
		if (ie + len > end)
			break;
		if (os_memcmp(ie, elem, len) != 0)
			continue;

		if (wpabuf_len(wpa_s->vendor_elem[frame]) == len) {
			wpabuf_free(wpa_s->vendor_elem[frame]);
			wpa_s->vendor_elem[frame] = NULL;
		} else {
			os_memmove(ie, ie + len, end - (ie + len));
			wpa_s->vendor_elem[frame]->used -= len;
		}
		wpas_vendor_elem_update(wpa_s);
		return 0;
	}

	return -1;
}
