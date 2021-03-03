#include "includes.h"
#include "common.h"
#include "wpa.h"
#include "eloop.h"
#include "l2_packet/l2_packet.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "preauth.h"
#include "pmksa_cache.h"
#include "wpa_i.h"
#if defined(IEEE8021X_EAPOL) && !defined(CONFIG_NO_WPA)
#define PMKID_CANDIDATE_PRIO_SCAN 1000
void pmksa_candidate_free(struct wpa_sm *sm)
{
	struct rsn_pmksa_candidate *entry, *n;

	if (sm == NULL)
		return;

	dl_list_for_each_safe(entry, n, &sm->pmksa_candidates,
			      struct rsn_pmksa_candidate, list) {
		dl_list_del(&entry->list);
		os_free(entry);
	}
}
void rsn_preauth_deinit(struct wpa_sm *sm)
{
	if (sm == NULL || !sm->preauth_eapol)
		return;

	eloop_cancel_timeout(rsn_preauth_timeout, sm, NULL);
	eapol_sm_deinit(sm->preauth_eapol);
	sm->preauth_eapol = NULL;
	os_memset(sm->preauth_bssid, 0, ETH_ALEN);

	l2_packet_deinit(sm->l2_preauth);
	sm->l2_preauth = NULL;
	if (sm->l2_preauth_br) {
		l2_packet_deinit(sm->l2_preauth_br);
		sm->l2_preauth_br = NULL;
	}
}
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#endif /* IEEE8021X_EAPOL && !CONFIG_NO_WPA */
