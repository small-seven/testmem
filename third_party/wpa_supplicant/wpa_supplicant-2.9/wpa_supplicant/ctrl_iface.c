#include "utils/includes.h"
#ifdef CONFIG_TESTING_OPTIONS
#include <netinet/ip.h>
#endif /* CONFIG_TESTING_OPTIONS */
#include <net/ethernet.h>
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/uuid.h"
#include "utils/module_tests.h"
#include "common/version.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/wpa_ctrl.h"
#ifdef CONFIG_DPP
#include "common/dpp.h"
#endif /* CONFIG_DPP */
#include "crypto/tls.h"
#include "ap/hostapd.h"
#include "eap_peer/eap.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "rsn_supp/wpa.h"
#include "rsn_supp/preauth.h"
#include "rsn_supp/pmksa_cache.h"
#include "l2_packet/l2_packet.h"
#include "wps/wps.h"
#include "fst/fst.h"
#include "fst/fst_ctrl_iface.h"
#include "config.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "wps_supplicant.h"
#include "ibss_rsn.h"
#include "ap.h"
#include "p2p_supplicant.h"
#include "p2p/p2p.h"
#include "hs20_supplicant.h"
#include "wifi_display.h"
#include "notify.h"
#include "bss.h"
#include "scan.h"
#include "ctrl_iface.h"
#include "interworking.h"
#include "blacklist.h"
#include "autoscan.h"
#include "wnm_sta.h"
#include "offchannel.h"
#include "drivers/driver.h"
#include "mesh.h"
#include "dpp_supplicant.h"
#include "sme.h"
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
#ifdef CONFIG_WPS_TESTING
#endif /* CONFIG_WPS_TESTING */
#ifdef CONFIG_TDLS
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#endif /* CONFIG_TDLS */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_DPP
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_DPP */
#ifdef CONFIG_TESTING_OPTIONS
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_TESTING_GET_GTK
#endif /* CONFIG_TESTING_GET_GTK */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_TDLS
#define SET_FREQ_SETTING(str) \
#undef SET_FREQ_SETTING
#endif /* CONFIG_TDLS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_WPS
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_WPS_NFC
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_WPS_ER
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS_ER */
#endif /* CONFIG_WPS */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef IEEE8021X_EAPOL
#else /* IEEE8021X_EAPOL */
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_SME
#ifdef CONFIG_SAE
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#endif /* CONFIG_SAE */
#endif /* CONFIG_SME */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS
#else /* CONFIG_WPS */
#endif /* CONFIG_WPS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_MESH
static int wpa_supplicant_ctrl_iface_mesh_group_remove(
	struct wpa_supplicant *wpa_s, char *cmd)
{
	struct wpa_supplicant *orig;
	struct wpa_global *global;
	int found = 0;

	wpa_printf(MSG_DEBUG, "CTRL_IFACE: MESH_GROUP_REMOVE ifname=%s", cmd);

	global = wpa_s->global;
	orig = wpa_s;

	for (wpa_s = global->ifaces; wpa_s; wpa_s = wpa_s->next) {
		if (os_strcmp(wpa_s->ifname, cmd) == 0) {
			found = 1;
			break;
		}
	}
	if (!found) {
		wpa_printf(MSG_ERROR,
			   "CTRL_IFACE: MESH_GROUP_REMOVE ifname=%s not found",
			   cmd);
		return -1;
	}
	if (wpa_s->mesh_if_created && wpa_s == orig) {
		wpa_printf(MSG_ERROR,
			   "CTRL_IFACE: MESH_GROUP_REMOVE can't remove itself");
		return -1;
	}

	wpa_s->reassociate = 0;
	wpa_s->disconnected = 1;
	wpa_supplicant_cancel_sched_scan(wpa_s);
	wpa_supplicant_cancel_scan(wpa_s);

	/*
	 * TODO: If necessary write our own group_remove function,
	 * for now we can reuse deauthenticate
	 */
	wpa_supplicant_deauthenticate(wpa_s, WLAN_REASON_DEAUTH_LEAVING);

	if (wpa_s->mesh_if_created)
		wpa_supplicant_remove_iface(global, wpa_s, 0);

	return 0;
}
static int wpa_supplicant_ctrl_iface_mesh_peer_remove(
	struct wpa_supplicant *wpa_s, char *cmd)
{
	u8 addr[ETH_ALEN];

	if (hwaddr_aton(cmd, addr) < 0)
		return -1;

	return wpas_mesh_peer_remove(wpa_s, addr);
}
#endif /* CONFIG_MESH */
static int wpa_supplicant_ctrl_iface_remove_network(
	struct wpa_supplicant *wpa_s, char *cmd)
{
	int id;
	struct wpa_ssid *ssid;
	int result;

	/* cmd: "<network id>" or "all" */
	if (os_strcmp(cmd, "all") == 0) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE: REMOVE_NETWORK all");
		if (wpa_s->sched_scanning)
			wpa_supplicant_cancel_sched_scan(wpa_s);

