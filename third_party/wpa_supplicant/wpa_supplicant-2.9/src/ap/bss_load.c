#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "hostapd.h"
#include "bss_load.h"
#include "ap_drv_ops.h"
#include "beacon.h"
void bss_load_update_deinit(struct hostapd_data *hapd)
{
	eloop_cancel_timeout(update_channel_utilization, hapd, NULL);
}
