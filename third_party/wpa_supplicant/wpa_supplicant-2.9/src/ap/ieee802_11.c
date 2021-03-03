#include "utils/includes.h"
#ifndef CONFIG_NATIVE_WINDOWS
#include "utils/common.h"
#include "utils/eloop.h"
#include "crypto/crypto.h"
#include "crypto/sha256.h"
#include "crypto/sha384.h"
#include "crypto/sha512.h"
#include "crypto/random.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/wpa_ctrl.h"
#include "common/sae.h"
#include "common/dpp.h"
#include "common/ocv.h"
#include "common/wpa_common.h"
#include "radius/radius.h"
#include "radius/radius_client.h"
#include "p2p/p2p.h"
#include "wps/wps.h"
#include "fst/fst.h"
#include "hostapd.h"
#include "beacon.h"
#include "ieee802_11_auth.h"
#include "sta_info.h"
#include "ieee802_1x.h"
#include "wpa_auth.h"
#include "pmksa_cache_auth.h"
#include "wmm.h"
#include "ap_list.h"
#include "accounting.h"
#include "ap_config.h"
#include "ap_mlme.h"
#include "p2p_hostapd.h"
#include "ap_drv_ops.h"
#include "wnm_ap.h"
#include "hw_features.h"
#include "ieee802_11.h"
#include "dfs.h"
#include "mbo_ap.h"
#include "rrm.h"
#include "taxonomy.h"
#include "fils_hlp.h"
#include "dpp_hostapd.h"
#include "gas_query_ap.h"
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifndef CONFIG_NO_RC4
#endif /* CONFIG_NO_RC4 */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_SAE
#ifndef CONFIG_NO_VLAN
#endif /* CONFIG_NO_VLAN */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_SAE */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_FILS
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#ifndef CONFIG_NO_RADIUS
#else /* CONFIG_NO_RADIUS */
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS_SK_PFS
#endif /* CONFIG_FILS_SK_PFS */
#endif /* CONFIG_FILS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_NO_RC4
#endif /* CONFIG_NO_RC4 */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifndef CONFIG_NO_RC4
#endif /* CONFIG_NO_RC4 */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_SAE
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#if defined(CONFIG_FILS) && defined(CONFIG_OCV)
#endif /* CONFIG_FILS && CONFIG_OCV */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P_MANAGER
#endif /* CONFIG_P2P_MANAGER */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_OWE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_TAXONOMY
#endif /* CONFIG_TAXONOMY */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WNM_AP
#endif /* CONFIG_WNM_AP */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_NATIVE_WINDOWS */
