#include "includes.h"
#include "common.h"
#include "uuid.h"
#include "config.h"
#ifndef WPA_KEY_ROOT
#define WPA_KEY_ROOT HKEY_LOCAL_MACHINE
#endif
#ifndef WPA_KEY_PREFIX
#define WPA_KEY_PREFIX TEXT("SOFTWARE\\wpa_supplicant")
#endif
#ifdef UNICODE
#define TSTR "%S"
#else /* UNICODE */
#define TSTR "%s"
#endif /* UNICODE */
#define TNAMELEN 255
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#define STR(t) write_str(netw, #t, ssid)
#define INT(t) write_int(netw, #t, ssid->t, 0)
#define INTe(t) write_int(netw, #t, ssid->eap.t, 0)
#define INT_DEF(t, def) write_int(netw, #t, ssid->t, def)
#define INT_DEFe(t, def) write_int(netw, #t, ssid->eap.t, def)
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#undef STR
#undef INT
#undef INT_DEF
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
