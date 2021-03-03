#include "utils/includes.h"
#ifdef CONFIG_SQLITE
#include <sqlite3.h>
#endif /* CONFIG_SQLITE */
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "common/hw_features_common.h"
#include "radius/radius_client.h"
#include "radius/radius_das.h"
#include "eap_server/tncs.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "eapol_auth/eapol_auth_sm_i.h"
#include "fst/fst.h"
#include "hostapd.h"
#include "authsrv.h"
#include "sta_info.h"
#include "accounting.h"
#include "ap_list.h"
#include "beacon.h"
#include "iapp.h"
#include "ieee802_1x.h"
#include "ieee802_11_auth.h"
#include "vlan_init.h"
#include "wpa_auth.h"
#include "wps_hostapd.h"
#include "dpp_hostapd.h"
#include "gas_query_ap.h"
#include "hw_features.h"
#include "wpa_auth_glue.h"
#include "ap_drv_ops.h"
#include "ap_config.h"
#include "p2p_hostapd.h"
#include "gas_serv.h"
#include "dfs.h"
#include "ieee802_11.h"
#include "bss_load.h"
#include "x_snoop.h"
#include "dhcp_snoop.h"
#include "ndisc_snoop.h"
#include "neighbor_db.h"
#include "rrm.h"
#include "fils_hlp.h"
#include "acs.h"
#include "hs20.h"
#include "airtime_policy.h"
#include "wpa_auth_kay.h"
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
static void hostapd_free_hapd_data(struct hostapd_data *hapd)
{
	os_free(hapd->probereq_cb);
	hapd->probereq_cb = NULL;
	hapd->num_probereq_cb = 0;

#ifdef CONFIG_P2P
	wpabuf_free(hapd->p2p_beacon_ie);
	hapd->p2p_beacon_ie = NULL;
	wpabuf_free(hapd->p2p_probe_resp_ie);
	hapd->p2p_probe_resp_ie = NULL;
#endif /* CONFIG_P2P */

	if (!hapd->started) {
		wpa_printf(MSG_ERROR, "%s: Interface %s wasn't started",
			   __func__, hapd->conf ? hapd->conf->iface : "N/A");
		return;
	}
	hapd->started = 0;
	hapd->beacon_set_done = 0;

	wpa_printf(MSG_DEBUG, "%s(%s)", __func__, hapd->conf->iface);
	iapp_deinit(hapd->iapp);
	hapd->iapp = NULL;
	accounting_deinit(hapd);
	hostapd_deinit_wpa(hapd);
	vlan_deinit(hapd);
	hostapd_acl_deinit(hapd);
#ifndef CONFIG_NO_RADIUS
	radius_client_deinit(hapd->radius);
	hapd->radius = NULL;
	radius_das_deinit(hapd->radius_das);
	hapd->radius_das = NULL;
#endif /* CONFIG_NO_RADIUS */

	hostapd_deinit_wps(hapd);
	ieee802_1x_dealloc_kay_sm_hapd(hapd);
#ifdef CONFIG_DPP
	hostapd_dpp_deinit(hapd);
	gas_query_ap_deinit(hapd->gas);
#endif /* CONFIG_DPP */

	authsrv_deinit(hapd);

	if (hapd->interface_added) {
		hapd->interface_added = 0;
		if (hostapd_if_remove(hapd, WPA_IF_AP_BSS, hapd->conf->iface)) {
			wpa_printf(MSG_WARNING,
				   "Failed to remove BSS interface %s",
				   hapd->conf->iface);
			hapd->interface_added = 1;
		} else {
			/*
			 * Since this was a dynamically added interface, the
			 * driver wrapper may have removed its internal instance
			 * and hapd->drv_priv is not valid anymore.
			 */
			hapd->drv_priv = NULL;
		}
	}

	wpabuf_free(hapd->time_adv);

#ifdef CONFIG_INTERWORKING
	gas_serv_deinit(hapd);
#endif /* CONFIG_INTERWORKING */

	bss_load_update_deinit(hapd);
	ndisc_snoop_deinit(hapd);
	dhcp_snoop_deinit(hapd);
	x_snoop_deinit(hapd);

#ifdef CONFIG_SQLITE
	bin_clear_free(hapd->tmp_eap_user.identity,
		       hapd->tmp_eap_user.identity_len);
	bin_clear_free(hapd->tmp_eap_user.password,
		       hapd->tmp_eap_user.password_len);
#endif /* CONFIG_SQLITE */

#ifdef CONFIG_MESH
	wpabuf_free(hapd->mesh_pending_auth);
	hapd->mesh_pending_auth = NULL;
#endif /* CONFIG_MESH */

	hostapd_clean_rrm(hapd);
	fils_hlp_deinit(hapd);

#ifdef CONFIG_SAE
	{
		struct hostapd_sae_commit_queue *q;

		while ((q = dl_list_first(&hapd->sae_commit_queue,
					  struct hostapd_sae_commit_queue,
					  list))) {
			dl_list_del(&q->list);
			os_free(q);
		}
	}
	eloop_cancel_timeout(auth_sae_process_commit, hapd, NULL);
#endif /* CONFIG_SAE */
}
static void hostapd_cleanup(struct hostapd_data *hapd)
{
	wpa_printf(MSG_DEBUG, "%s(hapd=%p (%s))", __func__, hapd,
		   hapd->conf ? hapd->conf->iface : "N/A");
	if (hapd->iface->interfaces &&
	    hapd->iface->interfaces->ctrl_iface_deinit) {
		wpa_msg(hapd->msg_ctx, MSG_INFO, WPA_EVENT_TERMINATING);
		hapd->iface->interfaces->ctrl_iface_deinit(hapd);
	}
	hostapd_free_hapd_data(hapd);
}
static void sta_track_deinit(struct hostapd_iface *iface)
{
	struct hostapd_sta_info *info;

	if (!iface->num_sta_seen)
		return;

	while ((info = dl_list_first(&iface->sta_seen, struct hostapd_sta_info,
				     list))) {
		dl_list_del(&info->list);
		iface->num_sta_seen--;
		sta_track_del(info);
	}
}
static void hostapd_cleanup_iface_partial(struct hostapd_iface *iface)
{
	wpa_printf(MSG_DEBUG, "%s(%p)", __func__, iface);
#ifdef CONFIG_IEEE80211N
#ifdef NEED_AP_MLME
	hostapd_stop_setup_timers(iface);
#endif /* NEED_AP_MLME */
#endif /* CONFIG_IEEE80211N */
	if (iface->current_mode)
		acs_cleanup(iface);
	hostapd_free_hw_features(iface->hw_features, iface->num_hw_features);
	iface->hw_features = NULL;
	iface->current_mode = NULL;
	os_free(iface->current_rates);
	iface->current_rates = NULL;
	os_free(iface->basic_rates);
	iface->basic_rates = NULL;
	ap_list_deinit(iface);
	sta_track_deinit(iface);
	airtime_policy_update_deinit(iface);
}
static void hostapd_cleanup_iface(struct hostapd_iface *iface)
{
	wpa_printf(MSG_DEBUG, "%s(%p)", __func__, iface);
	eloop_cancel_timeout(channel_list_update_timeout, iface, NULL);
	eloop_cancel_timeout(hostapd_interface_setup_failure_handler, iface,
			     NULL);

	hostapd_cleanup_iface_partial(iface);
	hostapd_config_free(iface->conf);
	iface->conf = NULL;

	os_free(iface->config_fname);
	os_free(iface->bss);
	wpa_printf(MSG_DEBUG, "%s: free iface=%p", __func__, iface);
	os_free(iface);
}
static void hostapd_bss_deinit_no_free(struct hostapd_data *hapd)
{
	hostapd_free_stas(hapd);
	hostapd_flush_old_stations(hapd, WLAN_REASON_DEAUTH_LEAVING);
	hostapd_clear_wep(hapd);
}
#ifndef CONFIG_NO_RADIUS
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_HS20
#else /* CONFIG_HS20 */
#define hostapd_das_coa NULL
#endif /* CONFIG_HS20 */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#endif /* CONFIG_NO_RADIUS */
#ifdef EAP_SERVER_TNC
#endif /* EAP_SERVER_TNC */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifndef CONFIG_NO_RADIUS
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
hostapd_alloc_bss_data(struct hostapd_iface *hapd_iface,
		       struct hostapd_config *conf,
		       struct hostapd_bss_config *bss)
{
	struct hostapd_data *hapd;

