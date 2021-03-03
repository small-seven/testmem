#include "includes.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <inttypes.h>
#ifdef __linux__
#include <netpacket/packet.h>
#include <net/if_arp.h>
#include <net/if.h>
#endif /* __linux__ */
#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
#include <net/if_dl.h>
#include <net/if_media.h>
#endif /* defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) */
#ifdef __sun__
#include <sys/sockio.h>
#endif /* __sun__ */
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/defs.h"
#include "common/ieee802_1x_defs.h"
#include "common/eapol_common.h"
#include "pae/ieee802_1x_kay.h"
#include "driver.h"
#include "driver_wired_common.h"
#include "nss_macsec_secy.h"
#include "nss_macsec_secy_rx.h"
#include "nss_macsec_secy_tx.h"
#define MAXSC 16
#define SAK_128_LEN	16
#define SAK_256_LEN	32
#define TCI_ES                0x40
#define TCI_SC                0x20
#define TCI_SCB               0x10
#define TCI_E                 0x08
#define TCI_C                 0x04
#ifdef _MSC_VER
#pragma pack(push, 1)
#endif /* _MSC_VER */
#ifdef _MSC_VER
#pragma pack(pop)
#endif /* _MSC_VER */
#ifdef __linux__
#ifdef HOSTAPD
#endif /* HOSTAPD */
#endif /* __linux__ */
#ifdef __linux__
#else /* __linux__ */
#endif /* __linux__ */