		eapol_sm_invalidate_cached_session(wpa_s->eapol);
		if (wpa_s->current_ssid) {
#ifdef CONFIG_SME
			wpa_s->sme.prev_bssid_set = 0;
#endif /* CONFIG_SME */
			wpa_sm_set_config(wpa_s->wpa, NULL);
			eapol_sm_notify_config(wpa_s->eapol, NULL, NULL);
			if (wpa_s->wpa_state >= WPA_AUTHENTICATING)
				wpa_s->own_disconnect_req = 1;
			wpa_supplicant_deauthenticate(
				wpa_s, WLAN_REASON_DEAUTH_LEAVING);
		}
		ssid = wpa_s->conf->ssid;
		while (ssid) {
			struct wpa_ssid *remove_ssid = ssid;
			id = ssid->id;
			ssid = ssid->next;
			if (wpa_s->last_ssid == remove_ssid)
				wpa_s->last_ssid = NULL;
			wpas_notify_network_removed(wpa_s, remove_ssid);
			wpa_config_remove_network(wpa_s->conf, id);
		}
		return 0;
	}

	id = atoi(cmd);
	wpa_printf(MSG_DEBUG, "CTRL_IFACE: REMOVE_NETWORK id=%d", id);

	result = wpa_supplicant_remove_network(wpa_s, id);
	if (result == -1) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE: Could not find network "
			   "id=%d", id);
		return -1;
	}
	if (result == -2) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE: Not able to remove the "
			   "network id=%d", id);
		return -1;
	}
	return 0;
}
static int wpas_ctrl_remove_cred(struct wpa_supplicant *wpa_s,
				 struct wpa_cred *cred)
{
	struct wpa_ssid *ssid;
	char str[20];
	int id;