	hapd = os_zalloc(sizeof(*hapd));
	if (hapd == NULL)
		return NULL;

	hapd->new_assoc_sta_cb = hostapd_new_assoc_sta;
	hapd->iconf = conf;
	hapd->conf = bss;
	hapd->iface = hapd_iface;
	if (conf)
		hapd->driver = conf->driver;
	hapd->ctrl_sock = -1;
	dl_list_init(&hapd->ctrl_dst);
	dl_list_init(&hapd->nr_db);
	hapd->dhcp_sock = -1;
#ifdef CONFIG_IEEE80211R_AP
	dl_list_init(&hapd->l2_queue);
	dl_list_init(&hapd->l2_oui_queue);
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_SAE
	dl_list_init(&hapd->sae_commit_queue);
#endif /* CONFIG_SAE */

	return hapd;
}
static void hostapd_bss_deinit(struct hostapd_data *hapd)
{
	if (!hapd)
		return;
	wpa_printf(MSG_DEBUG, "%s: deinit bss %s", __func__,
		   hapd->conf ? hapd->conf->iface : "N/A");
	hostapd_bss_deinit_no_free(hapd);
	wpa_msg(hapd->msg_ctx, MSG_INFO, AP_EVENT_DISABLED);
#ifdef CONFIG_SQLITE
	if (hapd->rad_attr_db) {
		sqlite3_close(hapd->rad_attr_db);
		hapd->rad_attr_db = NULL;
	}
#endif /* CONFIG_SQLITE */
	hostapd_cleanup(hapd);
}
void hostapd_interface_deinit(struct hostapd_iface *iface)
{
	int j;

	wpa_printf(MSG_DEBUG, "%s(%p)", __func__, iface);
	if (iface == NULL)
		return;

	hostapd_set_state(iface, HAPD_IFACE_DISABLED);

	eloop_cancel_timeout(channel_list_update_timeout, iface, NULL);
	iface->wait_channel_update = 0;

#ifdef CONFIG_FST
	if (iface->fst) {
		fst_detach(iface->fst);
		iface->fst = NULL;
	}
#endif /* CONFIG_FST */

	for (j = (int) iface->num_bss - 1; j >= 0; j--) {
		if (!iface->bss)
			break;
		hostapd_bss_deinit(iface->bss[j]);
	}

#ifdef CONFIG_IEEE80211N
#ifdef NEED_AP_MLME
	hostapd_stop_setup_timers(iface);
	eloop_cancel_timeout(ap_ht2040_timeout, iface, NULL);
#endif /* NEED_AP_MLME */
#endif /* CONFIG_IEEE80211N */
}
void hostapd_interface_free(struct hostapd_iface *iface)
{
	size_t j;
	wpa_printf(MSG_DEBUG, "%s(%p)", __func__, iface);
	for (j = 0; j < iface->num_bss; j++) {
		if (!iface->bss)
			break;
		wpa_printf(MSG_DEBUG, "%s: free hapd %p",
			   __func__, iface->bss[j]);
		os_free(iface->bss[j]);
	}
	hostapd_cleanup_iface(iface);
}
struct hostapd_iface * hostapd_alloc_iface(void)
{
	struct hostapd_iface *hapd_iface;

