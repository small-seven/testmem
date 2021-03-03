#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "common/ocv.h"
#include "ap/hostapd.h"
#include "ap/sta_info.h"
#include "ap/ap_config.h"
#include "ap/ap_drv_ops.h"
#include "ap/wpa_auth.h"
#include "mbo_ap.h"
#include "wnm_ap.h"
#define MAX_TFS_IE_LEN  1024
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#define MAX_GTK_SUBELEM_LEN 45
#define MAX_IGTK_SUBELEM_LEN 26
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#undef MAX_GTK_SUBELEM_LEN
#undef MAX_IGTK_SUBELEM_LEN
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
