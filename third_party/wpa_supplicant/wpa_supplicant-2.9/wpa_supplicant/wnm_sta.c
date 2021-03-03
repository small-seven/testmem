#include "utils/includes.h"
#include "utils/common.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/wpa_ctrl.h"
#include "common/ocv.h"
#include "rsn_supp/wpa.h"
#include "config.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "scan.h"
#include "ctrl_iface.h"
#include "bss.h"
#include "wnm_sta.h"
#include "notify.h"
#include "hs20_supplicant.h"
#define MAX_TFS_IE_LEN  1024
#define WNM_MAX_NEIGHBOR_REPORT 10
#define WNM_SCAN_RESULT_AGE 2 /* 2 seconds */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_MBO
#else /* CONFIG_MBO */
#endif /* CONFIG_MBO */
#define BTM_RESP_MIN_SIZE	5 + ETH_ALEN
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#if defined(CONFIG_MBO) && defined(CONFIG_TESTING_OPTIONS)
#endif /* CONFIG_MBO && CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#define BTM_QUERY_MIN_SIZE	4
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
