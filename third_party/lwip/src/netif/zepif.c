#include "netif/zepif.h"
#if LWIP_IPV6 && LWIP_UDP
#include "netif/lowpan6.h"
#include "lwip/udp.h"
#include "lwip/timeouts.h"
#include <string.h>
#ifndef ZEPIF_LOOPBACK
#define ZEPIF_LOOPBACK    0
#endif
#define ZEP_MAX_DATA_LEN  127
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif
#if ZEPIF_LOOPBACK
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#endif /* LWIP_IPV6 && LWIP_UDP */
