#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "eapol_auth/eapol_auth_sm.h"
#include "eapol_auth/eapol_auth_sm_i.h"
#include "radius/radius_das.h"
#include "sta_info.h"
#include "ap_config.h"
#include "pmksa_cache_auth.h"
#define PMKID_HASH_SIZE 128
#define PMKID_HASH(pmkid) (unsigned int) ((pmkid)[0] & 0x7f)
static void _pmksa_cache_free_entry(struct rsn_pmksa_cache_entry *entry)
{
	os_free(entry->vlan_desc);
	os_free(entry->identity);
	wpabuf_free(entry->cui);
#ifndef CONFIG_NO_RADIUS
	radius_free_class(&entry->radius_class);
#endif /* CONFIG_NO_RADIUS */
	bin_clear_free(entry, sizeof(*entry));
}
void pmksa_cache_free_entry(struct rsn_pmksa_cache *pmksa,
			    struct rsn_pmksa_cache_entry *entry)
{
	struct rsn_pmksa_cache_entry *pos, *prev;
	unsigned int hash;

	pmksa->pmksa_count--;
	pmksa->free_cb(entry, pmksa->ctx);

	/* unlink from hash list */
	hash = PMKID_HASH(entry->pmkid);
	pos = pmksa->pmkid[hash];
	prev = NULL;
	while (pos) {
		if (pos == entry) {
			if (prev != NULL)
				prev->hnext = entry->hnext;
			else
				pmksa->pmkid[hash] = entry->hnext;
			break;
		}
		prev = pos;
		pos = pos->hnext;
	}

	/* unlink from entry list */
	pos = pmksa->pmksa;
	prev = NULL;
	while (pos) {
		if (pos == entry) {
			if (prev != NULL)
				prev->next = entry->next;
			else
				pmksa->pmksa = entry->next;
			break;
		}
		prev = pos;
		pos = pos->next;
	}

	_pmksa_cache_free_entry(entry);
}
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifndef CONFIG_NO_VLAN
#endif /* CONFIG_NO_VLAN */
pmksa_cache_auth_create_entry(const u8 *pmk, size_t pmk_len, const u8 *pmkid,
			      const u8 *kck, size_t kck_len, const u8 *aa,
			      const u8 *spa, int session_timeout,
			      struct eapol_state_machine *eapol, int akmp)
{
	struct rsn_pmksa_cache_entry *entry;
	struct os_reltime now;

	if (pmk_len > PMK_LEN_MAX)
		return NULL;

	if (wpa_key_mgmt_suite_b(akmp) && !kck)
		return NULL;

	entry = os_zalloc(sizeof(*entry));
	if (entry == NULL)
		return NULL;
	os_memcpy(entry->pmk, pmk, pmk_len);
	entry->pmk_len = pmk_len;
	if (pmkid)
		os_memcpy(entry->pmkid, pmkid, PMKID_LEN);
	else if (akmp == WPA_KEY_MGMT_IEEE8021X_SUITE_B_192)
		rsn_pmkid_suite_b_192(kck, kck_len, aa, spa, entry->pmkid);
	else if (wpa_key_mgmt_suite_b(akmp))
		rsn_pmkid_suite_b(kck, kck_len, aa, spa, entry->pmkid);
	else
		rsn_pmkid(pmk, pmk_len, aa, spa, entry->pmkid, akmp);
	os_get_reltime(&now);
	entry->expiration = now.sec;
	if (session_timeout > 0)
		entry->expiration += session_timeout;
	else
		entry->expiration += dot11RSNAConfigPMKLifetime;
	entry->akmp = akmp;
	os_memcpy(entry->spa, spa, ETH_ALEN);
	pmksa_cache_from_eapol_data(entry, eapol);

	return entry;
}
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
void pmksa_cache_auth_deinit(struct rsn_pmksa_cache *pmksa)
{
	struct rsn_pmksa_cache_entry *entry, *prev;
	int i;

	if (pmksa == NULL)
		return;

	entry = pmksa->pmksa;
	while (entry) {
		prev = entry;
		entry = entry->next;
		_pmksa_cache_free_entry(prev);
	}
	eloop_cancel_timeout(pmksa_cache_expire, pmksa, NULL);
	pmksa->pmksa_count = 0;
	pmksa->pmksa = NULL;
	for (i = 0; i < PMKID_HASH_SIZE; i++)
		pmksa->pmkid[i] = NULL;
	os_free(pmksa);
}
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
