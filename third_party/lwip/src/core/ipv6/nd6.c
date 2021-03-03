#include "lwip/opt.h"
#if LWIP_IPV6  /* don't build if not configured for use in lwipopts.h */
#include "lwip/nd6.h"
#include "lwip/priv/nd6_priv.h"
#include "lwip/prot/nd6.h"
#include "lwip/prot/icmp6.h"
#include "lwip/pbuf.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#include "lwip/inet_chksum.h"
#include "lwip/netif.h"
#include "lwip/icmp6.h"
#include "lwip/mld6.h"
#include "lwip/dhcp6.h"
#include "lwip/ip.h"
#include "lwip/stats.h"
#include "lwip/dns.h"
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#if LWIP_IPV6_DUP_DETECT_ATTEMPTS > IP6_ADDR_TENTATIVE_COUNT_MASK
#error LWIP_IPV6_DUP_DETECT_ATTEMPTS > IP6_ADDR_TENTATIVE_COUNT_MASK
#endif
#if LWIP_ND6_RDNSS_MAX_DNS_SERVERS
#endif
#define ND6_SEND_FLAG_MULTICAST_DEST 0x01
#define ND6_SEND_FLAG_ALLNODES_DEST 0x02
#define ND6_SEND_FLAG_ANY_SRC 0x04
#if LWIP_IPV6_SEND_ROUTER_SOLICIT
#endif /* LWIP_IPV6_SEND_ROUTER_SOLICIT */
#if LWIP_ND6_QUEUEING
#else /* LWIP_ND6_QUEUEING */
#define nd6_free_q(q) pbuf_free(q)
#endif /* LWIP_ND6_QUEUEING */
#if LWIP_IPV6_AUTOCONFIG
#endif /* LWIP_IPV6_AUTOCONFIG */
#if LWIP_IPV6_AUTOCONFIG
#endif /* LWIP_IPV6_AUTOCONFIG */
#if LWIP_IPV6_DUP_DETECT_ATTEMPTS
#endif /* LWIP_IPV6_DUP_DETECT_ATTEMPTS */
#if LWIP_ND6_RDNSS_MAX_DNS_SERVERS
#endif /* LWIP_ND6_RDNSS_MAX_DNS_SERVERS */
#if LWIP_IPV6_SEND_ROUTER_SOLICIT
#endif /* LWIP_IPV6_SEND_ROUTER_SOLICIT */
#if LWIP_ND6_ALLOW_RA_UPDATES
#endif /* LWIP_ND6_ALLOW_RA_UPDATES */
#if LWIP_IPV6_DHCP6
#endif
#if LWIP_ND6_ALLOW_RA_UPDATES
#endif /* LWIP_ND6_ALLOW_RA_UPDATES */
#if LWIP_IPV6_AUTOCONFIG
#endif /* LWIP_IPV6_AUTOCONFIG */
#if LWIP_ND6_RDNSS_MAX_DNS_SERVERS
#endif /* LWIP_ND6_RDNSS_MAX_DNS_SERVERS */
#if LWIP_IPV6_ADDRESS_LIFETIMES
#endif /* LWIP_IPV6_ADDRESS_LIFETIMES */
#if LWIP_IPV6_ADDRESS_LIFETIMES
#endif /* LWIP_IPV6_ADDRESS_LIFETIMES */
#if LWIP_IPV6_SEND_ROUTER_SOLICIT
#endif /* LWIP_IPV6_SEND_ROUTER_SOLICIT */
#if CHECKSUM_GEN_ICMP6
#endif /* CHECKSUM_GEN_ICMP6 */
#if CHECKSUM_GEN_ICMP6
#endif /* CHECKSUM_GEN_ICMP6 */
#if LWIP_IPV6_SEND_ROUTER_SOLICIT
#if CHECKSUM_GEN_ICMP6
#endif /* CHECKSUM_GEN_ICMP6 */
#endif /* LWIP_IPV6_SEND_ROUTER_SOLICIT */
nd6_free_neighbor_cache_entry(s8_t i)
{
  if ((i < 0) || (i >= LWIP_ND6_NUM_NEIGHBORS)) {
    return;
  }
  if (neighbor_cache[i].isrouter) {
    /* isrouter needs to be cleared before deleting a neighbor cache entry */
    return;
  }

  /* Free any queued packets. */
  if (neighbor_cache[i].q != NULL) {
    nd6_free_q(neighbor_cache[i].q);
    neighbor_cache[i].q = NULL;
  }

  neighbor_cache[i].state = ND6_NO_ENTRY;
  neighbor_cache[i].isrouter = 0;
  neighbor_cache[i].netif = NULL;
  neighbor_cache[i].counter.reachable_time = 0;
  ip6_addr_set_zero(&(neighbor_cache[i].next_hop_address));
}
#ifdef LWIP_HOOK_ND6_GET_GW
#endif /* LWIP_HOOK_ND6_GET_GW */
#if LWIP_NETIF_HWADDRHINT
#endif /* LWIP_NETIF_HWADDRHINT */
#ifdef LWIP_HOOK_ND6_GET_GW
#endif /* LWIP_HOOK_ND6_GET_GW */
#if LWIP_NETIF_HWADDRHINT
#endif /* LWIP_NETIF_HWADDRHINT */
#if LWIP_ND6_QUEUEING
#endif /* LWIP_ND6_QUEUEING */
#if LWIP_ND6_QUEUEING
#else /* LWIP_ND6_QUEUEING */
#endif /* LWIP_ND6_QUEUEING */
#if LWIP_ND6_QUEUEING
#else /* LWIP_ND6_QUEUEING */
#endif /* LWIP_ND6_QUEUEING */
#if LWIP_ND6_QUEUEING
nd6_free_q(struct nd6_q_entry *q)
{
  struct nd6_q_entry *r;
  LWIP_ASSERT("q != NULL", q != NULL);
  LWIP_ASSERT("q->p != NULL", q->p != NULL);
  while (q) {
    r = q;
    q = q->next;
    LWIP_ASSERT("r->p != NULL", (r->p != NULL));
    pbuf_free(r->p);
    memp_free(MEMP_ND6_QUEUE, r);
  }
}
#endif /* LWIP_ND6_QUEUEING */
#if LWIP_ND6_QUEUEING
#endif /* LWIP_ND6_QUEUEING */
#if LWIP_ND6_QUEUEING
#else /* LWIP_ND6_QUEUEING */
#endif /* LWIP_ND6_QUEUEING */
#if LWIP_ND6_TCP_REACHABILITY_HINTS
#endif /* LWIP_ND6_TCP_REACHABILITY_HINTS */
nd6_cleanup_netif(struct netif *netif)
{
  u8_t i;
  s8_t router_index;
  for (i = 0; i < LWIP_ND6_NUM_PREFIXES; i++) {
    if (prefix_list[i].netif == netif) {
      prefix_list[i].netif = NULL;
    }
  }
  for (i = 0; i < LWIP_ND6_NUM_NEIGHBORS; i++) {
    if (neighbor_cache[i].netif == netif) {
      for (router_index = 0; router_index < LWIP_ND6_NUM_ROUTERS; router_index++) {
        if (default_router_list[router_index].neighbor_entry == &neighbor_cache[i]) {
          default_router_list[router_index].neighbor_entry = NULL;
          default_router_list[router_index].flags = 0;
        }
      }
      neighbor_cache[i].isrouter = 0;
      nd6_free_neighbor_cache_entry(i);
    }
  }
  /* Clear the destination cache, since many entries may now have become
   * invalid for one of several reasons. As destination cache entries have no
   * netif association, use a sledgehammer approach (this can be improved). */
  nd6_clear_destination_cache();
}
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#if LWIP_IPV6_SEND_ROUTER_SOLICIT
#endif /* LWIP_IPV6_SEND_ROUTER_SOLICIT */
#endif /* LWIP_IPV6 */
