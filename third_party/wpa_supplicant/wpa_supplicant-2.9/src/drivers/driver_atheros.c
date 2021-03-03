#include "includes.h"
#include <net/if.h>
#include <sys/ioctl.h>
#include "common.h"
#include "eloop.h"
#include "common/ieee802_11_defs.h"
#include "l2_packet/l2_packet.h"
#include "p2p/p2p.h"
#include "common.h"
#ifndef _BYTE_ORDER
#ifdef WORDS_BIGENDIAN
#define _BYTE_ORDER _BIG_ENDIAN
#else
#define _BYTE_ORDER _LITTLE_ENDIAN
#endif
#endif /* _BYTE_ORDER */
#define ATH_WPS_IE
#include "ieee80211_external.h"
#undef WPA_OUI_TYPE
#ifdef CONFIG_WPS
#include <netpacket/packet.h>
#endif /* CONFIG_WPS */
#ifndef ETH_P_80211_RAW
#define ETH_P_80211_RAW 0x0019
#endif
#include "linux_wext.h"
#include "driver.h"
#include "eloop.h"
#include "priv_netlink.h"
#include "l2_packet/l2_packet.h"
#include "common/ieee802_11_defs.h"
#include "netlink.h"
#include "linux_ioctl.h"
#if defined(CONFIG_IEEE80211W) || defined(CONFIG_IEEE80211R) || defined(CONFIG_HS20) || defined(CONFIG_WNM) || defined(CONFIG_WPS) || defined(CONFIG_FILS)
#define ATHEROS_USE_RAW_RECEIVE
#endif
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifdef ATH_GCM_SUPPORT
#endif /* ATH_GCM_SUPPORT */
#ifdef ATH_GCM_SUPPORT
#endif /* ATH_GCM_SUPPORT */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef ATH_GCM_SUPPORT
#endif /* ATH_GCM_SUPPORT */
#ifdef CONFIG_IEEE80211W
#ifdef ATH_GCM_SUPPORT
#endif /* ATH_GCM_SUPPORT */
#endif /* CONFIG_IEEE80211W */
#ifdef WORDS_BIGENDIAN
#ifndef WPA_KEY_RSC_LEN
#define WPA_KEY_RSC_LEN 8
#endif
#else /* WORDS_BIGENDIAN */
#endif /* WORDS_BIGENDIAN */
#ifdef CONFIG_ATHEROS_QOS_MAP
#endif /* CONFIG_ATHEROS_QOS_MAP */
#ifdef ATHEROS_USE_RAW_RECEIVE
#endif /* ATHEROS_USE_RAW_RECEIVE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#if defined(CONFIG_IEEE80211W) || defined(CONFIG_IEEE80211R) || defined(CONFIG_FILS)
#endif /* CONFIG_IEEE80211R || CONFIG_IEEE80211W || CONFIG_FILS */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#if defined(CONFIG_WPS) || defined(CONFIG_IEEE80211R) || defined(CONFIG_FILS)
#endif /* CONFIG_WPS || CONFIG_IEEE80211R || CONFIG_FILS */
#ifdef CONFIG_WPS
#else /* CONFIG_WPS */
#define atheros_set_ap_wps_ie NULL
#endif /* CONFIG_WPS */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_IEEE80211W) || defined(CONFIG_FILS)
#ifdef CONFIG_FILS
#else /* CONFIG_FILS */
#endif /* CONFIG_FILS */
#endif /* CONFIG_IEEE80211R || CONFIG_IEEE80211W || CONFIG_FILS */
#ifdef ATH_WPS_IE
#endif /* ATH_WPS_IE */
#ifdef ATH_WPS_IE
#endif /* ATH_WPS_IE */
#define MGMT_FRAM_TAG_SIZE 30 /* hardcoded in driver */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_IEEE80211W) || defined(CONFIG_FILS)
#endif /* CONFIG_IEEE80211W || CONFIG_IEEE80211R || CONFIG_FILS */
#ifdef ATHEROS_USE_RAW_RECEIVE
#endif /* ATHEROS_USE_RAW_RECEIVE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#if defined(CONFIG_HS20) && (defined(IEEE80211_PARAM_OSEN) || defined(CONFIG_ATHEROS_OSEN))
#endif /* CONFIG_HS20 && IEEE80211_PARAM_OSEN */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_IEEE80211W) || defined(CONFIG_FILS)
#endif /* CONFIG_IEEE80211R || CONFIG_IEEE80211W || CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#if defined(CONFIG_WNM) && defined(IEEE80211_APPIE_FRAME_WNM)
#define IEEE80211_APPIE_MAX    1024 /* max appie buffer size */
#endif /* CONFIG_WNM && IEEE80211_APPIE_FRAME_WNM */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_IEEE80211W) || defined(CONFIG_FILS)
#endif /* CONFIG_IEEE80211R || CONFIG_IEEE80211W || CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#if defined(CONFIG_WNM) && defined(IEEE80211_APPIE_FRAME_WNM)
#endif /* CONFIG_WNM && IEEE80211_APPIE_FRAME_WNM */
