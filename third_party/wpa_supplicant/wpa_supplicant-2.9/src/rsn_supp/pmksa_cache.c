#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "wpa.h"
#include "wpa_i.h"
#include "pmksa_cache.h"
#if defined(IEEE8021X_EAPOL) && !defined(CONFIG_NO_WPA)
static void _pmksa_cache_free_entry(struct rsn_pmksa_cache_entry *entry)
{
	bin_clear_free(entry, sizeof(*entry));
}
static void pmksa_cache_free_entry(struct rsn_pmksa_cache *pmksa,
				   struct rsn_pmksa_cache_entry *entry,
				   enum pmksa_free_reason reason)
{
	wpa_sm_remove_pmkid(pmksa->sm, entry->network_ctx, entry->aa,
			    entry->pmkid,
			    entry->fils_cache_id_set ? entry->fils_cache_id :
			    NULL);
	pmksa->pmksa_count--;
	pmksa->free_cb(entry, pmksa->ctx, reason);
	_pmksa_cache_free_entry(entry);
}
void pmksa_cache_deinit(struct rsn_pmksa_cache *pmksa)
{
	struct rsn_pmksa_cache_entry *entry, *prev;

	if (pmksa == NULL)
		return;

	entry = pmksa->pmksa;
	pmksa->pmksa = NULL;
	while (entry) {
		prev = entry;
		entry = entry->next;
		os_free(prev);
	}
	pmksa_cache_set_expiration(pmksa);
	os_free(pmksa);
}
#endif /* IEEE8021X_EAPOL */
