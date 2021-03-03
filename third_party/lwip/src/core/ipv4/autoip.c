#include "lwip/opt.h"
#if LWIP_IPV4 && LWIP_AUTOIP /* don't build if not configured for use in lwipopts.h */
#include "lwip/mem.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/autoip.h"
#include "lwip/etharp.h"
#include "lwip/prot/autoip.h"
#include <string.h>
#ifndef LWIP_AUTOIP_RAND
#define LWIP_AUTOIP_RAND(netif) ( (((u32_t)((netif->hwaddr[5]) & 0xff) << 24) | \
#endif /* LWIP_AUTOIP_RAND */
#ifndef LWIP_AUTOIP_CREATE_SEED_ADDR
#define LWIP_AUTOIP_CREATE_SEED_ADDR(netif) \
#endif /* LWIP_AUTOIP_CREATE_SEED_ADDR */
#endif /* LWIP_IPV4 && LWIP_AUTOIP */
