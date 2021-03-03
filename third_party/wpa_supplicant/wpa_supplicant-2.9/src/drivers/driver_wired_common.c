#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "driver.h"
#include "driver_wired_common.h"
#include <sys/ioctl.h>
#include <net/if.h>
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
#ifdef __sun__
#endif /* __sun__ */
#ifdef __linux__
#endif /* __linux__ */
#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
#endif /* defined(__FreeBSD__) || defined(__DragonFly__) || defined(FreeBSD_kernel__) */
#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
#endif /* defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) */
#ifdef __linux__
#else /* __linux__ */
#endif /* __linux__ */
#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
#endif /* defined(__FreeBSD__) || defined(__DragonFly__) || defined(FreeBSD_kernel__) */
#ifdef __linux__
#else /* __linux__ */
#endif /* __linux__ */
#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
#endif /* defined(__FreeBSD__) || defined(__DragonFly__) || defined(FreeBSD_kernel__) */
