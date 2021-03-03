#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "hostapd.h"
#include "ap_config.h"
#include "sta_info.h"
#include "beacon.h"
#include "ieee802_11.h"
#include "hw_features.h"
#include "ap_drv_ops.h"
void ht40_intolerant_remove(struct hostapd_iface *iface, struct sta_info *sta)
{
	if (!sta->ht40_intolerant_set)
		return;

	sta->ht40_intolerant_set = 0;
	iface->num_sta_ht40_intolerant--;

	if (iface->num_sta_ht40_intolerant == 0 &&
	    (iface->conf->ht_capab & HT_CAP_INFO_SUPP_CHANNEL_WIDTH_SET) &&
	    (iface->drv_flags & WPA_DRIVER_FLAGS_HT_2040_COEX)) {
		unsigned int delay_time = OVERLAPPING_BSS_TRANS_DELAY_FACTOR *
			iface->conf->obss_interval;
		wpa_printf(MSG_DEBUG,
			   "HT: Start 20->40 MHz transition timer (%d seconds)",
			   delay_time);
		eloop_cancel_timeout(ap_ht2040_timeout, iface, NULL);
		eloop_register_timeout(delay_time, 0, ap_ht2040_timeout,
				       iface, NULL);
	}
}
