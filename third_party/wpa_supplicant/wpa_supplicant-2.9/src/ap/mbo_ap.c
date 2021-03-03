#include "utils/includes.h"
#include "utils/common.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "hostapd.h"
#include "sta_info.h"
#include "mbo_ap.h"
void mbo_ap_sta_free(struct sta_info *sta)
{
	struct mbo_non_pref_chan_info *info, *prev;

	info = sta->non_pref_chan;
	sta->non_pref_chan = NULL;
	while (info) {
		prev = info;
		info = info->next;
		os_free(prev);
	}
}
