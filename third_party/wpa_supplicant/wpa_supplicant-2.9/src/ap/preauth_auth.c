#include "utils/includes.h"
#ifdef CONFIG_RSN_PREAUTH
#include "utils/common.h"
#include "utils/eloop.h"
#include "l2_packet/l2_packet.h"
#include "common/wpa_common.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "eapol_auth/eapol_auth_sm_i.h"
#include "hostapd.h"
#include "ap_config.h"
#include "ieee802_1x.h"
#include "sta_info.h"
#include "wpa_auth.h"
#include "preauth_auth.h"
#ifndef ETH_P_PREAUTH
#define ETH_P_PREAUTH 0x88C7 /* IEEE 802.11i pre-authentication */
#endif /* ETH_P_PREAUTH */
void rsn_preauth_iface_deinit(struct hostapd_data *hapd)
{
	struct rsn_preauth_interface *piface, *prev;

	piface = hapd->preauth_iface;
	hapd->preauth_iface = NULL;
	while (piface) {
		prev = piface;
		piface = piface->next;
		l2_packet_deinit(prev->l2);
		os_free(prev->ifname);
		os_free(prev);
	}
}
void rsn_preauth_free_station(struct hostapd_data *hapd, struct sta_info *sta)
{
	eloop_cancel_timeout(rsn_preauth_finished_cb, hapd, sta);
}
#endif /* CONFIG_RSN_PREAUTH */
