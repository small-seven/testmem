#include "lwip/opt.h"
#if LWIP_UDP /* don't build if not configured for use in lwipopts.h */
#include "lwip/udp.h"
#include "lwip/def.h"
#include "lwip/memp.h"
#include "lwip/inet_chksum.h"
#include "lwip/ip_addr.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#include "lwip/netif.h"
#include "lwip/icmp.h"
#include "lwip/icmp6.h"
#include "lwip/stats.h"
#include "lwip/snmp.h"
#include "lwip/dhcp.h"
#include <string.h>
#ifndef UDP_LOCAL_PORT_RANGE_START
#define UDP_LOCAL_PORT_RANGE_START  0xc000
#define UDP_LOCAL_PORT_RANGE_END    0xffff
#define UDP_ENSURE_LOCAL_PORT_RANGE(port) ((u16_t)(((port) & (u16_t)~UDP_LOCAL_PORT_RANGE_START) + UDP_LOCAL_PORT_RANGE_START))
#endif
#ifdef LWIP_RAND
#endif /* LWIP_RAND */
#if LWIP_IPV4 && IP_SOF_BROADCAST_RECV
#endif /* LWIP_IPV4 && IP_SOF_BROADCAST_RECV */
#if LWIP_IPV4
#if IP_SOF_BROADCAST_RECV
#endif /* IP_SOF_BROADCAST_RECV */
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if SO_REUSE
#endif /* SO_REUSE */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if CHECKSUM_CHECK_UDP
#if LWIP_UDPLITE
#endif /* LWIP_UDPLITE */
#endif /* CHECKSUM_CHECK_UDP */
#if SO_REUSE && SO_REUSE_RXTOALL
#endif /* SO_REUSE && SO_REUSE_RXTOALL */
#if LWIP_ICMP || LWIP_ICMP6
#endif /* LWIP_ICMP || LWIP_ICMP6 */
#if CHECKSUM_CHECK_UDP
#endif /* CHECKSUM_CHECK_UDP */
#if LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP
#endif /* LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP */
#if LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP
#endif /* LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP */
#if LWIP_MULTICAST_TX_OPTIONS
#if LWIP_IPV4
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#endif /* LWIP_IPV4 */
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#if LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP
#else /* LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP */
#endif /* LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP */
#if LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP
#endif /* LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP
#else /* LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP */
#endif /* LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP */
#if LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP
#endif /* LWIP_CHECKSUM_ON_COPY && CHECKSUM_GEN_UDP */
#if LWIP_IPV4 && IP_SOF_BROADCAST
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#endif /* LWIP_IPV4 && IP_SOF_BROADCAST */
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#if LWIP_UDPLITE
#if CHECKSUM_GEN_UDP
#if LWIP_CHECKSUM_ON_COPY
#endif /* LWIP_CHECKSUM_ON_COPY */
#if LWIP_CHECKSUM_ON_COPY
#endif /* LWIP_CHECKSUM_ON_COPY */
#endif /* CHECKSUM_GEN_UDP */
#endif /* LWIP_UDPLITE */
#if CHECKSUM_GEN_UDP
#if LWIP_CHECKSUM_ON_COPY
#endif /* LWIP_CHECKSUM_ON_COPY */
#endif /* CHECKSUM_GEN_UDP */
#if LWIP_MULTICAST_TX_OPTIONS
#else /* LWIP_MULTICAST_TX_OPTIONS */
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#if LWIP_IPV6 && LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6 && LWIP_IPV6_SCOPES */
#if LWIP_IPV4
#else /* LWIP_IPV4 */
#endif /* LWIP_IPV4 */
#if LWIP_IPV6 && LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6 && LWIP_IPV6_SCOPES */
#if SO_REUSE
#endif /* SO_REUSE */
#if LWIP_IPV6 && LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6 && LWIP_IPV6_SCOPES */
#if LWIP_IPV4 && LWIP_IPV6
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif
udp_remove(struct udp_pcb *pcb)
{
  struct udp_pcb *pcb2;

  LWIP_ASSERT_CORE_LOCKED();

  LWIP_ERROR("udp_remove: invalid pcb", pcb != NULL, return);

  mib2_udp_unbind(pcb);
  /* pcb to be removed is first in list? */
  if (udp_pcbs == pcb) {
    /* make list start at 2nd pcb */
    udp_pcbs = udp_pcbs->next;
    /* pcb not 1st in list */
  } else {
    for (pcb2 = udp_pcbs; pcb2 != NULL; pcb2 = pcb2->next) {
      /* find pcb in udp_pcbs list */
      if (pcb2->next != NULL && pcb2->next == pcb) {
        /* remove pcb from list */
        pcb2->next = pcb->next;
        break;
      }
    }
  }
  memp_free(MEMP_UDP_PCB, pcb);
}
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#if LWIP_IPV4 && LWIP_IPV6
#else
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if UDP_DEBUG
#endif /* UDP_DEBUG */
#endif /* LWIP_UDP */
