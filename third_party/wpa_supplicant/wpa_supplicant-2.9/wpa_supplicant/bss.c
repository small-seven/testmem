#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "drivers/driver.h"
#include "eap_peer/eap.h"
#include "wpa_supplicant_i.h"
#include "config.h"
#include "notify.h"
#include "scan.h"
#include "bss.h"
#define WPA_BSS_FREQ_CHANGED_FLAG	BIT(0)
#define WPA_BSS_SIGNAL_CHANGED_FLAG	BIT(1)
#define WPA_BSS_PRIVACY_CHANGED_FLAG	BIT(2)
#define WPA_BSS_MODE_CHANGED_FLAG	BIT(3)
#define WPA_BSS_WPAIE_CHANGED_FLAG	BIT(4)
#define WPA_BSS_RSNIE_CHANGED_FLAG	BIT(5)
#define WPA_BSS_WPS_CHANGED_FLAG	BIT(6)
#define WPA_BSS_RATES_CHANGED_FLAG	BIT(7)
#define WPA_BSS_IES_CHANGED_FLAG	BIT(8)
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
struct wpa_bss_anqp * wpa_bss_anqp_alloc(void)
{
	struct wpa_bss_anqp *anqp;
	anqp = os_zalloc(sizeof(*anqp));
	if (anqp == NULL)
		return NULL;
#ifdef CONFIG_INTERWORKING
	dl_list_init(&anqp->anqp_elems);
#endif /* CONFIG_INTERWORKING */
	anqp->users = 1;
	return anqp;
}
#define ANQP_DUP(f) if (anqp->f) n->f = wpabuf_dup(anqp->f)
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#undef ANQP_DUP
int wpa_bss_anqp_unshare_alloc(struct wpa_bss *bss)
{
	struct wpa_bss_anqp *anqp;

	if (bss->anqp && bss->anqp->users > 1) {
		/* allocated, but shared - clone an unshared copy */
		anqp = wpa_bss_anqp_clone(bss->anqp);
		if (anqp == NULL)
			return -1;
		anqp->users = 1;
		bss->anqp->users--;
		bss->anqp = anqp;
		return 0;
	}

	if (bss->anqp)
		return 0; /* already allocated and not shared */

	/* not allocated - allocate a new storage area */
	bss->anqp = wpa_bss_anqp_alloc();
	return bss->anqp ? 0 : -1;
}
static void wpa_bss_anqp_free(struct wpa_bss_anqp *anqp)
{
#ifdef CONFIG_INTERWORKING
	struct wpa_bss_anqp_elem *elem;
#endif /* CONFIG_INTERWORKING */

	if (anqp == NULL)
		return;

	anqp->users--;
	if (anqp->users > 0) {
		/* Another BSS entry holds a pointer to this ANQP info */
		return;
	}

#ifdef CONFIG_INTERWORKING
	wpabuf_free(anqp->capability_list);
	wpabuf_free(anqp->venue_name);
	wpabuf_free(anqp->network_auth_type);
	wpabuf_free(anqp->roaming_consortium);
	wpabuf_free(anqp->ip_addr_type_availability);
	wpabuf_free(anqp->nai_realm);
	wpabuf_free(anqp->anqp_3gpp);
	wpabuf_free(anqp->domain_name);
	wpabuf_free(anqp->fils_realm_info);

	while ((elem = dl_list_first(&anqp->anqp_elems,
				     struct wpa_bss_anqp_elem, list))) {
		dl_list_del(&elem->list);
		wpabuf_free(elem->payload);
		os_free(elem);
	}
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
	wpabuf_free(anqp->hs20_capability_list);
	wpabuf_free(anqp->hs20_operator_friendly_name);
	wpabuf_free(anqp->hs20_wan_metrics);
	wpabuf_free(anqp->hs20_connection_capability);
	wpabuf_free(anqp->hs20_operating_class);
	wpabuf_free(anqp->hs20_osu_providers_list);
	wpabuf_free(anqp->hs20_operator_icon_metadata);
	wpabuf_free(anqp->hs20_osu_providers_nai_list);
#endif /* CONFIG_HS20 */

	os_free(anqp);
}
void wpa_bss_remove(struct wpa_supplicant *wpa_s, struct wpa_bss *bss,
		    const char *reason)
{
	if (wpa_s->last_scan_res) {
		unsigned int i;
		for (i = 0; i < wpa_s->last_scan_res_used; i++) {
			if (wpa_s->last_scan_res[i] == bss) {
				os_memmove(&wpa_s->last_scan_res[i],
					   &wpa_s->last_scan_res[i + 1],
					   (wpa_s->last_scan_res_used - i - 1)
					   * sizeof(struct wpa_bss *));
				wpa_s->last_scan_res_used--;
				break;
			}
		}
	}
	wpa_bss_update_pending_connect(wpa_s, bss, NULL);
	dl_list_del(&bss->list);
	dl_list_del(&bss->list_id);
	wpa_s->num_bss--;
	wpa_dbg(wpa_s, MSG_DEBUG, "BSS: Remove id %u BSSID " MACSTR
		" SSID '%s' due to %s", bss->id, MAC2STR(bss->bssid),
		wpa_ssid_txt(bss->ssid, bss->ssid_len), reason);
	wpas_notify_bss_removed(wpa_s, bss->bssid, bss->id);
	wpa_bss_anqp_free(bss->anqp);
	os_free(bss);
}
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
static int wpa_bss_remove_oldest_unknown(struct wpa_supplicant *wpa_s)
{
	struct wpa_bss *bss;

	dl_list_for_each(bss, &wpa_s->bss, struct wpa_bss, list) {
		if (!wpa_bss_known(wpa_s, bss) &&
		    !wpa_bss_is_wps_candidate(wpa_s, bss)) {
			wpa_bss_remove(wpa_s, bss, __func__);
			return 0;
		}
	}

	return -1;
}
static int wpa_bss_remove_oldest(struct wpa_supplicant *wpa_s)
{
	struct wpa_bss *bss;

	/*
	 * Remove the oldest entry that does not match with any configured
	 * network.
	 */
	if (wpa_bss_remove_oldest_unknown(wpa_s) == 0)
		return 0;

	/*
	 * Remove the oldest entry that isn't currently in use.
	 */
	dl_list_for_each(bss, &wpa_s->bss, struct wpa_bss, list) {
		if (!wpa_bss_in_use(wpa_s, bss)) {
			wpa_bss_remove(wpa_s, bss, __func__);
			return 0;
		}
	}

	return -1;
}
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
void wpa_bss_deinit(struct wpa_supplicant *wpa_s)
{
	wpa_bss_flush(wpa_s);
}
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
