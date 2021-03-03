#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "common/sae.h"
#include "common/dpp.h"
#include "radius/radius.h"
#include "radius/radius_client.h"
#include "p2p/p2p.h"
#include "fst/fst.h"
#include "crypto/crypto.h"
#include "hostapd.h"
#include "accounting.h"
#include "ieee802_1x.h"
#include "ieee802_11.h"
#include "ieee802_11_auth.h"
#include "wpa_auth.h"
#include "preauth_auth.h"
#include "ap_config.h"
#include "beacon.h"
#include "ap_mlme.h"
#include "vlan_init.h"
#include "p2p_hostapd.h"
#include "ap_drv_ops.h"
#include "gas_serv.h"
#include "wnm_ap.h"
#include "mbo_ap.h"
#include "ndisc_snoop.h"
#include "sta_info.h"
#include "vlan.h"
#include "wps_hostapd.h"
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
void ap_free_sta(struct hostapd_data *hapd, struct sta_info *sta)
{
	int set_beacon = 0;

	accounting_sta_stop(hapd, sta);

	/* just in case */
	ap_sta_set_authorized(hapd, sta, 0);

	if (sta->flags & (WLAN_STA_WDS | WLAN_STA_MULTI_AP))
		hostapd_set_wds_sta(hapd, NULL, sta->addr, sta->aid, 0);

	if (sta->ipaddr)
		hostapd_drv_br_delete_ip_neigh(hapd, 4, (u8 *) &sta->ipaddr);
	ap_sta_ip6addr_del(hapd, sta);

	if (!hapd->iface->driver_ap_teardown &&
	    !(sta->flags & WLAN_STA_PREAUTH)) {
		hostapd_drv_sta_remove(hapd, sta->addr);
		sta->added_unassoc = 0;
	}

	ap_sta_hash_del(hapd, sta);
	ap_sta_list_del(hapd, sta);

	if (sta->aid > 0)
		hapd->sta_aid[(sta->aid - 1) / 32] &=
			~BIT((sta->aid - 1) % 32);

	hapd->num_sta--;
	if (sta->nonerp_set) {
		sta->nonerp_set = 0;
		hapd->iface->num_sta_non_erp--;
		if (hapd->iface->num_sta_non_erp == 0)
			set_beacon++;
	}

	if (sta->no_short_slot_time_set) {
		sta->no_short_slot_time_set = 0;
		hapd->iface->num_sta_no_short_slot_time--;
		if (hapd->iface->current_mode &&
		    hapd->iface->current_mode->mode == HOSTAPD_MODE_IEEE80211G
		    && hapd->iface->num_sta_no_short_slot_time == 0)
			set_beacon++;
	}

	if (sta->no_short_preamble_set) {
		sta->no_short_preamble_set = 0;
		hapd->iface->num_sta_no_short_preamble--;
		if (hapd->iface->current_mode &&
		    hapd->iface->current_mode->mode == HOSTAPD_MODE_IEEE80211G
		    && hapd->iface->num_sta_no_short_preamble == 0)
			set_beacon++;
	}

	if (sta->no_ht_gf_set) {
		sta->no_ht_gf_set = 0;
		hapd->iface->num_sta_ht_no_gf--;
	}

	if (sta->no_ht_set) {
		sta->no_ht_set = 0;
		hapd->iface->num_sta_no_ht--;
	}

	if (sta->ht_20mhz_set) {
		sta->ht_20mhz_set = 0;
		hapd->iface->num_sta_ht_20mhz--;
	}

#ifdef CONFIG_TAXONOMY
	wpabuf_free(sta->probe_ie_taxonomy);
	sta->probe_ie_taxonomy = NULL;
	wpabuf_free(sta->assoc_ie_taxonomy);
	sta->assoc_ie_taxonomy = NULL;
#endif /* CONFIG_TAXONOMY */

#ifdef CONFIG_IEEE80211N
	ht40_intolerant_remove(hapd->iface, sta);
#endif /* CONFIG_IEEE80211N */

#ifdef CONFIG_P2P
	if (sta->no_p2p_set) {
		sta->no_p2p_set = 0;
		hapd->num_sta_no_p2p--;
		if (hapd->num_sta_no_p2p == 0)
			hostapd_p2p_non_p2p_sta_disconnected(hapd);
	}
#endif /* CONFIG_P2P */

#if defined(NEED_AP_MLME) && defined(CONFIG_IEEE80211N)
	if (hostapd_ht_operation_update(hapd->iface) > 0)
		set_beacon++;
#endif /* NEED_AP_MLME && CONFIG_IEEE80211N */

#ifdef CONFIG_MESH
	if (hapd->mesh_sta_free_cb)
		hapd->mesh_sta_free_cb(hapd, sta);
#endif /* CONFIG_MESH */

	if (set_beacon)
		ieee802_11_set_beacons(hapd->iface);

	wpa_printf(MSG_DEBUG, "%s: cancel ap_handle_timer for " MACSTR,
		   __func__, MAC2STR(sta->addr));
	eloop_cancel_timeout(ap_handle_timer, hapd, sta);
	eloop_cancel_timeout(ap_handle_session_timer, hapd, sta);
	eloop_cancel_timeout(ap_handle_session_warning_timer, hapd, sta);
	ap_sta_clear_disconnect_timeouts(hapd, sta);
	sae_clear_retransmit_timer(hapd, sta);

	ieee802_1x_free_station(hapd, sta);
	wpa_auth_sta_deinit(sta->wpa_sm);
	rsn_preauth_free_station(hapd, sta);
#ifndef CONFIG_NO_RADIUS
	if (hapd->radius)
		radius_client_flush_auth(hapd->radius, sta->addr);
#endif /* CONFIG_NO_RADIUS */

#ifndef CONFIG_NO_VLAN
	/*
	 * sta->wpa_sm->group needs to be released before so that
	 * vlan_remove_dynamic() can check that no stations are left on the
	 * AP_VLAN netdev.
	 */
	if (sta->vlan_id)
		vlan_remove_dynamic(hapd, sta->vlan_id);
	if (sta->vlan_id_bound) {
		/*
		 * Need to remove the STA entry before potentially removing the
		 * VLAN.
		 */
		if (hapd->iface->driver_ap_teardown &&
		    !(sta->flags & WLAN_STA_PREAUTH)) {
			hostapd_drv_sta_remove(hapd, sta->addr);
			sta->added_unassoc = 0;
		}
		vlan_remove_dynamic(hapd, sta->vlan_id_bound);
	}
#endif /* CONFIG_NO_VLAN */

	os_free(sta->challenge);

#ifdef CONFIG_IEEE80211W
	os_free(sta->sa_query_trans_id);
	eloop_cancel_timeout(ap_sa_query_timer, hapd, sta);
#endif /* CONFIG_IEEE80211W */

#ifdef CONFIG_P2P
	p2p_group_notif_disassoc(hapd->p2p_group, sta->addr);
#endif /* CONFIG_P2P */

#ifdef CONFIG_INTERWORKING
	if (sta->gas_dialog) {
		int i;
		for (i = 0; i < GAS_DIALOG_MAX; i++)
			gas_serv_dialog_clear(&sta->gas_dialog[i]);
		os_free(sta->gas_dialog);
	}
#endif /* CONFIG_INTERWORKING */

	wpabuf_free(sta->wps_ie);
	wpabuf_free(sta->p2p_ie);
	wpabuf_free(sta->hs20_ie);
	wpabuf_free(sta->roaming_consortium);
#ifdef CONFIG_FST
	wpabuf_free(sta->mb_ies);
#endif /* CONFIG_FST */

	os_free(sta->ht_capabilities);
	os_free(sta->vht_capabilities);
	os_free(sta->vht_operation);
	os_free(sta->he_capab);
	hostapd_free_psk_list(sta->psk);
	os_free(sta->identity);
	os_free(sta->radius_cui);
	os_free(sta->remediation_url);
	os_free(sta->t_c_url);
	wpabuf_free(sta->hs20_deauth_req);
	os_free(sta->hs20_session_info_url);

#ifdef CONFIG_SAE
	sae_clear_data(sta->sae);
	os_free(sta->sae);
#endif /* CONFIG_SAE */

	mbo_ap_sta_free(sta);
	os_free(sta->supp_op_classes);

#ifdef CONFIG_FILS
	os_free(sta->fils_pending_assoc_req);
	wpabuf_free(sta->fils_hlp_resp);
	wpabuf_free(sta->hlp_dhcp_discover);
	eloop_cancel_timeout(fils_hlp_timeout, hapd, sta);
#ifdef CONFIG_FILS_SK_PFS
	crypto_ecdh_deinit(sta->fils_ecdh);
	wpabuf_clear_free(sta->fils_dh_ss);
	wpabuf_free(sta->fils_g_sta);
#endif /* CONFIG_FILS_SK_PFS */
#endif /* CONFIG_FILS */

#ifdef CONFIG_OWE
	bin_clear_free(sta->owe_pmk, sta->owe_pmk_len);
	crypto_ecdh_deinit(sta->owe_ecdh);
#endif /* CONFIG_OWE */

#ifdef CONFIG_DPP2
	dpp_pfs_free(sta->dpp_pfs);
	sta->dpp_pfs = NULL;
#endif /* CONFIG_DPP2 */

	os_free(sta->ext_capability);

#ifdef CONFIG_WNM_AP
	eloop_cancel_timeout(ap_sta_reset_steer_flag_timer, hapd, sta);
#endif /* CONFIG_WNM_AP */

	os_free(sta->ifname_wds);

	os_free(sta);
}
void hostapd_free_stas(struct hostapd_data *hapd)
{
	struct sta_info *sta, *prev;

	sta = hapd->sta_list;

	while (sta) {
		prev = sta;
		if (sta->flags & WLAN_STA_AUTH) {
			mlme_deauthenticate_indication(
				hapd, sta, WLAN_REASON_UNSPECIFIED);
		}
		sta = sta->next;
		wpa_printf(MSG_DEBUG, "Removing station " MACSTR,
			   MAC2STR(prev->addr));
		ap_free_sta(hapd, prev);
	}
}
#ifdef CONFIG_WNM_AP
#endif /* CONFIG_WNM_AP */
#ifdef CONFIG_TAXONOMY
#endif /* CONFIG_TAXONOMY */
static int ap_sta_remove(struct hostapd_data *hapd, struct sta_info *sta)
{
	ieee802_1x_notify_port_enabled(sta->eapol_sm, 0);

	if (sta->ipaddr)
		hostapd_drv_br_delete_ip_neigh(hapd, 4, (u8 *) &sta->ipaddr);
	ap_sta_ip6addr_del(hapd, sta);

	wpa_printf(MSG_DEBUG, "%s: Removing STA " MACSTR " from kernel driver",
		   hapd->conf->iface, MAC2STR(sta->addr));
	if (hostapd_drv_sta_remove(hapd, sta->addr) &&
	    sta->flags & WLAN_STA_ASSOC) {
		wpa_printf(MSG_DEBUG, "%s: Could not remove station " MACSTR
			   " from kernel driver",
			   hapd->conf->iface, MAC2STR(sta->addr));
		return -1;
	}
	sta->added_unassoc = 0;
	return 0;
}
static void ap_sta_remove_in_other_bss(struct hostapd_data *hapd,
				       struct sta_info *sta)
{
	struct hostapd_iface *iface = hapd->iface;
	size_t i;

