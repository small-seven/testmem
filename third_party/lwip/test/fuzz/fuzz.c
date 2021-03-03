#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/dns.h"
#include "netif/etharp.h"
#if LWIP_IPV6
#include "lwip/ethip6.h"
#include "lwip/nd6.h"
#endif
#include "lwip/apps/httpd.h"
#include "lwip/apps/snmp.h"
#include "lwip/apps/lwiperf.h"
#include "lwip/apps/mdns.h"
#include <string.h>
#include <stdio.h>
#ifdef LWIP_FUZZ_MULTI_PACKET
#else
#endif
#if LWIP_IPV6
#endif
#ifdef LWIP_FUZZ_MULTI_PACKET
#else /* LWIP_FUZZ_MULTI_PACKET */
#endif /* LWIP_FUZZ_MULTI_PACKET */
#if LWIP_IPV6
#endif
