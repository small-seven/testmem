#include "includes.h"
#include "common.h"
#include "utils/uuid.h"
#include "utils/ip_addr.h"
#include "common/ieee802_1x_defs.h"
#include "crypto/sha1.h"
#include "rsn_supp/wpa.h"
#include "eap_peer/eap.h"
#include "p2p/p2p.h"
#include "fst/fst.h"
#include "config.h"
#if !defined(CONFIG_CTRL_IFACE) && defined(CONFIG_NO_CONFIG_WRITE)
#define NO_CONFIG_WRITE
#endif
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifdef CONFIG_EXT_PASSWORD
#endif /* CONFIG_EXT_PASSWORD */
#ifndef CONFIG_NO_PBKDF2
#else /* CONFIG_NO_PBKDF2 */
#endif /* CONFIG_NO_PBKDF2 */
#ifndef NO_CONFIG_WRITE
#ifdef CONFIG_EXT_PASSWORD
#endif /* CONFIG_EXT_PASSWORD */
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifndef NO_CONFIG_WRITE
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#endif /* CONFIG_FILS */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#endif /* NO_CONFIG_WRITE */
#ifdef CONFIG_NO_WPA
#else /* CONFIG_NO_WPA */
#endif /* CONFIG_NO_WPA */
#ifndef NO_CONFIG_WRITE
#ifdef CONFIG_NO_WPA
#else /* CONFIG_NO_WPA */
#endif /* CONFIG_NO_WPA */
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifdef IEEE8021X_EAPOL
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifdef CONFIG_EXT_PASSWORD
#endif /* CONFIG_EXT_PASSWORD */
#ifndef NO_CONFIG_WRITE
#ifdef CONFIG_EXT_PASSWORD
#endif /* CONFIG_EXT_PASSWORD */
#endif /* NO_CONFIG_WRITE */
#endif /* IEEE8021X_EAPOL */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifdef CONFIG_P2P
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#endif /* CONFIG_P2P */
#ifdef CONFIG_MESH
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#endif /* CONFIG_MESH */
#ifdef CONFIG_MACSEC
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_OCV
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#endif /* CONFIG_OCV */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifdef OFFSET
#undef OFFSET
#endif /* OFFSET */
#define OFFSET(v) ((void *) &((struct wpa_ssid *) 0)->v)
#ifdef NO_CONFIG_WRITE
#define _STR(f) #f, wpa_config_parse_str, OFFSET(f)
#define _STRe(f) #f, wpa_config_parse_str, OFFSET(eap.f)
#else /* NO_CONFIG_WRITE */
#define _STR(f) #f, wpa_config_parse_str, wpa_config_write_str, OFFSET(f)
#define _STRe(f) #f, wpa_config_parse_str, wpa_config_write_str, OFFSET(eap.f)
#endif /* NO_CONFIG_WRITE */
#define STR(f) _STR(f), NULL, NULL, NULL, 0
#define STRe(f) _STRe(f), NULL, NULL, NULL, 0
#define STR_KEY(f) _STR(f), NULL, NULL, NULL, 1
#define STR_KEYe(f) _STRe(f), NULL, NULL, NULL, 1
#define _STR_LEN(f) _STR(f), OFFSET(f ## _len)
#define _STR_LENe(f) _STRe(f), OFFSET(eap.f ## _len)
#define STR_LEN(f) _STR_LEN(f), NULL, NULL, 0
#define STR_LENe(f) _STR_LENe(f), NULL, NULL, 0
#define STR_LEN_KEY(f) _STR_LEN(f), NULL, NULL, 1
#define _STR_RANGE(f, min, max) _STR_LEN(f), (void *) (min), (void *) (max)
#define STR_RANGE(f, min, max) _STR_RANGE(f, min, max), 0
#define STR_RANGE_KEY(f, min, max) _STR_RANGE(f, min, max), 1
#ifdef NO_CONFIG_WRITE
#define _INT(f) #f, wpa_config_parse_int, OFFSET(f), (void *) 0
#define _INTe(f) #f, wpa_config_parse_int, OFFSET(eap.f), (void *) 0
#else /* NO_CONFIG_WRITE */
#define _INT(f) #f, wpa_config_parse_int, wpa_config_write_int, \
#define _INTe(f) #f, wpa_config_parse_int, wpa_config_write_int, \
#endif /* NO_CONFIG_WRITE */
#define INT(f) _INT(f), NULL, NULL, 0
#define INTe(f) _INTe(f), NULL, NULL, 0
#define INT_RANGE(f, min, max) _INT(f), (void *) (min), (void *) (max), 0
#ifdef NO_CONFIG_WRITE
#define _FUNC(f) #f, wpa_config_parse_ ## f, NULL, NULL, NULL, NULL
#else /* NO_CONFIG_WRITE */
#define _FUNC(f) #f, wpa_config_parse_ ## f, wpa_config_write_ ## f, \
#endif /* NO_CONFIG_WRITE */
#define FUNC(f) _FUNC(f), 0
#define FUNC_KEY(f) _FUNC(f), 1
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_MESH
#else /* CONFIG_MESH */
#endif /* CONFIG_MESH */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#undef OFFSET
#undef _STR
#undef STR
#undef STR_KEY
#undef _STR_LEN
#undef STR_LEN
#undef STR_LEN_KEY
#undef _STR_RANGE
#undef STR_RANGE
#undef STR_RANGE_KEY
#undef _INT
#undef INT
#undef INT_RANGE
#undef _FUNC
#undef FUNC
#undef FUNC_KEY
#define NUM_SSID_FIELDS ARRAY_SIZE(ssid_fields)
#ifdef IEEE8021X_EAPOL
static void eap_peer_config_free(struct eap_peer_config *eap)
{
	os_free(eap->eap_methods);
	bin_clear_free(eap->identity, eap->identity_len);
	os_free(eap->anonymous_identity);
	os_free(eap->imsi_identity);
	bin_clear_free(eap->password, eap->password_len);
	os_free(eap->ca_cert);
	os_free(eap->ca_path);
	os_free(eap->client_cert);
	os_free(eap->private_key);
	str_clear_free(eap->private_key_passwd);
	os_free(eap->dh_file);
	os_free(eap->subject_match);
	os_free(eap->check_cert_subject);
	os_free(eap->altsubject_match);
	os_free(eap->domain_suffix_match);
	os_free(eap->domain_match);
	os_free(eap->ca_cert2);
	os_free(eap->ca_path2);
	os_free(eap->client_cert2);
	os_free(eap->private_key2);
	str_clear_free(eap->private_key2_passwd);
	os_free(eap->dh_file2);
	os_free(eap->subject_match2);
	os_free(eap->check_cert_subject2);
	os_free(eap->altsubject_match2);
	os_free(eap->domain_suffix_match2);
	os_free(eap->domain_match2);
	os_free(eap->phase1);
	os_free(eap->phase2);
	os_free(eap->pcsc);
	str_clear_free(eap->pin);
	os_free(eap->engine_id);
	os_free(eap->key_id);
	os_free(eap->cert_id);
	os_free(eap->ca_cert_id);
	os_free(eap->key2_id);
	os_free(eap->cert2_id);
	os_free(eap->ca_cert2_id);
	str_clear_free(eap->pin2);
	os_free(eap->engine2_id);
	os_free(eap->otp);
	os_free(eap->pending_req_otp);
	os_free(eap->pac_file);
	bin_clear_free(eap->new_password, eap->new_password_len);
	str_clear_free(eap->external_sim_resp);
	os_free(eap->openssl_ciphers);
}
#endif /* IEEE8021X_EAPOL */
void wpa_config_free_ssid(struct wpa_ssid *ssid)
{
	struct psk_list_entry *psk;

	os_free(ssid->ssid);
	str_clear_free(ssid->passphrase);
	os_free(ssid->ext_psk);
	str_clear_free(ssid->sae_password);
	os_free(ssid->sae_password_id);
#ifdef IEEE8021X_EAPOL
	eap_peer_config_free(&ssid->eap);
#endif /* IEEE8021X_EAPOL */
	os_free(ssid->id_str);
	os_free(ssid->scan_freq);
	os_free(ssid->freq_list);
	os_free(ssid->bgscan);
	os_free(ssid->p2p_client_list);
	os_free(ssid->bssid_blacklist);
	os_free(ssid->bssid_whitelist);
#ifdef CONFIG_HT_OVERRIDES
	os_free(ssid->ht_mcs);
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_MESH
	os_free(ssid->mesh_basic_rates);
#endif /* CONFIG_MESH */
#ifdef CONFIG_HS20
	os_free(ssid->roaming_consortium_selection);
#endif /* CONFIG_HS20 */
	os_free(ssid->dpp_connector);
	bin_clear_free(ssid->dpp_netaccesskey, ssid->dpp_netaccesskey_len);
	os_free(ssid->dpp_csign);
	while ((psk = dl_list_first(&ssid->psk_list, struct psk_list_entry,
				    list))) {
		dl_list_del(&psk->list);
		bin_clear_free(psk, sizeof(*psk));
	}
	bin_clear_free(ssid, sizeof(*ssid));
}
void wpa_config_free_cred(struct wpa_cred *cred)
{
	size_t i;

	os_free(cred->realm);
	str_clear_free(cred->username);
	str_clear_free(cred->password);
	os_free(cred->ca_cert);
	os_free(cred->client_cert);
	os_free(cred->private_key);
	str_clear_free(cred->private_key_passwd);
	os_free(cred->imsi);
	str_clear_free(cred->milenage);
	for (i = 0; i < cred->num_domain; i++)
		os_free(cred->domain[i]);
	os_free(cred->domain);
	os_free(cred->domain_suffix_match);
	os_free(cred->eap_method);
	os_free(cred->phase1);
	os_free(cred->phase2);
	os_free(cred->excluded_ssid);
	os_free(cred->roaming_partner);
	os_free(cred->provisioning_sp);
	for (i = 0; i < cred->num_req_conn_capab; i++)
		os_free(cred->req_conn_capab_port[i]);
	os_free(cred->req_conn_capab_port);
	os_free(cred->req_conn_capab_proto);
	os_free(cred);
}
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
void wpa_config_free(struct wpa_config *config)
{
	struct wpa_ssid *ssid, *prev = NULL;
	struct wpa_cred *cred, *cprev;
	int i;

	ssid = config->ssid;
	while (ssid) {
		prev = ssid;
		ssid = ssid->next;
		wpa_config_free_ssid(prev);
	}

	cred = config->cred;
	while (cred) {
		cprev = cred;
		cred = cred->next;
		wpa_config_free_cred(cprev);
	}

	wpa_config_flush_blobs(config);

	wpabuf_free(config->wps_vendor_ext_m1);
	for (i = 0; i < MAX_WPS_VENDOR_EXT; i++)
		wpabuf_free(config->wps_vendor_ext[i]);
	os_free(config->ctrl_interface);
	os_free(config->ctrl_interface_group);
	os_free(config->opensc_engine_path);
	os_free(config->pkcs11_engine_path);
	os_free(config->pkcs11_module_path);
	os_free(config->openssl_ciphers);
	os_free(config->pcsc_reader);
	str_clear_free(config->pcsc_pin);
	os_free(config->driver_param);
	os_free(config->device_name);
	os_free(config->manufacturer);
	os_free(config->model_name);
	os_free(config->model_number);
	os_free(config->serial_number);
	os_free(config->config_methods);
	os_free(config->p2p_ssid_postfix);
	os_free(config->pssid);
	os_free(config->p2p_pref_chan);
	os_free(config->p2p_no_go_freq.range);
	os_free(config->autoscan);
	os_free(config->freq_list);
	wpabuf_free(config->wps_nfc_dh_pubkey);
	wpabuf_free(config->wps_nfc_dh_privkey);
	wpabuf_free(config->wps_nfc_dev_pw);
	os_free(config->ext_password_backend);
	os_free(config->sae_groups);
	wpabuf_free(config->ap_vendor_elements);
	os_free(config->osu_dir);
	os_free(config->bgscan);
	os_free(config->wowlan_triggers);
	os_free(config->fst_group_id);
	os_free(config->sched_scan_plans);
#ifdef CONFIG_MBO
	os_free(config->non_pref_chan);
#endif /* CONFIG_MBO */

	os_free(config);
}
int wpa_config_remove_network(struct wpa_config *config, int id)
{
	struct wpa_ssid *ssid, *prev = NULL;

	ssid = config->ssid;
	while (ssid) {
		if (id == ssid->id)
			break;
		prev = ssid;
		ssid = ssid->next;
	}

	if (ssid == NULL)
		return -1;

	if (prev)
		prev->next = ssid->next;
	else
		config->ssid = ssid->next;

	wpa_config_update_prio_list(config);
	wpa_config_free_ssid(ssid);
	return 0;
}
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef NO_CONFIG_WRITE
#else /* NO_CONFIG_WRITE */
#endif /* NO_CONFIG_WRITE */
#ifndef NO_CONFIG_WRITE
#endif /* NO_CONFIG_WRITE */
#ifndef CONFIG_NO_PBKDF2
#endif /* CONFIG_NO_PBKDF2 */
static char * alloc_int_str(int val)
{
	const unsigned int bufsize = 20;
	char *buf;
	int res;

	buf = os_malloc(bufsize);
	if (buf == NULL)
		return NULL;
	res = os_snprintf(buf, bufsize, "%d", val);
	if (os_snprintf_error(bufsize, res)) {
		os_free(buf);
		buf = NULL;
	}
	return buf;
}
static char * alloc_strdup(const char *str)
{
	if (str == NULL)
		return NULL;
	return os_strdup(str);
}
int wpa_config_remove_cred(struct wpa_config *config, int id)
{
	struct wpa_cred *cred, *prev = NULL;

	cred = config->cred;
	while (cred) {
		if (id == cred->id)
			break;
		prev = cred;
		cred = cred->next;
	}

	if (cred == NULL)
		return -1;

	if (prev)
		prev->next = cred->next;
	else
		config->cred = cred->next;

	wpa_config_free_cred(cred);
	return 0;
}
#ifndef CONFIG_NO_CONFIG_BLOBS
void wpa_config_free_blob(struct wpa_config_blob *blob)
{
	if (blob) {
		os_free(blob->name);
		bin_clear_free(blob->data, blob->len);
		os_free(blob);
	}
}
int wpa_config_remove_blob(struct wpa_config *config, const char *name)
{
	struct wpa_config_blob *pos = config->blobs, *prev = NULL;

	while (pos) {
		if (os_strcmp(pos->name, name) == 0) {
			if (prev)
				prev->next = pos->next;
			else
				config->blobs = pos->next;
			wpa_config_free_blob(pos);
			return 0;
		}
		prev = pos;
		pos = pos->next;
	}

	return -1;
}
#endif /* CONFIG_NO_CONFIG_BLOBS */
struct wpa_config * wpa_config_alloc_empty(const char *ctrl_interface,
					   const char *driver_param)
{
	struct wpa_config *config;
	const int aCWmin = 4, aCWmax = 10;
	const struct hostapd_wmm_ac_params ac_bk =
		{ aCWmin, aCWmax, 7, 0, 0 }; /* background traffic */
	const struct hostapd_wmm_ac_params ac_be =
		{ aCWmin, aCWmax, 3, 0, 0 }; /* best effort traffic */
	const struct hostapd_wmm_ac_params ac_vi = /* video traffic */
		{ aCWmin - 1, aCWmin, 2, 3000 / 32, 0 };
	const struct hostapd_wmm_ac_params ac_vo = /* voice traffic */
		{ aCWmin - 2, aCWmin - 1, 2, 1500 / 32, 0 };

	config = os_zalloc(sizeof(*config));
	if (config == NULL)
		return NULL;
	config->eapol_version = DEFAULT_EAPOL_VERSION;
	config->ap_scan = DEFAULT_AP_SCAN;
	config->user_mpm = DEFAULT_USER_MPM;
	config->max_peer_links = DEFAULT_MAX_PEER_LINKS;
	config->mesh_max_inactivity = DEFAULT_MESH_MAX_INACTIVITY;
	config->dot11RSNASAERetransPeriod =
		DEFAULT_DOT11_RSNA_SAE_RETRANS_PERIOD;
	config->fast_reauth = DEFAULT_FAST_REAUTH;
	config->p2p_go_intent = DEFAULT_P2P_GO_INTENT;
	config->p2p_intra_bss = DEFAULT_P2P_INTRA_BSS;
	config->p2p_go_freq_change_policy = DEFAULT_P2P_GO_FREQ_MOVE;
	config->p2p_go_max_inactivity = DEFAULT_P2P_GO_MAX_INACTIVITY;
	config->p2p_optimize_listen_chan = DEFAULT_P2P_OPTIMIZE_LISTEN_CHAN;
	config->p2p_go_ctwindow = DEFAULT_P2P_GO_CTWINDOW;
	config->bss_max_count = DEFAULT_BSS_MAX_COUNT;
	config->bss_expiration_age = DEFAULT_BSS_EXPIRATION_AGE;
	config->bss_expiration_scan_count = DEFAULT_BSS_EXPIRATION_SCAN_COUNT;
	config->max_num_sta = DEFAULT_MAX_NUM_STA;
	config->ap_isolate = DEFAULT_AP_ISOLATE;
	config->access_network_type = DEFAULT_ACCESS_NETWORK_TYPE;
	config->scan_cur_freq = DEFAULT_SCAN_CUR_FREQ;
	config->wmm_ac_params[0] = ac_be;
	config->wmm_ac_params[1] = ac_bk;
	config->wmm_ac_params[2] = ac_vi;
	config->wmm_ac_params[3] = ac_vo;
	config->p2p_search_delay = DEFAULT_P2P_SEARCH_DELAY;
	config->rand_addr_lifetime = DEFAULT_RAND_ADDR_LIFETIME;
	config->key_mgmt_offload = DEFAULT_KEY_MGMT_OFFLOAD;
	config->cert_in_cb = DEFAULT_CERT_IN_CB;
	config->wpa_rsc_relaxation = DEFAULT_WPA_RSC_RELAXATION;

#ifdef CONFIG_MBO
	config->mbo_cell_capa = DEFAULT_MBO_CELL_CAPA;
	config->disassoc_imminent_rssi_threshold =
		DEFAULT_DISASSOC_IMMINENT_RSSI_THRESHOLD;
	config->oce = DEFAULT_OCE_SUPPORT;
#endif /* CONFIG_MBO */

	if (ctrl_interface)
		config->ctrl_interface = os_strdup(ctrl_interface);
	if (driver_param)
		config->driver_param = os_strdup(driver_param);
	config->gas_rand_addr_lifetime = DEFAULT_RAND_ADDR_LIFETIME;

	return config;
}
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef OFFSET
#undef OFFSET
#endif /* OFFSET */
#define OFFSET(v) ((void *) &((struct wpa_config *) 0)->v)
#define FUNC(f) #f, wpa_config_process_ ## f, NULL, OFFSET(f), NULL, NULL
#define FUNC_NO_VAR(f) #f, wpa_config_process_ ## f, NULL, NULL, NULL, NULL
#define _INT(f) #f, wpa_global_config_parse_int, wpa_config_get_int, OFFSET(f)
#define INT(f) _INT(f), NULL, NULL
#define INT_RANGE(f, min, max) _INT(f), (void *) min, (void *) max
#define _STR(f) #f, wpa_global_config_parse_str, wpa_config_get_str, OFFSET(f)
#define STR(f) _STR(f), NULL, NULL
#define STR_RANGE(f, min, max) _STR(f), (void *) min, (void *) max
#define BIN(f) #f, wpa_global_config_parse_bin, NULL, OFFSET(f), NULL, NULL
#define IPV4(f) #f, wpa_global_config_parse_ipv4, wpa_config_get_ipv4,  \
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#ifdef CONFIG_MACSEC
#else /* CONFIG_MACSEC */
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#undef FUNC
#undef _INT
#undef INT
#undef INT_RANGE
#undef _STR
#undef STR
#undef STR_RANGE
#undef BIN
#undef IPV4
#define NUM_GLOBAL_FIELDS ARRAY_SIZE(global_fields)
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
