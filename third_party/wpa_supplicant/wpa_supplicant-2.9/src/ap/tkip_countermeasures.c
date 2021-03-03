#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "radius/radius.h"
#include "hostapd.h"
#include "sta_info.h"
#include "ap_mlme.h"
#include "wpa_auth.h"
#include "ap_drv_ops.h"
#include "tkip_countermeasures.h"
void ieee80211_tkip_countermeasures_deinit(struct hostapd_data *hapd)
{
	eloop_cancel_timeout(ieee80211_tkip_countermeasures_stop, hapd, NULL);
}
