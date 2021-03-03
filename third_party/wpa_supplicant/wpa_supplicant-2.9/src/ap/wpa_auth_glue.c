#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/list.h"
#include "common/ieee802_11_defs.h"
#include "common/sae.h"
#include "common/wpa_ctrl.h"
#include "crypto/sha1.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "eapol_auth/eapol_auth_sm_i.h"
#include "eap_server/eap.h"
#include "l2_packet/l2_packet.h"
#include "eth_p_oui.h"
#include "hostapd.h"
#include "ieee802_1x.h"
#include "preauth_auth.h"
#include "sta_info.h"
#include "tkip_countermeasures.h"
#include "ap_drv_ops.h"
#include "ap_config.h"
#include "ieee802_11.h"
#include "pmksa_cache_auth.h"
#include "wpa_auth.h"
#include "wpa_auth_glue.h"
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_HS20
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_HS20 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifndef CONFIG_NO_HOSTAPD_LOGGER
#endif /* CONFIG_NO_HOSTAPD_LOGGER */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_TESTING_OPTIONS
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_ETH_P_OUI
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#endif /* CONFIG_ETH_P_OUI */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_ETH_P_OUI
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#else /* CONFIG_ETH_P_OUI */
#endif /* CONFIG_ETH_P_OUI */
#ifndef CONFIG_NO_VLAN
#endif /* CONFIG_NO_VLAN */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
void hostapd_deinit_wpa(struct hostapd_data *hapd)
{
	ieee80211_tkip_countermeasures_deinit(hapd);
	rsn_preauth_iface_deinit(hapd);
	if (hapd->wpa_auth) {
		wpa_deinit(hapd->wpa_auth);
		hapd->wpa_auth = NULL;

		if (hapd->drv_priv && hostapd_set_privacy(hapd, 0)) {
			wpa_printf(MSG_DEBUG, "Could not disable "
				   "PrivacyInvoked for interface %s",
				   hapd->conf->iface);
		}

		if (hapd->drv_priv &&
		    hostapd_set_generic_elem(hapd, (u8 *) "", 0)) {
			wpa_printf(MSG_DEBUG, "Could not remove generic "
				   "information element from interface %s",
				   hapd->conf->iface);
		}
	}
	ieee802_1x_deinit(hapd);

#ifdef CONFIG_IEEE80211R_AP
	eloop_cancel_timeout(hostapd_wpa_ft_rrb_rx_later, hapd, ELOOP_ALL_CTX);
	hostapd_wpa_ft_rrb_rx_later(hapd, NULL); /* flush without delivering */
	eloop_cancel_timeout(hostapd_oui_deliver_later, hapd, ELOOP_ALL_CTX);
	hostapd_oui_deliver_later(hapd, NULL); /* flush without delivering */
	l2_packet_deinit(hapd->l2);
	hapd->l2 = NULL;
	hostapd_wpa_unregister_ft_oui(hapd);
#endif /* CONFIG_IEEE80211R_AP */
}
