#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "hostapd.h"
#include "ap_drv_ops.h"
#include "sta_info.h"
#include "airtime_policy.h"
void airtime_policy_update_deinit(struct hostapd_iface *iface)
{
	eloop_cancel_timeout(update_airtime_weights, iface, NULL);
}
