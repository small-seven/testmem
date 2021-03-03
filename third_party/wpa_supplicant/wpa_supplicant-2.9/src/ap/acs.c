#include "utils/includes.h"
#include <math.h>
#include "utils/common.h"
#include "utils/list.h"
#include "common/ieee802_11_defs.h"
#include "common/hw_features_common.h"
#include "common/wpa_ctrl.h"
#include "drivers/driver.h"
#include "hostapd.h"
#include "ap_drv_ops.h"
#include "ap_config.h"
#include "hw_features.h"
#include "acs.h"
void acs_cleanup(struct hostapd_iface *iface)
{
	int i;
	struct hostapd_channel_data *chan;

	for (i = 0; i < iface->current_mode->num_channels; i++) {
		chan = &iface->current_mode->channels[i];

		if (chan->flag & HOSTAPD_CHAN_SURVEY_LIST_INITIALIZED)
			acs_clean_chan_surveys(chan);

		dl_list_init(&chan->survey_list);
		chan->flag |= HOSTAPD_CHAN_SURVEY_LIST_INITIALIZED;
		chan->min_nf = 0;
	}

	iface->chans_surveyed = 0;
	iface->acs_num_completed_scans = 0;
}
#ifndef ACS_ADJ_WEIGHT
#define ACS_ADJ_WEIGHT 0.85
#endif /* ACS_ADJ_WEIGHT */
#ifndef ACS_NEXT_ADJ_WEIGHT
#define ACS_NEXT_ADJ_WEIGHT 0.55
#endif /* ACS_NEXT_ADJ_WEIGHT */
#ifndef ACS_24GHZ_PREFER_1_6_11
#define ACS_24GHZ_PREFER_1_6_11 0.8
#endif /* ACS_24GHZ_PREFER_1_6_11 */
