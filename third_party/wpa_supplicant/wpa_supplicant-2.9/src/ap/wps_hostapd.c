#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/uuid.h"
#include "common/wpa_ctrl.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "eapol_auth/eapol_auth_sm_i.h"
#include "wps/wps.h"
#include "wps/wps_defs.h"
#include "wps/wps_dev_attr.h"
#include "wps/wps_attr_parse.h"
#include "hostapd.h"
#include "ap_config.h"
#include "ap_drv_ops.h"
#include "beacon.h"
#include "sta_info.h"
#include "wps_hostapd.h"
#ifdef CONFIG_WPS_UPNP
#include "wps/wps_upnp.h"
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
void hostapd_deinit_wps(struct hostapd_data *hapd)
{
	eloop_cancel_timeout(hostapd_wps_reenable_ap_pin, hapd, NULL);
	eloop_cancel_timeout(hostapd_wps_ap_pin_timeout, hapd, NULL);
	eloop_cancel_timeout(wps_reload_config, hapd->iface, NULL);
	if (hapd->wps == NULL) {
		hostapd_wps_clear_ies(hapd, 1);
		return;
	}
#ifdef CONFIG_WPS_UPNP
	hostapd_wps_upnp_deinit(hapd);
#endif /* CONFIG_WPS_UPNP */
	wps_registrar_deinit(hapd->wps->registrar);
	wps_free_pending_msgs(hapd->wps->upnp_msgs);
	hostapd_free_wps(hapd->wps);
	hapd->wps = NULL;
	hostapd_wps_clear_ies(hapd, 1);
}
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#ifndef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
