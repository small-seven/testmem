#include "includes.h"
#include "common.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "rsn_supp/wpa.h"
#include "eloop.h"
#include "config.h"
#include "l2_packet/l2_packet.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "pcsc_funcs.h"
#include "rsn_supp/preauth.h"
#include "rsn_supp/pmksa_cache.h"
#include "common/wpa_ctrl.h"
#include "eap_peer/eap.h"
#include "ap/hostapd.h"
#include "p2p/p2p.h"
#include "fst/fst.h"
#include "wnm_sta.h"
#include "notify.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/gas_server.h"
#include "common/dpp.h"
#include "crypto/random.h"
#include "blacklist.h"
#include "wpas_glue.h"
#include "wps_supplicant.h"
#include "ibss_rsn.h"
#include "sme.h"
#include "gas_query.h"
#include "p2p_supplicant.h"
#include "bgscan.h"
#include "autoscan.h"
#include "ap.h"
#include "bss.h"
#include "scan.h"
#include "offchannel.h"
#include "interworking.h"
#include "mesh.h"
#include "mesh_mpm.h"
#include "wmm_ac.h"
#include "dpp_supplicant.h"
#define MAX_OWE_TRANSITION_BSS_SELECT_COUNT 5
#ifndef CONFIG_NO_SCAN_PROCESSING
#endif /* CONFIG_NO_SCAN_PROCESSING */
#ifndef CONFIG_NO_SCAN_PROCESSING
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#endif /* CONFIG_NO_SCAN_PROCESSING */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef IEEE8021X_EAPOL
#ifdef PCSC_FUNCS
#endif /* PCSC_FUNCS */
#endif /* IEEE8021X_EAPOL */
#ifndef CONFIG_NO_SCAN_PROCESSING
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifndef CONFIG_IBSS_RSN
#endif /* !CONFIG_IBSS_RSN */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_MBO
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_MBO */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifndef CONFIG_IBSS_RSN
#endif /* !CONFIG_IBSS_RSN */
#ifndef CONFIG_NO_ROAMING
#endif /* CONFIG_NO_ROAMING */
#ifndef CONFIG_NO_ROAMING
#else /* CONFIG_NO_ROAMING */
#endif /* CONFIG_NO_ROAMING */
#ifndef CONFIG_NO_RANDOM_POOL
#endif /* CONFIG_NO_RANDOM_POOL */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifndef CONFIG_NO_RANDOM_POOL
#endif /* CONFIG_NO_RANDOM_POOL */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#endif /* CONFIG_NO_SCAN_PROCESSING */
#ifdef CONFIG_NO_SCAN_PROCESSING
#else /* CONFIG_NO_SCAN_PROCESSING */
#endif /* CONFIG_NO_SCAN_PROCESSING */
#ifdef CONFIG_WNM
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#endif /* CONFIG_WNM */
void wnm_bss_keep_alive_deinit(struct wpa_supplicant *wpa_s)
{
#ifdef CONFIG_WNM
	eloop_cancel_timeout(wnm_bss_keep_alive, wpa_s, NULL);
#endif /* CONFIG_WNM */
}
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_OWE)
#endif /* CONFIG_IEEE80211R || CONFIG_OWE */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_FILS
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SME
#ifdef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#endif /* CONFIG_SME */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifndef CONFIG_NO_SCAN_PROCESSING
#endif /* CONFIG_NO_SCAN_PROCESSING */
#ifdef CONFIG_DELAYED_MIC_ERROR_REPORT
#endif /* CONFIG_DELAYED_MIC_ERROR_REPORT */
#ifdef CONFIG_DELAYED_MIC_ERROR_REPORT
#else /* CONFIG_DELAYED_MIC_ERROR_REPORT */
#endif /* CONFIG_DELAYED_MIC_ERROR_REPORT */
#ifdef CONFIG_TERMINATE_ONLASTIF
#endif /* CONFIG_TERMINATE_ONLASTIF */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_MATCH_IFACE
#endif /* CONFIG_MATCH_IFACE */
#ifdef CONFIG_TERMINATE_ONLASTIF
#endif /* CONFIG_TERMINATE_ONLASTIF */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#ifdef CONFIG_SME
#endif /* CONFIG_SME */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_GAS
#endif /* CONFIG_GAS */
#ifdef CONFIG_GAS_SERVER
#endif /* CONFIG_GAS_SERVER */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#if defined(NEED_AP_MLME) && defined(CONFIG_AP)
#endif /* NEED_AP_MLME && CONFIG_AP */
#if defined(NEED_AP_MLME) && defined(CONFIG_AP)
#endif /* NEED_AP_MLME && CONFIG_AP */
#if defined(NEED_AP_MLME) && defined(CONFIG_AP)
#endif /* NEED_AP_MLME && CONFIG_AP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifndef CONFIG_NO_SCAN_PROCESSING
#endif /* CONFIG_NO_SCAN_PROCESSING */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_AP
#ifdef CONFIG_OFFCHANNEL
#endif /* CONFIG_OFFCHANNEL */
#endif /* CONFIG_AP */
#ifdef CONFIG_OFFCHANNEL
#endif /* CONFIG_OFFCHANNEL */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_AP
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#endif /* CONFIG_AP */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_OFFCHANNEL
#endif /* CONFIG_OFFCHANNEL */
#ifdef CONFIG_OFFCHANNEL
#endif /* CONFIG_OFFCHANNEL */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_MATCH_IFACE
#endif /* CONFIG_MATCH_IFACE */
