#include "utils/includes.h"
#ifndef CONFIG_NATIVE_WINDOWS
#ifdef CONFIG_TESTING_OPTIONS
#include <net/ethernet.h>
#include <netinet/ip.h>
#endif /* CONFIG_TESTING_OPTIONS */
#include <sys/un.h>
#include <sys/stat.h>
#include <stddef.h>
#ifdef CONFIG_CTRL_IFACE_UDP
#include <netdb.h>
#endif /* CONFIG_CTRL_IFACE_UDP */
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/module_tests.h"
#include "common/version.h"
#include "common/ieee802_11_defs.h"
#include "common/ctrl_iface_common.h"
#ifdef CONFIG_DPP
#include "common/dpp.h"
#endif /* CONFIG_DPP */
#include "common/wpa_ctrl.h"
#include "crypto/tls.h"
#include "drivers/driver.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "radius/radius_client.h"
#include "radius/radius_server.h"
#include "l2_packet/l2_packet.h"
#include "ap/hostapd.h"
#include "ap/ap_config.h"
#include "ap/ieee802_1x.h"
#include "ap/wpa_auth.h"
#include "ap/ieee802_11.h"
#include "ap/sta_info.h"
#include "ap/wps_hostapd.h"
#include "ap/ctrl_iface_ap.h"
#include "ap/ap_drv_ops.h"
#include "ap/hs20.h"
#include "ap/wnm_ap.h"
#include "ap/wpa_auth.h"
#include "ap/beacon.h"
#include "ap/neighbor_db.h"
#include "ap/rrm.h"
#include "ap/dpp_hostapd.h"
#include "wps/wps_defs.h"
#include "wps/wps.h"
#include "fst/fst_ctrl_iface.h"
#include "config_file.h"
#include "ctrl_iface.h"
#define HOSTAPD_CLI_DUP_VALUE_MAX_LEN 256
#ifdef CONFIG_CTRL_IFACE_UDP
#define COOKIE_LEN 8
#define HOSTAPD_CTRL_IFACE_PORT		9877
#define HOSTAPD_CTRL_IFACE_PORT_LIMIT	50
#define HOSTAPD_GLOBAL_CTRL_IFACE_PORT		8878
#define HOSTAPD_GLOBAL_CTRL_IFACE_PORT_LIMIT	50
#endif /* CONFIG_CTRL_IFACE_UDP */
static int hostapd_ctrl_iface_detach(struct hostapd_data *hapd,
				     struct sockaddr_storage *from,
				     socklen_t fromlen)
{
	return ctrl_iface_detach(&hapd->ctrl_dst, from, fromlen);
}
#ifdef CONFIG_IEEE80211W
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_WNM_AP
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#endif /* CONFIG_WNM_AP */
#ifdef CONFIG_IEEE80211R_AP
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS_TESTING
#endif /* CONFIG_WPS_TESTING */
#ifdef CONFIG_TESTING_OPTIONS
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
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
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef NEED_AP_MLME
#else /* NEED_AP_MLME */
#endif /* NEED_AP_MLME */
#ifdef RADIUS_SERVER
#endif /* RADIUS_SERVER */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
static int hostapd_ctrl_iface_remove_neighbor(struct hostapd_data *hapd,
					      char *buf)
{
	struct wpa_ssid_value ssid;
	u8 bssid[ETH_ALEN];
	char *tmp;

	if (hwaddr_aton(buf, bssid)) {
		wpa_printf(MSG_ERROR, "CTRL: REMOVE_NEIGHBOR: Bad BSSID");
		return -1;
	}

	tmp = os_strstr(buf, "ssid=");
	if (!tmp || ssid_parse(tmp + 5, &ssid)) {
		wpa_printf(MSG_ERROR,
			   "CTRL: REMOVE_NEIGHBORr: Bad or missing SSID");
		return -1;
	}

	return hostapd_neighbor_remove(hapd, bssid, &ssid);
}
#ifdef CONFIG_DPP
#ifdef CONFIG_DPP2
#else /* CONFIG_DPP2 */
#endif /* CONFIG_DPP2 */
#endif /* CONFIG_DPP */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_TAXONOMY
#endif /* CONFIG_TAXONOMY */
#ifdef CONFIG_IEEE80211W
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_WNM_AP
#endif /* CONFIG_WNM_AP */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef RADIUS_SERVER
#endif /* RADIUS_SERVER */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef RADIUS_SERVER
#endif /* RADIUS_SERVER */
#ifdef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifndef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UDP
#ifdef CONFIG_CTRL_IFACE_UDP_REMOTE
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#else /* CONFIG_CTRL_IFACE_UDP */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef __FreeBSD__
#endif /* __FreeBSD__ */
#endif /* CONFIG_CTRL_IFACE_UDP */
void hostapd_ctrl_iface_deinit(struct hostapd_data *hapd)
{
	struct wpa_ctrl_dst *dst, *prev;

	if (hapd->ctrl_sock > -1) {
#ifndef CONFIG_CTRL_IFACE_UDP
		char *fname;
#endif /* !CONFIG_CTRL_IFACE_UDP */

		eloop_unregister_read_sock(hapd->ctrl_sock);
		close(hapd->ctrl_sock);
		hapd->ctrl_sock = -1;
#ifndef CONFIG_CTRL_IFACE_UDP
		fname = hostapd_ctrl_iface_path(hapd);
		if (fname)
			unlink(fname);
		os_free(fname);

		if (hapd->conf->ctrl_interface &&
		    rmdir(hapd->conf->ctrl_interface) < 0) {
			if (errno == ENOTEMPTY) {
				wpa_printf(MSG_DEBUG, "Control interface "
					   "directory not empty - leaving it "
					   "behind");
			} else {
				wpa_printf(MSG_ERROR,
					   "rmdir[ctrl_interface=%s]: %s",
					   hapd->conf->ctrl_interface,
					   strerror(errno));
			}
		}
#endif /* !CONFIG_CTRL_IFACE_UDP */
	}

	dl_list_for_each_safe(dst, prev, &hapd->ctrl_dst, struct wpa_ctrl_dst,
			      list)
		os_free(dst);

#ifdef CONFIG_TESTING_OPTIONS
	l2_packet_deinit(hapd->l2_test);
	hapd->l2_test = NULL;
#endif /* CONFIG_TESTING_OPTIONS */
}
static int hostapd_ctrl_iface_remove(struct hapd_interfaces *interfaces,
				     char *buf)
{
	if (hostapd_remove_iface(interfaces, buf) < 0) {
		wpa_printf(MSG_ERROR, "Removing interface %s failed", buf);
		return -1;
	}
	return 0;
}
static int hostapd_global_ctrl_iface_detach(struct hapd_interfaces *interfaces,
					    struct sockaddr_storage *from,
					    socklen_t fromlen)
{
	return ctrl_iface_detach(&interfaces->global_ctrl_dst, from, fromlen);
}
#ifdef CONFIG_WPS_TESTING
#endif /* CONFIG_WPS_TESTING */
#ifdef CONFIG_TESTING_OPTIONS
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_MODULE_TESTS
#endif /* CONFIG_MODULE_TESTS */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifndef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UDP
#ifdef CONFIG_CTRL_IFACE_UDP_REMOTE
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#else /* CONFIG_CTRL_IFACE_UDP */
#ifdef __FreeBSD__
#endif /* __FreeBSD__ */
#endif /* CONFIG_CTRL_IFACE_UDP */
void hostapd_global_ctrl_iface_deinit(struct hapd_interfaces *interfaces)
{
#ifndef CONFIG_CTRL_IFACE_UDP
	char *fname = NULL;
#endif /* CONFIG_CTRL_IFACE_UDP */
	struct wpa_ctrl_dst *dst, *prev;

	if (interfaces->global_ctrl_sock > -1) {
		eloop_unregister_read_sock(interfaces->global_ctrl_sock);
		close(interfaces->global_ctrl_sock);
		interfaces->global_ctrl_sock = -1;
#ifndef CONFIG_CTRL_IFACE_UDP
		fname = hostapd_global_ctrl_iface_path(interfaces);
		if (fname) {
			unlink(fname);
			os_free(fname);
		}

		if (interfaces->global_iface_path &&
		    rmdir(interfaces->global_iface_path) < 0) {
			if (errno == ENOTEMPTY) {
				wpa_printf(MSG_DEBUG, "Control interface "
					   "directory not empty - leaving it "
					   "behind");
			} else {
				wpa_printf(MSG_ERROR,
					   "rmdir[ctrl_interface=%s]: %s",
					   interfaces->global_iface_path,
					   strerror(errno));
			}
		}
#endif /* CONFIG_CTRL_IFACE_UDP */
	}

	os_free(interfaces->global_iface_path);
	interfaces->global_iface_path = NULL;

	dl_list_for_each_safe(dst, prev, &interfaces->global_ctrl_dst,
			      struct wpa_ctrl_dst, list)
		os_free(dst);
}
#endif /* CONFIG_NATIVE_WINDOWS */
