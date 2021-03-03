#include "utils/includes.h"
#include "utils/common.h"
#include "hostapd.h"
#include "ieee802_11.h"
#include "neighbor_db.h"
int hostapd_neighbor_remove(struct hostapd_data *hapd, const u8 *bssid,
			    const struct wpa_ssid_value *ssid)
{
	struct hostapd_neighbor_entry *nr;

	nr = hostapd_neighbor_get(hapd, bssid, ssid);
	if (!nr)
		return -1;

	hostapd_neighbor_clear_entry(nr);
	dl_list_del(&nr->list);
	os_free(nr);

	return 0;
}
void hostapd_free_neighbor_db(struct hostapd_data *hapd)
{
	struct hostapd_neighbor_entry *nr, *prev;

	dl_list_for_each_safe(nr, prev, &hapd->nr_db,
			      struct hostapd_neighbor_entry, list) {
		hostapd_neighbor_clear_entry(nr);
		dl_list_del(&nr->list);
		os_free(nr);
	}
}
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