	hapd_iface = os_zalloc(sizeof(*hapd_iface));
	if (!hapd_iface)
		return NULL;

	dl_list_init(&hapd_iface->sta_seen);

	return hapd_iface;
}
void hostapd_interface_deinit_free(struct hostapd_iface *iface)
{
	const struct wpa_driver_ops *driver;
	void *drv_priv;

	wpa_printf(MSG_DEBUG, "%s(%p)", __func__, iface);
	if (iface == NULL)
		return;
	wpa_printf(MSG_DEBUG, "%s: num_bss=%u conf->num_bss=%u",
		   __func__, (unsigned int) iface->num_bss,
		   (unsigned int) iface->conf->num_bss);
	driver = iface->bss[0]->driver;
	drv_priv = iface->bss[0]->drv_priv;
	hostapd_interface_deinit(iface);
	wpa_printf(MSG_DEBUG, "%s: driver=%p drv_priv=%p -> hapd_deinit",
		   __func__, driver, drv_priv);
	if (driver && driver->hapd_deinit && drv_priv) {
		driver->hapd_deinit(drv_priv);
		iface->bss[0]->drv_priv = NULL;
	}
	hostapd_interface_free(iface);
}
static void hostapd_deinit_driver(const struct wpa_driver_ops *driver,
				  void *drv_priv,
				  struct hostapd_iface *hapd_iface)
{
	size_t j;

