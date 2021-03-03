#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "common/ieee802_11_common.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "wps/wps_i.h"
#include "p2p/p2p.h"
#include "ap/hostapd.h"
#include "ap/ap_config.h"
#include "ap/sta_info.h"
#include "ap/ap_drv_ops.h"
#include "ap/wps_hostapd.h"
#include "ap/p2p_hostapd.h"
#include "ap/dfs.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "rsn_supp/wpa.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "ap.h"
#include "config_ssid.h"
#include "config.h"
#include "notify.h"
#include "scan.h"
#include "bss.h"
#include "offchannel.h"
#include "wps_supplicant.h"
#include "p2p_supplicant.h"
#include "wifi_display.h"
#define P2P_MAX_JOIN_SCAN_ATTEMPTS 10
#define P2P_AUTO_PD_SCAN_ATTEMPTS 5
#define P2P_GO_FREQ_CHANGE_TIME 5
#define P2P_GO_CSA_COUNT 7
#define P2P_GO_CSA_BLOCK_TX 0
#ifndef P2P_MAX_CLIENT_IDLE
#define P2P_MAX_CLIENT_IDLE 10
#endif /* P2P_MAX_CLIENT_IDLE */
#ifndef P2P_MAX_INITIAL_CONN_WAIT
#define P2P_MAX_INITIAL_CONN_WAIT 10
#endif /* P2P_MAX_INITIAL_CONN_WAIT */
#ifndef P2P_MAX_INITIAL_CONN_WAIT_GO
#define P2P_MAX_INITIAL_CONN_WAIT_GO 10
#endif /* P2P_MAX_INITIAL_CONN_WAIT_GO */
#ifndef P2P_MAX_INITIAL_CONN_WAIT_GO_REINVOKE
#define P2P_MAX_INITIAL_CONN_WAIT_GO_REINVOKE 15
#endif /* P2P_MAX_INITIAL_CONN_WAIT_GO_REINVOKE */
#define P2P_MGMT_DEVICE_PREFIX		"p2p-dev-"
#define P2P_RECONSIDER_GO_MOVE_DELAY 30
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#define C(n)                            \
#undef C
#ifndef CONFIG_NO_STDOUT_DEBUG
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#endif /* CONFIG_NO_STDOUT_DEBUG */
static void wpas_p2p_listen_work_free(struct wpas_p2p_listen_work *lwork)
{
	if (lwork == NULL)
		return;
	wpabuf_free(lwork->probe_resp_ie);
	os_free(lwork);
}
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
void wpas_p2p_deinit(struct wpa_supplicant *wpa_s)
{
	if (wpa_s->driver && wpa_s->drv_priv)
		wpa_drv_probe_req_report(wpa_s, 0);

	if (wpa_s->go_params) {
		/* Clear any stored provisioning info */
		p2p_clear_provisioning_info(
			wpa_s->global->p2p,
			wpa_s->go_params->peer_device_addr);
	}

	os_free(wpa_s->go_params);
	wpa_s->go_params = NULL;
	eloop_cancel_timeout(wpas_p2p_psk_failure_removal, wpa_s, NULL);
	eloop_cancel_timeout(wpas_p2p_group_formation_timeout, wpa_s, NULL);
	eloop_cancel_timeout(wpas_p2p_join_scan, wpa_s, NULL);
	wpa_s->p2p_long_listen = 0;
	eloop_cancel_timeout(wpas_p2p_long_listen_timeout, wpa_s, NULL);
	eloop_cancel_timeout(wpas_p2p_group_idle_timeout, wpa_s, NULL);
	wpas_p2p_remove_pending_group_interface(wpa_s);
	eloop_cancel_timeout(wpas_p2p_group_freq_conflict, wpa_s, NULL);
	wpas_p2p_listen_work_done(wpa_s);
	if (wpa_s->p2p_send_action_work) {
		os_free(wpa_s->p2p_send_action_work->ctx);
		radio_work_done(wpa_s->p2p_send_action_work);
		wpa_s->p2p_send_action_work = NULL;
	}
	eloop_cancel_timeout(wpas_p2p_send_action_work_timeout, wpa_s, NULL);

	wpabuf_free(wpa_s->p2p_oob_dev_pw);
	wpa_s->p2p_oob_dev_pw = NULL;

	os_free(wpa_s->p2p_group_common_freqs);
	wpa_s->p2p_group_common_freqs = NULL;
	wpa_s->p2p_group_common_freqs_num = 0;

	/* TODO: remove group interface from the driver if this wpa_s instance
	 * is on top of a P2P group interface */
}
int wpas_p2p_group_remove(struct wpa_supplicant *wpa_s, const char *ifname)
{
	struct wpa_global *global = wpa_s->global;
	struct wpa_supplicant *calling_wpa_s = wpa_s;

	if (os_strcmp(ifname, "*") == 0) {
		struct wpa_supplicant *prev;
		wpa_s = global->ifaces;
		while (wpa_s) {
			prev = wpa_s;
			wpa_s = wpa_s->next;
			if (prev->p2p_group_interface !=
			    NOT_P2P_GROUP_INTERFACE ||
			    (prev->current_ssid &&
			     prev->current_ssid->p2p_group))
				wpas_p2p_disconnect_safely(prev, calling_wpa_s);
		}
		return 0;
	}

	for (wpa_s = global->ifaces; wpa_s; wpa_s = wpa_s->next) {
		if (os_strcmp(wpa_s->ifname, ifname) == 0)
			break;
	}

	return wpas_p2p_disconnect_safely(wpa_s, calling_wpa_s);
}
void wpas_p2p_network_removed(struct wpa_supplicant *wpa_s,
			      struct wpa_ssid *ssid)
{
	if (wpa_s->p2p_in_provisioning && ssid->p2p_group &&
	    eloop_cancel_timeout(wpas_p2p_group_formation_timeout,
				 wpa_s->p2pdev, NULL) > 0) {
		/**
		 * Remove the network by scheduling the group formation
		 * timeout to happen immediately. The teardown code
		 * needs to be scheduled to run asynch later so that we
		 * don't delete data from under ourselves unexpectedly.
		 * Calling wpas_p2p_group_formation_timeout directly
		 * causes a series of crashes in WPS failure scenarios.
		 */
		wpa_printf(MSG_DEBUG, "P2P: Canceled group formation due to "
			   "P2P group network getting removed");
		eloop_register_timeout(0, 0, wpas_p2p_group_formation_timeout,
				       wpa_s->p2pdev, NULL);
	}
}
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
void wpas_p2p_deinit_iface(struct wpa_supplicant *wpa_s)
{
	if (wpa_s == wpa_s->global->p2p_init_wpa_s && wpa_s->global->p2p) {
		wpa_dbg(wpa_s, MSG_DEBUG, "P2P: Disable P2P since removing "
			"the management interface is being removed");
		wpas_p2p_deinit_global(wpa_s->global);
	}
}
void wpas_p2p_ap_deinit(struct wpa_supplicant *wpa_s)
{
	if (wpa_s->ap_iface->bss)
		wpa_s->ap_iface->bss[0]->p2p_group = NULL;
	wpas_p2p_group_deinit(wpa_s);
}
