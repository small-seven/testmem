#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/wpa_ctrl.h"
#include "common/hw_features_common.h"
#include "hostapd.h"
#include "ap_config.h"
#include "ap_drv_ops.h"
#include "acs.h"
#include "ieee802_11.h"
#include "beacon.h"
#include "hw_features.h"
void hostapd_free_hw_features(struct hostapd_hw_modes *hw_features,
			      size_t num_hw_features)
{
	size_t i;

	if (hw_features == NULL)
		return;

	for (i = 0; i < num_hw_features; i++) {
		os_free(hw_features[i].channels);
		os_free(hw_features[i].rates);
	}

	os_free(hw_features);
}
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_IEEE80211N
#define HT2040_COEX_SCAN_RETRY 15
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211N
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#endif /* CONFIG_IEEE80211N */
