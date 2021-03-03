#include "lwip/opt.h"
#if LWIP_ICMP6 && LWIP_IPV6 /* don't build if not configured for use in lwipopts.h */
#include "lwip/icmp6.h"
#include "lwip/prot/icmp6.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#include "lwip/inet_chksum.h"
#include "lwip/pbuf.h"
#include "lwip/netif.h"
#include "lwip/nd6.h"
#include "lwip/mld6.h"
#include "lwip/ip.h"
#include "lwip/stats.h"
#include <string.h>
#if LWIP_ICMP6_DATASIZE == 0
#undef LWIP_ICMP6_DATASIZE
#define LWIP_ICMP6_DATASIZE   8
#endif
#if CHECKSUM_CHECK_ICMP6
#endif /* CHECKSUM_CHECK_ICMP6 */
#if LWIP_IPV6_FORWARD
#endif
#if LWIP_IPV6_MLD
#endif
#if !LWIP_MULTICAST_PING
#endif /* LWIP_MULTICAST_PING */
#if LWIP_MULTICAST_PING
#endif /* LWIP_MULTICAST_PING */
#if CHECKSUM_GEN_ICMP6
#endif /* CHECKSUM_GEN_ICMP6 */
#if CHECKSUM_GEN_ICMP6
#endif /* CHECKSUM_GEN_ICMP6 */
#endif /* LWIP_ICMP6 && LWIP_IPV6 */
