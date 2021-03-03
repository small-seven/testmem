#include "utils/includes.h"
#ifdef CONFIG_SQLITE
#include <sqlite3.h>
#endif /* CONFIG_SQLITE */
#include "utils/common.h"
#include "utils/eloop.h"
#include "crypto/md5.h"
#include "crypto/crypto.h"
#include "crypto/random.h"
#include "common/ieee802_11_defs.h"
#include "radius/radius.h"
#include "radius/radius_client.h"
#include "eap_server/eap.h"
#include "eap_common/eap_wsc_common.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "eapol_auth/eapol_auth_sm_i.h"
#include "p2p/p2p.h"
#include "hostapd.h"
#include "accounting.h"
#include "sta_info.h"
#include "wpa_auth.h"
#include "preauth_auth.h"
#include "pmksa_cache_auth.h"
#include "ap_config.h"
#include "ap_drv_ops.h"
#include "wps_hostapd.h"
#include "hs20.h"
#include "ieee802_11.h"
#include "ieee802_1x.h"
#include "wpa_auth_kay.h"
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifndef CONFIG_FIPS
#ifndef CONFIG_NO_RC4
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifndef CONFIG_NO_VLAN
#endif /* CONFIG_NO_VLAN */
#endif /* CONFIG_NO_RC4 */
#endif /* CONFIG_FIPS */
#ifndef CONFIG_NO_RADIUS
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
ieee802_1x_alloc_eapol_sm(struct hostapd_data *hapd, struct sta_info *sta)
{
	int flags = 0;
	if (sta->flags & WLAN_STA_PREAUTH)
		flags |= EAPOL_SM_PREAUTH;
	if (sta->wpa_sm) {
		flags |= EAPOL_SM_USES_WPA;
		if (wpa_auth_sta_get_pmksa(sta->wpa_sm))
			flags |= EAPOL_SM_FROM_PMKSA_CACHE;
	}
	return eapol_auth_alloc(hapd->eapol_auth, sta->addr, flags,
				sta->wps_ie, sta->p2p_ie, sta,
				sta->identity, sta->radius_cui);
}
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
void ieee802_1x_free_station(struct hostapd_data *hapd, struct sta_info *sta)
{
	struct eapol_state_machine *sm = sta->eapol_sm;

#ifdef CONFIG_HS20
	eloop_cancel_timeout(ieee802_1x_wnm_notif_send, hapd, sta);
#endif /* CONFIG_HS20 */

	if (sta->pending_eapol_rx) {
		wpabuf_free(sta->pending_eapol_rx->buf);
		os_free(sta->pending_eapol_rx);
		sta->pending_eapol_rx = NULL;
	}

	if (sm == NULL)
		return;

	sta->eapol_sm = NULL;

#ifndef CONFIG_NO_RADIUS
	radius_msg_free(sm->last_recv_radius);
	radius_free_class(&sm->radius_class);
#endif /* CONFIG_NO_RADIUS */

	eapol_auth_free(sm);
}
#ifndef CONFIG_NO_RADIUS
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifndef CONFIG_NO_VLAN
#endif /* CONFIG_NO_VLAN */
#ifndef CONFIG_NO_VLAN
#endif /* CONFIG_NO_VLAN */
#ifdef CONFIG_FILS
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#endif /* CONFIG_FILS */
#endif /* CONFIG_NO_RADIUS */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifndef CONFIG_NO_HOSTAPD_LOGGER
#endif /* CONFIG_NO_HOSTAPD_LOGGER */
#ifndef CONFIG_FIPS
#ifndef CONFIG_NO_RC4
#endif /* CONFIG_NO_RC4 */
#endif /* CONFIG_FIPS */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
void ieee802_1x_deinit(struct hostapd_data *hapd)
{
	eloop_cancel_timeout(ieee802_1x_rekey, hapd, NULL);

	if (hapd->driver && hapd->drv_priv &&
	    (hapd->conf->ieee802_1x || hapd->conf->wpa))
		hostapd_set_drv_ieee8021x(hapd, hapd->conf->iface, 0);

	eapol_auth_deinit(hapd->eapol_auth);
	hapd->eapol_auth = NULL;

	ieee802_1x_erp_flush(hapd);
}
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
