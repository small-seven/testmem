#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "uuid.h"
#include "crypto/random.h"
#include "crypto/dh_group5.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/wpa_common.h"
#include "common/wpa_ctrl.h"
#include "eap_common/eap_wsc_common.h"
#include "eap_peer/eap.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "rsn_supp/wpa.h"
#include "wps/wps_attr_parse.h"
#include "config.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "notify.h"
#include "blacklist.h"
#include "bss.h"
#include "scan.h"
#include "ap.h"
#include "p2p/p2p.h"
#include "p2p_supplicant.h"
#include "wps_supplicant.h"
#ifndef WPS_PIN_SCAN_IGNORE_SEL_REG
#define WPS_PIN_SCAN_IGNORE_SEL_REG 3
#endif /* WPS_PIN_SCAN_IGNORE_SEL_REG */
#ifndef WPS_PIN_TIME_IGNORE_SEL_REG
#define WPS_PIN_TIME_IGNORE_SEL_REG 5
#endif /* WPS_PIN_TIME_IGNORE_SEL_REG */
#ifdef CONFIG_WPS_REG_DISABLE_OPEN
#endif /* CONFIG_WPS_REG_DISABLE_OPEN */
#ifdef CONFIG_WPS_REG_DISABLE_OPEN
#endif /* CONFIG_WPS_REG_DISABLE_OPEN */
#ifdef CONFIG_WPS_REG_DISABLE_OPEN
#endif /* CONFIG_WPS_REG_DISABLE_OPEN */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
static void wpa_supplicant_wps_event_er_ap_remove(struct wpa_supplicant *wpa_s,
						  struct wps_event_er_ap *ap)
{
	char uuid_str[100];
	uuid_bin2str(ap->uuid, uuid_str, sizeof(uuid_str));
	wpa_msg(wpa_s, MSG_INFO, WPS_EVENT_ER_AP_REMOVE "%s", uuid_str);
}
static void wpa_supplicant_wps_event_er_enrollee_remove(
	struct wpa_supplicant *wpa_s, struct wps_event_er_enrollee *enrollee)
{
	char uuid_str[100];
	uuid_bin2str(enrollee->uuid, uuid_str, sizeof(uuid_str));
	wpa_msg(wpa_s, MSG_INFO, WPS_EVENT_ER_ENROLLEE_REMOVE "%s " MACSTR,
		uuid_str, MAC2STR(enrollee->mac_addr));
}
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifndef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifndef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
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
#ifdef CONFIG_WPS_ER
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_WPS_ER
#endif /* CONFIG_WPS_ER */
void wpas_wps_deinit(struct wpa_supplicant *wpa_s)
{
	wpas_wps_assoc_with_cred_cancel(wpa_s);
	eloop_cancel_timeout(wpas_wps_timeout, wpa_s, NULL);
	eloop_cancel_timeout(wpas_wps_clear_timeout, wpa_s, NULL);
	eloop_cancel_timeout(wpas_wps_reenable_networks_cb, wpa_s, NULL);
	wpas_wps_clear_ap_info(wpa_s);

#ifdef CONFIG_P2P
	eloop_cancel_timeout(wpas_p2p_pbc_overlap_cb, wpa_s, NULL);
#endif /* CONFIG_P2P */

	if (wpa_s->wps == NULL)
		return;

#ifdef CONFIG_WPS_ER
	wps_er_deinit(wpa_s->wps_er, NULL, NULL);
	wpa_s->wps_er = NULL;
	wpas_wps_nfc_clear(wpa_s->wps);
#endif /* CONFIG_WPS_ER */

	wps_registrar_deinit(wpa_s->wps->registrar);
	wpabuf_free(wpa_s->wps->dh_pubkey);
	wpabuf_free(wpa_s->wps->dh_privkey);
	wpabuf_free(wpa_s->wps->dev.vendor_ext_m1);
	os_free(wpa_s->wps->network_key);
	os_free(wpa_s->wps);
	wpa_s->wps = NULL;
}
#ifdef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#ifdef CONFIG_WPS_ER
#else /* CONFIG_WPS_ER */
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_WPS_ER
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_WPS_ER
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_WPS_ER
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_WPS_NFC
#ifdef CONFIG_WPS_ER
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_WPS_ER
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_WPS_ER
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_WPS_ER
#endif /* CONFIG_WPS_ER */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS_NFC
#ifdef CONFIG_WPS_ER
#else /* CONFIG_WPS_ER */
#endif /* CONFIG_WPS_ER */
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS_NFC */
