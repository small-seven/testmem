#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "radius/radius.h"
#include "radius/radius_client.h"
#include "hostapd.h"
#include "ap_config.h"
#include "ap_drv_ops.h"
#include "ieee802_11.h"
#include "ieee802_1x.h"
#include "ieee802_11_auth.h"
#define RADIUS_ACL_TIMEOUT 30
#ifndef CONFIG_NO_RADIUS
static void hostapd_acl_cache_free_entry(struct hostapd_cached_radius_acl *e)
{
	os_free(e->identity);
	os_free(e->radius_cui);
	hostapd_free_psk_list(e->psk);
	os_free(e);
}
static void hostapd_acl_cache_free(struct hostapd_cached_radius_acl *acl_cache)
{
	struct hostapd_cached_radius_acl *prev;

	while (acl_cache) {
		prev = acl_cache;
		acl_cache = acl_cache->next;
		hostapd_acl_cache_free_entry(prev);
	}
}
#endif /* CONFIG_NO_RADIUS */
static void hostapd_acl_query_free(struct hostapd_acl_query_data *query)
{
	if (query == NULL)
		return;
	os_free(query->auth_msg);
	os_free(query);
}
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_NO_RADIUS
#else /* CONFIG_NO_RADIUS */
#endif /* CONFIG_NO_RADIUS */
#ifndef CONFIG_NO_RADIUS
#ifdef CONFIG_DRIVER_RADIUS_ACL
#else /* CONFIG_DRIVER_RADIUS_ACL */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#endif /* CONFIG_DRIVER_RADIUS_ACL */
#endif /* CONFIG_NO_RADIUS */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
void hostapd_acl_deinit(struct hostapd_data *hapd)
{
	struct hostapd_acl_query_data *query, *prev;

#ifndef CONFIG_NO_RADIUS
	hostapd_acl_cache_free(hapd->acl_cache);
	hapd->acl_cache = NULL;
#endif /* CONFIG_NO_RADIUS */

	query = hapd->acl_queries;
	hapd->acl_queries = NULL;
	while (query) {
		prev = query;
		query = query->next;
		hostapd_acl_query_free(prev);
	}
}
void hostapd_free_psk_list(struct hostapd_sta_wpa_psk_short *psk)
{
	if (psk && psk->ref) {
		/* This will be freed when the last reference is dropped. */
		psk->ref--;
		return;
	}

	while (psk) {
		struct hostapd_sta_wpa_psk_short *prev = psk;
		psk = psk->next;
		os_free(prev);
	}
}
