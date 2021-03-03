#include "lwip/opt.h"
#if LWIP_IPV6 && LWIP_ETHERNET
#include "lwip/ethip6.h"
#include "lwip/nd6.h"
#include "lwip/pbuf.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#include "lwip/inet_chksum.h"
#include "lwip/netif.h"
#include "lwip/icmp6.h"
#include "lwip/prot/ethernet.h"
#include "netif/ethernet.h"
#include <string.h>
#endif /* LWIP_IPV6 && LWIP_ETHERNET */
