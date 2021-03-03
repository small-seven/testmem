#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "driver.h"
#include "driver_wired_common.h"
#include <sys/ioctl.h>
#undef IFNAMSIZ
#include <net/if.h>
#ifdef __linux__
#include <netpacket/packet.h>
#include <net/if_arp.h>
#endif /* __linux__ */
#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
#include <net/if_dl.h>
#include <net/if_media.h>
#endif /* defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) */
#ifdef __sun__
#include <sys/sockio.h>
#endif /* __sun__ */
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