	wpa_printf(MSG_DEBUG, "%s: driver=%p drv_priv=%p -> hapd_deinit",
		   __func__, driver, drv_priv);
	if (driver && driver->hapd_deinit && drv_priv) {
		driver->hapd_deinit(drv_priv);
		for (j = 0; j < hapd_iface->num_bss; j++) {
			wpa_printf(MSG_DEBUG, "%s:bss[%d]->drv_priv=%p",
				   __func__, (int) j,
				   hapd_iface->bss[j]->drv_priv);
			if (hapd_iface->bss[j]->drv_priv == drv_priv) {
				hapd_iface->bss[j]->drv_priv = NULL;
				hapd_iface->extended_capa = NULL;
				hapd_iface->extended_capa_mask = NULL;
				hapd_iface->extended_capa_len = 0;
			}
		}
	}
}
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
hostapd_iface_alloc(struct hapd_interfaces *interfaces)
{
	struct hostapd_iface **iface, *hapd_iface;

	iface = os_realloc_array(interfaces->iface, interfaces->count + 1,
				 sizeof(struct hostapd_iface *));
	if (iface == NULL)
		return NULL;
	interfaces->iface = iface;
	hapd_iface = interfaces->iface[interfaces->count] =
		hostapd_alloc_iface();
	if (hapd_iface == NULL) {
		wpa_printf(MSG_ERROR, "%s: Failed to allocate memory for "
			   "the interface", __func__);
		return NULL;
	}
	interfaces->count++;
	hapd_iface->interfaces = interfaces;

	return hapd_iface;
}
hostapd_config_alloc(struct hapd_interfaces *interfaces, const char *ifname,
		     const char *ctrl_iface, const char *driver)
{
	struct hostapd_bss_config *bss;
	struct hostapd_config *conf;

	/* Allocates memory for bss and conf */
	conf = hostapd_config_defaults();
	if (conf == NULL) {
		 wpa_printf(MSG_ERROR, "%s: Failed to allocate memory for "
				"configuration", __func__);
		 return NULL;
	}

	if (driver) {
		int j;

		for (j = 0; wpa_drivers[j]; j++) {
			if (os_strcmp(driver, wpa_drivers[j]->name) == 0) {
				conf->driver = wpa_drivers[j];
				goto skip;
			}
		}

		wpa_printf(MSG_ERROR,
			   "Invalid/unknown driver '%s' - registering the default driver",
			   driver);
	}

	conf->driver = wpa_drivers[0];
	if (conf->driver == NULL) {
		wpa_printf(MSG_ERROR, "No driver wrappers registered!");
		hostapd_config_free(conf);
		return NULL;
	}

skip:
	bss = conf->last_bss = conf->bss[0];

	os_strlcpy(bss->iface, ifname, sizeof(bss->iface));
	bss->ctrl_interface = os_strdup(ctrl_iface);
	if (bss->ctrl_interface == NULL) {
		hostapd_config_free(conf);
		return NULL;
	}

	/* Reading configuration file skipped, will be done in SET!
	 * From reading the configuration till the end has to be done in
	 * SET
	 */
	return conf;
}
static int hostapd_data_alloc(struct hostapd_iface *hapd_iface,
			      struct hostapd_config *conf)
{
	size_t i;
	struct hostapd_data *hapd;

	hapd_iface->bss = os_calloc(conf->num_bss,
				    sizeof(struct hostapd_data *));
	if (hapd_iface->bss == NULL)
		return -1;

