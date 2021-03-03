#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "crypto/sha256.h"
#include "crypto/random.h"
#include "crypto/aes.h"
#include "crypto/aes_siv.h"
#include "rsn_supp/wpa.h"
#include "ap/hostapd.h"
#include "ap/wpa_auth.h"
#include "ap/sta_info.h"
#include "ap/ieee802_11.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "wpas_glue.h"
#include "mesh_mpm.h"
#include "mesh_rsn.h"
#define MESH_AUTH_TIMEOUT 10
#define MESH_AUTH_RETRY 3
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