	if (cred == NULL) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE: Could not find cred");
		return -1;
	}

	id = cred->id;
	if (wpa_config_remove_cred(wpa_s->conf, id) < 0) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE: Could not find cred");
		return -1;
	}

	wpa_msg(wpa_s, MSG_INFO, CRED_REMOVED "%d", id);

	/* Remove any network entry created based on the removed credential */
	ssid = wpa_s->conf->ssid;
	while (ssid) {
		if (ssid->parent_cred == cred) {
			int res;

			wpa_printf(MSG_DEBUG, "Remove network id %d since it "
				   "used the removed credential", ssid->id);
			res = os_snprintf(str, sizeof(str), "%d", ssid->id);
			if (os_snprintf_error(sizeof(str), res))
				str[sizeof(str) - 1] = '\0';
			ssid = ssid->next;
			wpa_supplicant_ctrl_iface_remove_network(wpa_s, str);
		} else
			ssid = ssid->next;
	}

	return 0;
}
static int wpa_supplicant_ctrl_iface_remove_cred(struct wpa_supplicant *wpa_s,
						 char *cmd)
{
	int id;
	struct wpa_cred *cred, *prev;

	/* cmd: "<cred id>", "all", "sp_fqdn=<FQDN>", or
	 * "provisioning_sp=<FQDN> */
	if (os_strcmp(cmd, "all") == 0) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE: REMOVE_CRED all");
		cred = wpa_s->conf->cred;
		while (cred) {
			prev = cred;
			cred = cred->next;
			wpas_ctrl_remove_cred(wpa_s, prev);
		}
		return 0;
	}

	if (os_strncmp(cmd, "sp_fqdn=", 8) == 0) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE: REMOVE_CRED SP FQDN '%s'",
			   cmd + 8);
		cred = wpa_s->conf->cred;
		while (cred) {
			prev = cred;
			cred = cred->next;
			if (prev->domain) {
				size_t i;
				for (i = 0; i < prev->num_domain; i++) {
					if (os_strcmp(prev->domain[i], cmd + 8)
					    != 0)
						continue;
					wpas_ctrl_remove_cred(wpa_s, prev);
					break;
				}
			}
		}
		return 0;
	}

	if (os_strncmp(cmd, "provisioning_sp=", 16) == 0) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE: REMOVE_CRED provisioning SP FQDN '%s'",
			   cmd + 16);
		cred = wpa_s->conf->cred;
		while (cred) {
			prev = cred;
			cred = cred->next;
			if (prev->provisioning_sp &&
			    os_strcmp(prev->provisioning_sp, cmd + 16) == 0)
				wpas_ctrl_remove_cred(wpa_s, prev);
		}
		return 0;
	}

	id = atoi(cmd);
	wpa_printf(MSG_DEBUG, "CTRL_IFACE: REMOVE_CRED id=%d", id);

	cred = wpa_config_get_cred(wpa_s->conf, id);
	return wpas_ctrl_remove_cred(wpa_s, cred);
}
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#endif /* CONFIG_FILS */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_ERP
#endif /* CONFIG_EPR */
#ifdef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifdef CONFIG_FILS
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#endif /* CONFIG_FILS */
#ifdef CONFIG_DPP
#ifdef CONFIG_DPP2
#else /* CONFIG_DPP2 */
#endif /* CONFIG_DPP2 */
#endif /* CONFIG_DPP */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_INTERWORKING
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_TESTING_OPTIONS
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_NO_SCAN_PROCESSING
#else /* CONFIG_NO_SCAN_PROCESSING */
#endif /* CONFIG_NO_SCAN_PROCESSING */
#ifdef CONFIG_P2P
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_P2P */
#ifdef CONFIG_INTERWORKING
#define MAX_ANQP_INFO_ID 100
#ifdef CONFIG_HS20
#else /* CONFIG_HS20 */
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#else /* CONFIG_MBO */
#endif /* CONFIG_MBO */
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_AUTOSCAN
#endif /* CONFIG_AUTOSCAN */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS_TESTING
#endif /* CONFIG_WPS_TESTING */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_DPP
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_DPP */
#ifdef CONFIG_TDLS
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#endif /* CONFIG_TDLS */
#ifdef CONFIG_INTERWORKING
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_TESTING_OPTIONS
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_TESTING_OPTIONS
#define HWSIM_PACKETLEN 1500
#define HWSIM_IP_LEN (HWSIM_PACKETLEN - sizeof(struct ether_header))
#ifdef WPA_TRACE_BFD
#else /* WPA_TRACE_BFD */
#endif /* WPA_TRACE_BFD */
#ifdef WPA_TRACE_BFD
#else /* WPA_TRACE_BFD */
#endif /* WPA_TRACE_BFD */
#ifdef WPA_TRACE_BFD
#else /* WPA_TRACE_BFD */
#endif /* WPA_TRACE_BFD */
#ifdef WPA_TRACE_BFD
#else /* WPA_TRACE_BFD */
#endif /* WPA_TRACE_BFD */
#ifdef CONFIG_SME
#else /* CONFIG_SME */
#endif /* CONFIG_SME */
#endif /* CONFIG_TESTING_OPTIONS */
static int wpas_ctrl_vendor_elem_remove(struct wpa_supplicant *wpa_s, char *cmd)
{
	char *pos = cmd;
	int frame;
	size_t len;
	u8 *buf;
	struct ieee802_11_elems elems;
	int res;

	frame = atoi(pos);
	if (frame < 0 || frame >= NUM_VENDOR_ELEM_FRAMES)
		return -1;
	wpa_s = wpas_vendor_elem(wpa_s, frame);

	pos = os_strchr(pos, ' ');
	if (pos == NULL)
		return -1;
	pos++;

	if (*pos == '*') {
		wpabuf_free(wpa_s->vendor_elem[frame]);
		wpa_s->vendor_elem[frame] = NULL;
		wpas_vendor_elem_update(wpa_s);
		return 0;
	}

	if (wpa_s->vendor_elem[frame] == NULL)
		return -1;

	len = os_strlen(pos);
	if (len == 0)
		return 0;
	if (len & 1)
		return -1;
	len /= 2;

	buf = os_malloc(len);
	if (buf == NULL)
		return -1;

	if (hexstr2bin(pos, buf, len) < 0) {
		os_free(buf);
		return -1;
	}

	if (ieee802_11_parse_elems(buf, len, &elems, 0) == ParseFailed) {
		os_free(buf);
		return -1;
	}

	res = wpas_vendor_elem_remove(wpa_s, frame, buf, len);
	os_free(buf);
	return res;
}
#define NR_IE_MIN_LEN (ETH_ALEN + 4 + 1 + 1 + 1)
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_WPS
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_WPS_ER
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS_ER */
#endif /* CONFIG_WPS */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_AUTOSCAN
#endif /* CONFIG_AUTOSCAN */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_TESTING_OPTIONS
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_DPP
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#endif /* CONFIG_DPP */
static int wpa_supplicant_global_iface_remove(struct wpa_global *global,
					      char *cmd)
{
	struct wpa_supplicant *wpa_s;
	int ret;
	unsigned int delete_iface;

	wpa_printf(MSG_DEBUG, "CTRL_IFACE GLOBAL INTERFACE_REMOVE '%s'", cmd);

	wpa_s = wpa_supplicant_get_iface(global, cmd);
	if (wpa_s == NULL)
		return -1;
	delete_iface = wpa_s->added_vif;
	ret = wpa_supplicant_remove_iface(global, wpa_s, 0);
	if (!ret && delete_iface) {
		wpa_printf(MSG_DEBUG, "CTRL_IFACE deleting the interface '%s'",
			   cmd);
		ret = wpa_drv_if_remove(global->ifaces, WPA_IF_STATION, cmd);
	}
	return ret;
}
static void wpa_free_iface_info(struct wpa_interface_info *iface)
{
	struct wpa_interface_info *prev;

	while (iface) {
		prev = iface;
		iface = iface->next;

		os_free(prev->ifname);
		os_free(prev->desc);
		os_free(prev);
	}
}
#ifdef CONFIG_P2P
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#endif /* CONFIG_P2P */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_MODULE_TESTS
#endif /* CONFIG_MODULE_TESTS */
