#include "includes.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <net/route.h>
#ifdef __linux__
#include <net/if.h>
#endif /* __linux__ */
#include "common.h"
#include "uuid.h"
#include "eloop.h"
#include "wps.h"
#include "wps_upnp.h"
#include "wps_upnp_i.h"
#define UPNP_CACHE_SEC (UPNP_CACHE_SEC_MIN + 1) /* cache time we use */
#define UPNP_CACHE_SEC_MIN 1800 /* min cachable time per UPnP standard */
#define UPNP_ADVERTISE_REPEAT 2 /* no more than 3 */
#define MAX_MSEARCH 20          /* max simultaneous M-SEARCH replies ongoing */
#define SSDP_TARGET  "239.0.0.0"
#define SSDP_NETMASK "255.0.0.0"
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#if 0   /* could be */
#endif  /* could be */
#if 0
#endif
#ifdef __linux__
#else /* __linux__ */
#endif /* __linux__ */
#ifdef __linux__
#endif /* __linux__ */
#if 0   /* maybe ok if we sometimes block on writes */
#endif
#if 0   /* not needed, because we don't receive using multicast_sd */
#endif  /* not needed */
