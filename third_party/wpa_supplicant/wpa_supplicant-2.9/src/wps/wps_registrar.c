#include "utils/includes.h"
#include "utils/common.h"
#include "utils/base64.h"
#include "utils/eloop.h"
#include "utils/uuid.h"
#include "utils/list.h"
#include "crypto/crypto.h"
#include "crypto/sha256.h"
#include "crypto/random.h"
#include "common/ieee802_11_defs.h"
#include "wps_i.h"
#include "wps_dev_attr.h"
#include "wps_upnp.h"
#include "wps_upnp_i.h"
#ifndef CONFIG_WPS_STRICT
#define WPS_WORKAROUNDS
#endif /* CONFIG_WPS_STRICT */
#ifdef CONFIG_WPS_NFC
#else /* CONFIG_WPS_NFC */
#define wps_free_nfc_pw_tokens(t, p) do { } while (0)
#endif /* CONFIG_WPS_NFC */
#define PIN_LOCKED BIT(0)
#define PIN_EXPIRES BIT(1)
#ifdef WPS_WORKAROUNDS
#endif /* WPS_WORKAROUNDS */
#define WPS_STRDUP(n) \
#undef WPS_STRDUP
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef WPS_WORKAROUNDS
#endif /* WPS_WORKAROUNDS */
#ifdef WPS_WORKAROUNDS
#endif /* WPS_WORKAROUNDS */
#ifdef WPS_WORKAROUNDS
#endif /* WPS_WORKAROUNDS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_WPS_TESTING
#endif /* CONFIG_WPS_TESTING */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef WPS_WORKAROUNDS
#endif /* WPS_WORKAROUNDS */
#ifdef WPS_WORKAROUNDS
#else /* WPS_WORKAROUNDS */
#endif /* WPS_WORKAROUNDS */
#ifdef WPS_WORKAROUNDS
#else /* WPS_WORKAROUNDS */
#endif /* WPS_WORKAROUNDS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef WPS_WORKAROUNDS
#endif /* WPS_WORKAROUNDS */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef WPS_WORKAROUNDS
#endif /* WPS_WORKAROUNDS */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_UPNP
#endif /* CONFIG_WPS_UPNP */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
