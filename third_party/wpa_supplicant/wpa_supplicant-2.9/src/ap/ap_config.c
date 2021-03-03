#include "utils/includes.h"
#include "utils/common.h"
#include "crypto/sha1.h"
#include "crypto/tls.h"
#include "radius/radius_client.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_1x_defs.h"
#include "common/eapol_common.h"
#include "common/dhcp.h"
#include "eap_common/eap_wsc_common.h"
#include "eap_server/eap.h"
#include "wpa_auth.h"
#include "sta_info.h"
#include "airtime_policy.h"
#include "ap_config.h"
static void hostapd_config_free_vlan(struct hostapd_bss_config *bss)
{
	struct hostapd_vlan *vlan, *prev;

	vlan = bss->vlan;
	prev = NULL;
	while (vlan) {
		prev = vlan;
		vlan = vlan->next;
		os_free(prev);
	}

	bss->vlan = NULL;
}
#ifndef DEFAULT_WPA_DISABLE_EAPOL_KEY_RETRIES
#define DEFAULT_WPA_DISABLE_EAPOL_KEY_RETRIES 0
#endif /* DEFAULT_WPA_DISABLE_EAPOL_KEY_RETRIES */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef EAP_SERVER_FAST
#endif /* EAP_SERVER_FAST */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#define ecw2cw(ecw) ((1 << (ecw)) - 1)
#undef ecw2cw
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_AIRTIME_POLICY
#endif /* CONFIG_AIRTIME_POLICY */
static void hostapd_config_free_radius(struct hostapd_radius_server *servers,
				       int num_servers)
{
	int i;

	for (i = 0; i < num_servers; i++) {
		os_free(servers[i].shared_secret);
	}
	os_free(servers);
}
void hostapd_config_free_radius_attr(struct hostapd_radius_attr *attr)
{
	struct hostapd_radius_attr *prev;

	while (attr) {
		prev = attr;
		attr = attr->next;
		wpabuf_free(prev->val);
		os_free(prev);
	}
}
void hostapd_config_free_eap_user(struct hostapd_eap_user *user)
{
	hostapd_config_free_radius_attr(user->accept_attr);
	os_free(user->identity);
	bin_clear_free(user->password, user->password_len);
	bin_clear_free(user->salt, user->salt_len);
	os_free(user);
}
void hostapd_config_free_eap_users(struct hostapd_eap_user *user)
{
	struct hostapd_eap_user *prev_user;

	while (user) {
		prev_user = user;
		user = user->next;
		hostapd_config_free_eap_user(prev_user);
	}
}
static void hostapd_config_free_wep(struct hostapd_wep_keys *keys)
{
	int i;
	for (i = 0; i < NUM_WEP_KEYS; i++) {
		bin_clear_free(keys->key[i], keys->len[i]);
		keys->key[i] = NULL;
	}
}
static void hostapd_config_free_anqp_elem(struct hostapd_bss_config *conf)
{
	struct anqp_element *elem;

	while ((elem = dl_list_first(&conf->anqp_elem, struct anqp_element,
				     list))) {
		dl_list_del(&elem->list);
		wpabuf_free(elem->payload);
		os_free(elem);
	}
}
static void hostapd_config_free_fils_realms(struct hostapd_bss_config *conf)
{
#ifdef CONFIG_FILS
	struct fils_realm *realm;

	while ((realm = dl_list_first(&conf->fils_realms, struct fils_realm,
				      list))) {
		dl_list_del(&realm->list);
		os_free(realm);
	}
#endif /* CONFIG_FILS */
}
static void hostapd_config_free_sae_passwords(struct hostapd_bss_config *conf)
{
	struct sae_password_entry *pw, *tmp;

	pw = conf->sae_passwords;
	conf->sae_passwords = NULL;
	while (pw) {
		tmp = pw;
		pw = pw->next;
		str_clear_free(tmp->password);
		os_free(tmp->identifier);
		os_free(tmp);
	}
}
#ifdef CONFIG_DPP2
static void hostapd_dpp_controller_conf_free(struct dpp_controller_conf *conf)
{
	struct dpp_controller_conf *prev;

	while (conf) {
		prev = conf;
		conf = conf->next;
		os_free(prev);
	}
}
#endif /* CONFIG_DPP2 */
void hostapd_config_free_bss(struct hostapd_bss_config *conf)
{
#if defined(CONFIG_WPS) || defined(CONFIG_HS20)
	size_t i;
#endif

	if (conf == NULL)
		return;

	hostapd_config_clear_wpa_psk(&conf->ssid.wpa_psk);

	str_clear_free(conf->ssid.wpa_passphrase);
	os_free(conf->ssid.wpa_psk_file);
	hostapd_config_free_wep(&conf->ssid.wep);
#ifdef CONFIG_FULL_DYNAMIC_VLAN
	os_free(conf->ssid.vlan_tagged_interface);
#endif /* CONFIG_FULL_DYNAMIC_VLAN */

	hostapd_config_free_eap_users(conf->eap_user);
	os_free(conf->eap_user_sqlite);

	os_free(conf->eap_req_id_text);
	os_free(conf->erp_domain);
	os_free(conf->accept_mac);
	os_free(conf->deny_mac);
	os_free(conf->nas_identifier);
	if (conf->radius) {
		hostapd_config_free_radius(conf->radius->auth_servers,
					   conf->radius->num_auth_servers);
		hostapd_config_free_radius(conf->radius->acct_servers,
					   conf->radius->num_acct_servers);
	}
	hostapd_config_free_radius_attr(conf->radius_auth_req_attr);
	hostapd_config_free_radius_attr(conf->radius_acct_req_attr);
	os_free(conf->radius_req_attr_sqlite);
	os_free(conf->rsn_preauth_interfaces);
	os_free(conf->ctrl_interface);
	os_free(conf->ca_cert);
	os_free(conf->server_cert);
	os_free(conf->server_cert2);
	os_free(conf->private_key);
	os_free(conf->private_key2);
	os_free(conf->private_key_passwd);
	os_free(conf->private_key_passwd2);
	os_free(conf->check_cert_subject);
	os_free(conf->ocsp_stapling_response);
	os_free(conf->ocsp_stapling_response_multi);
	os_free(conf->dh_file);
	os_free(conf->openssl_ciphers);
	os_free(conf->openssl_ecdh_curves);
	os_free(conf->pac_opaque_encr_key);
	os_free(conf->eap_fast_a_id);
	os_free(conf->eap_fast_a_id_info);
	os_free(conf->eap_sim_db);
	os_free(conf->radius_server_clients);
	os_free(conf->radius);
	os_free(conf->radius_das_shared_secret);
	hostapd_config_free_vlan(conf);
	os_free(conf->time_zone);

#ifdef CONFIG_IEEE80211R_AP
	{
		struct ft_remote_r0kh *r0kh, *r0kh_prev;
		struct ft_remote_r1kh *r1kh, *r1kh_prev;

		r0kh = conf->r0kh_list;
		conf->r0kh_list = NULL;
		while (r0kh) {
			r0kh_prev = r0kh;
			r0kh = r0kh->next;
			os_free(r0kh_prev);
		}

		r1kh = conf->r1kh_list;
		conf->r1kh_list = NULL;
		while (r1kh) {
			r1kh_prev = r1kh;
			r1kh = r1kh->next;
			os_free(r1kh_prev);
		}
	}
#endif /* CONFIG_IEEE80211R_AP */

#ifdef CONFIG_WPS
	os_free(conf->wps_pin_requests);
	os_free(conf->device_name);
	os_free(conf->manufacturer);
	os_free(conf->model_name);
	os_free(conf->model_number);
	os_free(conf->serial_number);
	os_free(conf->config_methods);
	os_free(conf->ap_pin);
	os_free(conf->extra_cred);
	os_free(conf->ap_settings);
	hostapd_config_clear_wpa_psk(&conf->multi_ap_backhaul_ssid.wpa_psk);
	str_clear_free(conf->multi_ap_backhaul_ssid.wpa_passphrase);
	os_free(conf->upnp_iface);
	os_free(conf->friendly_name);
	os_free(conf->manufacturer_url);
	os_free(conf->model_description);
	os_free(conf->model_url);
	os_free(conf->upc);
	for (i = 0; i < MAX_WPS_VENDOR_EXTENSIONS; i++)
		wpabuf_free(conf->wps_vendor_ext[i]);
	wpabuf_free(conf->wps_nfc_dh_pubkey);
	wpabuf_free(conf->wps_nfc_dh_privkey);
	wpabuf_free(conf->wps_nfc_dev_pw);
#endif /* CONFIG_WPS */

	os_free(conf->roaming_consortium);
	os_free(conf->venue_name);
	os_free(conf->venue_url);
	os_free(conf->nai_realm_data);
	os_free(conf->network_auth_type);
	os_free(conf->anqp_3gpp_cell_net);
	os_free(conf->domain_name);
	hostapd_config_free_anqp_elem(conf);

#ifdef CONFIG_RADIUS_TEST
	os_free(conf->dump_msk_file);
#endif /* CONFIG_RADIUS_TEST */

#ifdef CONFIG_HS20
	os_free(conf->hs20_oper_friendly_name);
	os_free(conf->hs20_wan_metrics);
	os_free(conf->hs20_connection_capability);
	os_free(conf->hs20_operating_class);
	os_free(conf->hs20_icons);
	if (conf->hs20_osu_providers) {
		for (i = 0; i < conf->hs20_osu_providers_count; i++) {
			struct hs20_osu_provider *p;
			size_t j;
			p = &conf->hs20_osu_providers[i];
			os_free(p->friendly_name);
			os_free(p->server_uri);
			os_free(p->method_list);
			for (j = 0; j < p->icons_count; j++)
				os_free(p->icons[j]);
			os_free(p->icons);
			os_free(p->osu_nai);
			os_free(p->osu_nai2);
			os_free(p->service_desc);
		}
		os_free(conf->hs20_osu_providers);
	}
	if (conf->hs20_operator_icon) {
		for (i = 0; i < conf->hs20_operator_icon_count; i++)
			os_free(conf->hs20_operator_icon[i]);
		os_free(conf->hs20_operator_icon);
	}
	os_free(conf->subscr_remediation_url);
	os_free(conf->hs20_sim_provisioning_url);
	os_free(conf->t_c_filename);
	os_free(conf->t_c_server_url);
#endif /* CONFIG_HS20 */

	wpabuf_free(conf->vendor_elements);
	wpabuf_free(conf->assocresp_elements);

	os_free(conf->sae_groups);
#ifdef CONFIG_OWE
	os_free(conf->owe_groups);
#endif /* CONFIG_OWE */

	os_free(conf->wowlan_triggers);

	os_free(conf->server_id);

#ifdef CONFIG_TESTING_OPTIONS
	wpabuf_free(conf->own_ie_override);
	wpabuf_free(conf->sae_commit_override);
#endif /* CONFIG_TESTING_OPTIONS */

	os_free(conf->no_probe_resp_if_seen_on);
	os_free(conf->no_auth_if_seen_on);

	hostapd_config_free_fils_realms(conf);

#ifdef CONFIG_DPP
	os_free(conf->dpp_connector);
	wpabuf_free(conf->dpp_netaccesskey);
	wpabuf_free(conf->dpp_csign);
#ifdef CONFIG_DPP2
	hostapd_dpp_controller_conf_free(conf->dpp_controller);
#endif /* CONFIG_DPP2 */
#endif /* CONFIG_DPP */

	hostapd_config_free_sae_passwords(conf);

#ifdef CONFIG_AIRTIME_POLICY
	{
		struct airtime_sta_weight *wt, *wt_prev;

		wt = conf->airtime_weight_list;
		conf->airtime_weight_list = NULL;
		while (wt) {
			wt_prev = wt;
			wt = wt->next;
			os_free(wt_prev);
		}
	}
#endif /* CONFIG_AIRTIME_POLICY */

	os_free(conf);
}
void hostapd_config_free(struct hostapd_config *conf)
{
	size_t i;

	if (conf == NULL)
		return;

	for (i = 0; i < conf->num_bss; i++)
		hostapd_config_free_bss(conf->bss[i]);
	os_free(conf->bss);
	os_free(conf->supported_rates);
	os_free(conf->basic_rates);
	os_free(conf->acs_ch_list.range);
	os_free(conf->driver_params);
#ifdef CONFIG_ACS
	os_free(conf->acs_chan_bias);
#endif /* CONFIG_ACS */
	wpabuf_free(conf->lci);
	wpabuf_free(conf->civic);

	os_free(conf);
}
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_AIRTIME_POLICY
#endif /* CONFIG_AIRTIME_POLICY */
