#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "radius/radius.h"
#include "drivers/driver.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/wpa_ctrl.h"
#include "common/dpp.h"
#include "crypto/random.h"
#include "p2p/p2p.h"
#include "wps/wps.h"
#include "fst/fst.h"
#include "wnm_ap.h"
#include "hostapd.h"
#include "ieee802_11.h"
#include "ieee802_11_auth.h"
#include "sta_info.h"
#include "accounting.h"
#include "tkip_countermeasures.h"
#include "ieee802_1x.h"
#include "wpa_auth.h"
#include "wps_hostapd.h"
#include "ap_drv_ops.h"
#include "ap_config.h"
#include "ap_mlme.h"
#include "hw_features.h"
#include "dfs.h"
#include "beacon.h"
#include "mbo_ap.h"
#include "dpp_hostapd.h"
#include "fils_hlp.h"
#include "neighbor_db.h"
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#if defined(CONFIG_IEEE80211R_AP) || defined(CONFIG_IEEE80211W) || defined(CONFIG_FILS) || defined(CONFIG_OWE)
#endif /* CONFIG_IEEE80211R_AP || CONFIG_IEEE80211W || CONFIG_FILS || CONFIG_OWE */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IEEE80211N
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_WPS
#ifdef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#endif /* CONFIG_WPS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#if defined(CONFIG_IEEE80211R_AP) || defined(CONFIG_FILS) || defined(CONFIG_OWE)
#else /* CONFIG_IEEE80211R_AP || CONFIG_FILS */
#endif /* CONFIG_IEEE80211R_AP || CONFIG_FILS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifdef HOSTAPD
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifndef NEED_AP_MLME
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WNM_AP
#endif /* CONFIG_WNM_AP */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#endif /* NEED_AP_MLME */
#ifdef NEED_AP_MLME
#define HAPD_BROADCAST ((struct hostapd_data *) -1)
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* NEED_AP_MLME */
#endif /* HOSTAPD */
#ifdef HOSTAPD
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef NEED_AP_MLME
#else /* NEED_AP_MLME */
#endif /* NEED_AP_MLME */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#endif /* HOSTAPD */
