#include "lwip/opt.h"
#if LWIP_IPV4
#include "lwip/ip4_frag.h"
#include "lwip/def.h"
#include "lwip/inet_chksum.h"
#include "lwip/netif.h"
#include "lwip/stats.h"
#include "lwip/icmp.h"
#include <string.h>
#if IP_REASSEMBLY
#ifndef IP_REASS_CHECK_OVERLAP
#define IP_REASS_CHECK_OVERLAP 1
#endif /* IP_REASS_CHECK_OVERLAP */
#ifndef IP_REASS_FREE_OLDEST
#define IP_REASS_FREE_OLDEST 1
#endif /* IP_REASS_FREE_OLDEST */
#define IP_REASS_FLAG_LASTFRAG 0x01
#define IP_REASS_VALIDATE_TELEGRAM_FINISHED  1
#define IP_REASS_VALIDATE_PBUF_QUEUED        0
#define IP_REASS_VALIDATE_PBUF_DROPPED       -1
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif
#define IP_ADDRESSES_AND_ID_MATCH(iphdrA, iphdrB)  \
ip_reass_free_complete_datagram(struct ip_reassdata *ipr, struct ip_reassdata *prev)
{
  u16_t pbufs_freed = 0;
  u16_t clen;
  struct pbuf *p;
  struct ip_reass_helper *iprh;

  LWIP_ASSERT("prev != ipr", prev != ipr);
  if (prev != NULL) {
    LWIP_ASSERT("prev->next == ipr", prev->next == ipr);
  }

  MIB2_STATS_INC(mib2.ipreasmfails);
#if LWIP_ICMP
  iprh = (struct ip_reass_helper *)ipr->p->payload;
  if (iprh->start == 0) {
    /* The first fragment was received, send ICMP time exceeded. */
    /* First, de-queue the first pbuf from r->p. */
    p = ipr->p;
    ipr->p = iprh->next_pbuf;
    /* Then, copy the original header into it. */
    SMEMCPY(p->payload, &ipr->iphdr, IP_HLEN);
    icmp_time_exceeded(p, ICMP_TE_FRAG);
    clen = pbuf_clen(p);
    LWIP_ASSERT("pbufs_freed + clen <= 0xffff", pbufs_freed + clen <= 0xffff);
    pbufs_freed = (u16_t)(pbufs_freed + clen);
    pbuf_free(p);
  }
#endif /* LWIP_ICMP */

  /* First, free all received pbufs.  The individual pbufs need to be released
     separately as they have not yet been chained */
  p = ipr->p;
  while (p != NULL) {
    struct pbuf *pcur;
    iprh = (struct ip_reass_helper *)p->payload;
    pcur = p;
    /* get the next pointer before freeing */
    p = iprh->next_pbuf;
    clen = pbuf_clen(pcur);
    LWIP_ASSERT("pbufs_freed + clen <= 0xffff", pbufs_freed + clen <= 0xffff);
    pbufs_freed = (u16_t)(pbufs_freed + clen);
    pbuf_free(pcur);
  }
  /* Then, unchain the struct ip_reassdata from the list and free it. */
  ip_reass_dequeue_datagram(ipr, prev);
  LWIP_ASSERT("ip_reass_pbufcount >= pbufs_freed", ip_reass_pbufcount >= pbufs_freed);
  ip_reass_pbufcount = (u16_t)(ip_reass_pbufcount - pbufs_freed);

  return pbufs_freed;
}
#if IP_REASS_FREE_OLDEST
ip_reass_remove_oldest_datagram(struct ip_hdr *fraghdr, int pbufs_needed)
{
  /* @todo Can't we simply remove the last datagram in the
   *       linked list behind reassdatagrams?
   */
  struct ip_reassdata *r, *oldest, *prev, *oldest_prev;
  int pbufs_freed = 0, pbufs_freed_current;
  int other_datagrams;

  /* Free datagrams until being allowed to enqueue 'pbufs_needed' pbufs,
   * but don't free the datagram that 'fraghdr' belongs to! */
  do {
    oldest = NULL;
    prev = NULL;
    oldest_prev = NULL;
    other_datagrams = 0;
    r = reassdatagrams;
    while (r != NULL) {
      if (!IP_ADDRESSES_AND_ID_MATCH(&r->iphdr, fraghdr)) {
        /* Not the same datagram as fraghdr */
        other_datagrams++;
        if (oldest == NULL) {
          oldest = r;
          oldest_prev = prev;
        } else if (r->timer <= oldest->timer) {
          /* older than the previous oldest */
          oldest = r;
          oldest_prev = prev;
        }
      }
      if (r->next != NULL) {
        prev = r;
      }
      r = r->next;
    }
    if (oldest != NULL) {
      pbufs_freed_current = ip_reass_free_complete_datagram(oldest, oldest_prev);
      pbufs_freed += pbufs_freed_current;
    }
  } while ((pbufs_freed < pbufs_needed) && (other_datagrams > 1));
  return pbufs_freed;
}
#endif /* IP_REASS_FREE_OLDEST */
#if ! IP_REASS_FREE_OLDEST
#endif
#if IP_REASS_FREE_OLDEST
#endif /* IP_REASS_FREE_OLDEST */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IP_REASS_FREE_OLDEST
#endif /* IP_REASS_FREE_OLDEST */
#if CHECKSUM_GEN_IP
#endif /* CHECKSUM_GEN_IP */
#endif /* IP_REASSEMBLY */
#if IP_FRAG
#if !LWIP_NETIF_TX_SINGLE_PBUF
#endif /* !LWIP_NETIF_TX_SINGLE_PBUF */
#if !LWIP_NETIF_TX_SINGLE_PBUF
#endif
#if LWIP_NETIF_TX_SINGLE_PBUF
#else /* LWIP_NETIF_TX_SINGLE_PBUF */
#endif /* LWIP_NETIF_TX_SINGLE_PBUF */
#if CHECKSUM_GEN_IP
#endif /* CHECKSUM_GEN_IP */
#endif /* IP_FRAG */
#endif /* LWIP_IPV4 */
