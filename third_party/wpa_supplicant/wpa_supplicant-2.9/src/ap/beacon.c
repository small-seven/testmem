#include "utils/includes.h"
#ifndef CONFIG_NATIVE_WINDOWS
#include "utils/common.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/hw_features_common.h"
#include "common/wpa_ctrl.h"
#include "wps/wps_defs.h"
#include "p2p/p2p.h"
#include "hostapd.h"
#include "ieee802_11.h"
#include "wpa_auth.h"
#include "wmm.h"
#include "ap_config.h"
#include "sta_info.h"
#include "p2p_hostapd.h"
#include "ap_drv_ops.h"
#include "beacon.h"
#include "hs20.h"
#include "dfs.h"
#include "taxonomy.h"
#include "ieee802_11_auth.h"
#ifdef NEED_AP_MLME
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#define MAX_PROBERESP_LEN 768
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P_MANAGER
#endif /* CONFIG_P2P_MANAGER */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_TAXONOMY
#endif /* CONFIG_TAXONOMY */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_TAXONOMY
#endif /* CONFIG_TAXONOMY */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif  /* CONFIG_P2P */
#endif /* NEED_AP_MLME */
#ifdef CONFIG_TAXONOMY
#endif /* CONFIG_TAXONOMY */
#ifdef NEED_AP_MLME
#define BEACON_HEAD_BUF_SIZE 256
#define BEACON_TAIL_BUF_SIZE 512
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P_MANAGER
#endif /* CONFIG_P2P_MANAGER */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#endif /* NEED_AP_MLME */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
void ieee802_11_free_ap_params(struct wpa_driver_ap_params *params)
{
	os_free(params->tail);
	params->tail = NULL;
	os_free(params->head);
	params->head = NULL;
	os_free(params->proberesp);
	params->proberesp = NULL;
}
#endif /* CONFIG_NATIVE_WINDOWS */