	for (i = 0; i < conf->num_bss; i++) {
		hapd = hapd_iface->bss[i] =
			hostapd_alloc_bss_data(hapd_iface, conf, conf->bss[i]);
		if (hapd == NULL) {
			while (i > 0) {
				i--;
				os_free(hapd_iface->bss[i]);
				hapd_iface->bss[i] = NULL;
			}
			os_free(hapd_iface->bss);
			hapd_iface->bss = NULL;
			return -1;
		}
		hapd->msg_ctx = hapd;
	}

	hapd_iface->conf = conf;
	hapd_iface->num_bss = conf->num_bss;

	return 0;
}
static int hostapd_remove_bss(struct hostapd_iface *iface, unsigned int idx)
{
	size_t i;

	wpa_printf(MSG_INFO, "Remove BSS '%s'", iface->conf->bss[idx]->iface);

	/* Remove hostapd_data only if it has already been initialized */
	if (idx < iface->num_bss) {
		struct hostapd_data *hapd = iface->bss[idx];

		hostapd_bss_deinit(hapd);
		wpa_printf(MSG_DEBUG, "%s: free hapd %p (%s)",
			   __func__, hapd, hapd->conf->iface);
		hostapd_config_free_bss(hapd->conf);
		hapd->conf = NULL;
		os_free(hapd);

		iface->num_bss--;

		for (i = idx; i < iface->num_bss; i++)
			iface->bss[i] = iface->bss[i + 1];
	} else {
		hostapd_config_free_bss(iface->conf->bss[idx]);
		iface->conf->bss[idx] = NULL;
	}

	iface->conf->num_bss--;
	for (i = idx; i < iface->conf->num_bss; i++)
		iface->conf->bss[i] = iface->conf->bss[i + 1];

	return 0;
}
int hostapd_remove_iface(struct hapd_interfaces *interfaces, char *buf)
{
	struct hostapd_iface *hapd_iface;
	size_t i, j, k = 0;

	for (i = 0; i < interfaces->count; i++) {
		hapd_iface = interfaces->iface[i];
		if (hapd_iface == NULL)
			return -1;
		if (!os_strcmp(hapd_iface->conf->bss[0]->iface, buf)) {
			wpa_printf(MSG_INFO, "Remove interface '%s'", buf);
			hapd_iface->driver_ap_teardown =
				!!(hapd_iface->drv_flags &
				   WPA_DRIVER_FLAGS_AP_TEARDOWN_SUPPORT);

			hostapd_interface_deinit_free(hapd_iface);
			k = i;
			while (k < (interfaces->count - 1)) {
				interfaces->iface[k] =
					interfaces->iface[k + 1];
				k++;
			}
			interfaces->count--;
			return 0;
		}

		for (j = 0; j < hapd_iface->conf->num_bss; j++) {
			if (!os_strcmp(hapd_iface->conf->bss[j]->iface, buf)) {
				hapd_iface->driver_ap_teardown =
					!(hapd_iface->drv_flags &
					  WPA_DRIVER_FLAGS_AP_TEARDOWN_SUPPORT);
				return hostapd_remove_bss(hapd_iface, j);
			}
		}
	}
	return -1;
}
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef NEED_AP_MLME
static void free_beacon_data(struct beacon_data *beacon)
{
	os_free(beacon->head);
	beacon->head = NULL;
	os_free(beacon->tail);
	beacon->tail = NULL;
	os_free(beacon->probe_resp);
	beacon->probe_resp = NULL;
	os_free(beacon->beacon_ies);
	beacon->beacon_ies = NULL;
	os_free(beacon->proberesp_ies);
	beacon->proberesp_ies = NULL;
	os_free(beacon->assocresp_ies);
	beacon->assocresp_ies = NULL;
}
void hostapd_cleanup_cs_params(struct hostapd_data *hapd)
{
	os_memset(&hapd->cs_freq_params, 0, sizeof(hapd->cs_freq_params));
	hapd->cs_count = 0;
	hapd->cs_block_tx = 0;
	hapd->cs_c_off_beacon = 0;
	hapd->cs_c_off_proberesp = 0;
	hapd->csa_in_progress = 0;
	hapd->cs_c_off_ecsa_beacon = 0;
	hapd->cs_c_off_ecsa_proberesp = 0;
}
#endif /* NEED_AP_MLME */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
