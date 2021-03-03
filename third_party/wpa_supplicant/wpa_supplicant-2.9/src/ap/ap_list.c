#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "hostapd.h"
#include "ap_config.h"
#include "ieee802_11.h"
#include "sta_info.h"
#include "beacon.h"
#include "ap_list.h"
static void ap_free_ap(struct hostapd_iface *iface, struct ap_info *ap)
{
	ap_ap_hash_del(iface, ap);
	ap_ap_list_del(iface, ap);

	iface->num_ap--;
	os_free(ap);
}
static void hostapd_free_aps(struct hostapd_iface *iface)
{
	struct ap_info *ap, *prev;

	ap = iface->ap_list;

	while (ap) {
		prev = ap;
		ap = ap->next;
		ap_free_ap(iface, prev);
	}

	iface->ap_list = NULL;
}
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
void ap_list_deinit(struct hostapd_iface *iface)
{
	hostapd_free_aps(iface);
}