	for (i = 0; i < iface->num_bss; i++) {
		struct hostapd_data *bss = iface->bss[i];
		struct sta_info *sta2;
		/* bss should always be set during operation, but it may be
		 * NULL during reconfiguration. Assume the STA is not
		 * associated to another BSS in that case to avoid NULL pointer
		 * dereferences. */
		if (bss == hapd || bss == NULL)
			continue;
		sta2 = ap_get_sta(bss, sta->addr);
		if (!sta2)
			continue;

		wpa_printf(MSG_DEBUG, "%s: disconnect old STA " MACSTR
			   " association from another BSS %s",
			   hapd->conf->iface, MAC2STR(sta2->addr),
			   bss->conf->iface);
		ap_sta_disconnect(bss, sta2, sta2->addr,
				  WLAN_REASON_PREV_AUTH_NOT_VALID);
	}
}
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
static int ap_sta_get_free_vlan_id(struct hostapd_data *hapd)
{
	struct hostapd_vlan *vlan;
	int vlan_id = MAX_VLAN_ID + 2;

retry:
	for (vlan = hapd->conf->vlan; vlan; vlan = vlan->next) {
		if (vlan->vlan_id == vlan_id) {
			vlan_id++;
			goto retry;
		}
	}
	return vlan_id;
}
#ifndef CONFIG_NO_VLAN
#else /* CONFIG_NO_VLAN */
#endif /* CONFIG_NO_VLAN */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
