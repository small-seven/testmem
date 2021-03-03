#include "includes.h"
#include <sys/ioctl.h>
#include <sys/sysctl.h>
#include "common.h"
#include "driver.h"
#include "eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_common.h"
#include <net/if.h>
#include <net/if_media.h>
#ifdef __NetBSD__
#include <net/if_ether.h>
#else
#include <net/ethernet.h>
#endif
#include <net/route.h>
#ifdef __DragonFly__
#include <netproto/802_11/ieee80211_ioctl.h>
#include <netproto/802_11/ieee80211_dragonfly.h>
#else /* __DragonFly__ */
#ifdef __GLIBC__
#include <netinet/ether.h>
#endif /* __GLIBC__ */
#include <net80211/ieee80211.h>
#include <net80211/ieee80211_ioctl.h>
#include <net80211/ieee80211_crypto.h>
#endif /* __DragonFly__ || __GLIBC__ */
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#include <net80211/ieee80211_freebsd.h>
#endif
#if __NetBSD__
#include <net80211/ieee80211_netbsd.h>
#endif
#include "l2_packet/l2_packet.h"
#ifndef HOSTAPD
#endif /* HOSTAPD */
#ifdef SIOCG80211NWID
#else
#endif
#ifdef SIOCS80211NWID
#else
#endif
#ifdef IEEE80211_KEY_NOREPLAY
#endif /* IEEE80211_KEY_NOREPLAY */
#ifndef HOSTAPD
#endif /* HOSTAPD */
#ifndef HOSTAPD
#ifdef IEEE80211_KEY_NOREPLAY
#endif /* IEEE80211_KEY_NOREPLAY */
#endif /* HOSTAPD */
#ifdef WORDS_BIGENDIAN
#else /* WORDS_BIGENDIAN */
#endif /* WORDS_BIGENDIAN */
#ifndef IEEE80211_IOC_APPIE
#endif /* IEEE80211_IOC_APPIE */
#ifdef SIOCS80211CHANNEL
#endif /* SIOCS80211CHANNEL */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef SIOCS80211CHANNEL
#else /* SIOCS80211CHANNEL */
#endif /* SIOCS80211CHANNEL */
#ifdef IEEE80211_IOC_APPIE
#endif /* IEEE80211_IOC_APPIE */
#ifdef HOSTAPD
#undef RSN_VERSION
#undef WPA_VERSION
#undef WPA_OUI_TYPE
#ifdef WORDS_BIGENDIAN
#else /* WORDS_BIGENDIAN */
#endif /* WORDS_BIGENDIAN */
#ifdef RTM_IEEE80211_REJOIN
#endif
#else /* HOSTAPD */
#ifdef SIOCG80211BSSID
#else
#endif
#ifdef IEEE80211_IOC_APPIE
#else /* IEEE80211_IOC_APPIE */
#endif /* IEEE80211_IOC_APPIE */
#ifdef IEEE80211_IOC_SCAN_MAX_SSID
#endif /* IEEE80211_IOC_SCAN_MAX_SSID */
#ifdef IEEE80211_IOC_SCAN_MAX_SSID
#if 0
#endif
#else /* IEEE80211_IOC_SCAN_MAX_SSID */
#endif /* IEEE80211_IOC_SCAN_MAX_SSID */
#ifdef RTM_IEEE80211_REJOIN
#endif
#ifdef __FreeBSD__
#else
#endif
#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#else
#endif
#ifdef IEEE80211_IOC_DEVCAPS
#define IEEE80211_CIPHER_WEP            0
#define IEEE80211_CIPHER_TKIP           1
#define IEEE80211_CIPHER_AES_CCM        3
#define IEEE80211_CRYPTO_WEP            (1<<IEEE80211_CIPHER_WEP)
#define IEEE80211_CRYPTO_TKIP           (1<<IEEE80211_CIPHER_TKIP)
#define IEEE80211_CRYPTO_AES_CCM        (1<<IEEE80211_CIPHER_AES_CCM)
#define IEEE80211_C_HOSTAP      0x00000400      /* CAPABILITY: HOSTAP avail */
#define IEEE80211_C_WPA1        0x00800000      /* CAPABILITY: WPA1 avail */
#define IEEE80211_C_WPA2        0x01000000      /* CAPABILITY: WPA2 avail */
#undef IEEE80211_CIPHER_WEP
#undef IEEE80211_CIPHER_TKIP
#undef IEEE80211_CIPHER_AES_CCM
#undef IEEE80211_CRYPTO_WEP
#undef IEEE80211_CRYPTO_TKIP
#undef IEEE80211_CRYPTO_AES_CCM
#undef IEEE80211_C_HOSTAP
#undef IEEE80211_C_WPA1
#undef IEEE80211_C_WPA2
#else /* IEEE80211_IOC_DEVCAPS */
#endif /* IEEE80211_IOC_DEVCAPS */
#ifdef IEEE80211_IOC_SCAN_MAX_SSID
#else /* IEEE80211_IOC_SCAN_MAX_SSID */
#endif /* IEEE80211_IOC_SCAN_MAX_SSID */
#ifdef IEEE80211_M_MBSS
#endif /* IEEE80211_M_MBSS */
#define	GETPARAM(drv, param, v) \
#undef GETPARAM
#endif /* HOSTAPD */
#ifdef HOSTAPD
#else /* HOSTAPD */
#endif /* HOSTAPD */
#ifdef HOSTAPD
#else /* HOSTAPD */
#endif /* HOSTAPD */
