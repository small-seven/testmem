#include "includes.h"
#include "common.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "eap_peer/eap.h"
#include "rsn_supp/wpa.h"
#include "eloop.h"
#include "config.h"
#include "l2_packet/l2_packet.h"
#include "common/wpa_common.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "rsn_supp/pmksa_cache.h"
#include "sme.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "wpas_glue.h"
#include "wps_supplicant.h"
#include "bss.h"
#include "scan.h"
#include "notify.h"
#include "wpas_kay.h"
#ifndef CONFIG_NO_CONFIG_BLOBS
#if defined(IEEE8021X_EAPOL) || !defined(CONFIG_NO_WPA)
#endif /* defined(IEEE8021X_EAPOL) || !defined(CONFIG_NO_WPA) */
#endif /* CONFIG_NO_CONFIG_BLOBS */
#if defined(IEEE8021X_EAPOL) || !defined(CONFIG_NO_WPA)
static u8 * wpa_alloc_eapol(const struct wpa_supplicant *wpa_s, u8 type,
			    const void *data, u16 data_len,
			    size_t *msg_len, void **data_pos)
{
	struct ieee802_1x_hdr *hdr;

	*msg_len = sizeof(*hdr) + data_len;
	hdr = os_malloc(*msg_len);
	if (hdr == NULL)
		return NULL;

	hdr->version = wpa_s->conf->eapol_version;
	hdr->type = type;
	hdr->length = host_to_be16(data_len);

	if (data)
		os_memcpy(hdr + 1, data, data_len);
	else
		os_memset(hdr + 1, 0, data_len);

	if (data_pos)
		*data_pos = hdr + 1;

	return (u8 *) hdr;
}
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* IEEE8021X_EAPOL || !CONFIG_NO_WPA */
#ifdef IEEE8021X_EAPOL
#ifdef CONFIG_IEEE80211R
#else /* CONFIG_IEEE80211R */
#endif /* CONFIG_IEEE80211R */
#endif /* IEEE8021X_EAPOL */
#ifndef CONFIG_NO_WPA
static u8 * _wpa_alloc_eapol(void *wpa_s, u8 type,
			     const void *data, u16 data_len,
			     size_t *msg_len, void **data_pos)
{
	return wpa_alloc_eapol(wpa_s, type, data, data_len, msg_len, data_pos);
}
#ifdef CONFIG_TESTING_GET_GTK
#endif /* CONFIG_TESTING_GET_GTK */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
static int wpa_supplicant_remove_pmkid(void *_wpa_s, void *network_ctx,
				       const u8 *bssid, const u8 *pmkid,
				       const u8 *fils_cache_id)
{
	struct wpa_supplicant *wpa_s = _wpa_s;
	struct wpa_ssid *ssid;
	struct wpa_pmkid_params params;

	os_memset(&params, 0, sizeof(params));
	ssid = wpas_get_network_ctx(wpa_s, network_ctx);
	if (ssid)
		wpa_msg(wpa_s, MSG_INFO, PMKSA_CACHE_REMOVED MACSTR " %d",
			MAC2STR(bssid), ssid->id);
	if (ssid && fils_cache_id) {
		params.ssid = ssid->ssid;
		params.ssid_len = ssid->ssid_len;
		params.fils_cache_id = fils_cache_id;
	} else {
		params.bssid = bssid;
	}

	params.pmkid = pmkid;

	return wpa_drv_remove_pmkid(wpa_s, &params);
}
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#endif /* CONFIG_NO_WPA */
#ifdef IEEE8021X_EAPOL
#if defined(CONFIG_CTRL_IFACE) || !defined(CONFIG_NO_STDOUT_DEBUG)
#else /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#define wpa_supplicant_eap_param_needed NULL
#endif /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#endif /* IEEE8021X_EAPOL */
#ifdef IEEE8021X_EAPOL
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#endif /* IEEE8021X_EAPOL */
#ifndef CONFIG_NO_WPA
#endif /* CONFIG_NO_WPA */
#ifndef CONFIG_NO_WPA
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#endif /* CONFIG_NO_WPA */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
