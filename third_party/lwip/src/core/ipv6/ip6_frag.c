#include "lwip/opt.h"
#include "lwip/ip6_frag.h"
#include "lwip/ip6.h"
#include "lwip/icmp6.h"
#include "lwip/nd6.h"
#include "lwip/ip.h"
#include "lwip/pbuf.h"
#include "lwip/memp.h"
#include "lwip/stats.h"
#include <string.h>
#if LWIP_IPV6 && LWIP_IPV6_REASS  /* don't build if not configured for use in lwipopts.h */
#ifndef IP_REASS_CHECK_OVERLAP
#define IP_REASS_CHECK_OVERLAP 1
#endif /* IP_REASS_CHECK_OVERLAP */
#ifndef IP_REASS_FREE_OLDEST
#define IP_REASS_FREE_OLDEST 1
#endif /* IP_REASS_FREE_OLDEST */
#if IPV6_FRAG_COPYHEADER
#define IPV6_FRAG_REQROOM ((s16_t)(sizeof(struct ip6_reass_helper) - IP6_FRAG_HLEN))
#endif
#define IP_REASS_FLAG_LASTFRAG 0x01
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif
#if IP_REASS_FREE_OLDEST
#endif /* IP_REASS_FREE_OLDEST */
#if !IPV6_FRAG_COPYHEADER
#endif /* !IPV6_FRAG_COPYHEADER */
ip6_reass_free_complete_datagram(struct ip6_reassdata *ipr)
{
  struct ip6_reassdata *prev;
  u16_t pbufs_freed = 0;
  u16_t clen;
  struct pbuf *p;
  struct ip6_reass_helper *iprh;

#if LWIP_ICMP6
  iprh = (struct ip6_reass_helper *)ipr->p->payload;
  if (iprh->start == 0) {
    /* The first fragment was received, send ICMP time exceeded. */
    /* First, de-queue the first pbuf from r->p. */
    p = ipr->p;
    ipr->p = iprh->next_pbuf;
    /* Restore the part that we've overwritten with our helper structure, or we
     * might send garbage (and disclose a pointer) in the ICMPv6 reply. */
    MEMCPY(p->payload, ipr->orig_hdr, sizeof(iprh));
    /* Then, move back to the original ipv6 header (we are now pointing to Fragment header).
       This cannot fail since we already checked when receiving this fragment. */
    if (pbuf_header_force(p, (s16_t)((u8_t*)p->payload - (u8_t*)ipr->iphdr))) {
      LWIP_ASSERT("ip6_reass_free: moving p->payload to ip6 header failed\n", 0);
    }
    else {
      /* Reconstruct the zoned source and destination addresses, so that we do
       * not end up sending the ICMP response over the wrong link. */
      ip6_addr_t src_addr, dest_addr;
      ip6_addr_copy_from_packed(src_addr, IPV6_FRAG_SRC(ipr));
      ip6_addr_set_zone(&src_addr, ipr->src_zone);
      ip6_addr_copy_from_packed(dest_addr, IPV6_FRAG_DEST(ipr));
      ip6_addr_set_zone(&dest_addr, ipr->dest_zone);
      /* Send the actual ICMP response. */
      icmp6_time_exceeded_with_addrs(p, ICMP6_TE_FRAG, &src_addr, &dest_addr);
    }
    clen = pbuf_clen(p);
    LWIP_ASSERT("pbufs_freed + clen <= 0xffff", pbufs_freed + clen <= 0xffff);
    pbufs_freed = (u16_t)(pbufs_freed + clen);
    pbuf_free(p);
  }
#endif /* LWIP_ICMP6 */

  /* First, free all received pbufs.  The individual pbufs need to be released
     separately as they have not yet been chained */
  p = ipr->p;
  while (p != NULL) {
    struct pbuf *pcur;
    iprh = (struct ip6_reass_helper *)p->payload;
    pcur = p;
    /* get the next pointer before freeing */
    p = iprh->next_pbuf;
    clen = pbuf_clen(pcur);
    LWIP_ASSERT("pbufs_freed + clen <= 0xffff", pbufs_freed + clen <= 0xffff);
    pbufs_freed = (u16_t)(pbufs_freed + clen);
    pbuf_free(pcur);
  }

  /* Then, unchain the struct ip6_reassdata from the list and free it. */
  if (ipr == reassdatagrams) {
    reassdatagrams = ipr->next;
  } else {
    prev = reassdatagrams;
    while (prev != NULL) {
      if (prev->next == ipr) {
        break;
      }
      prev = prev->next;
    }
    if (prev != NULL) {
      prev->next = ipr->next;
    }
  }
  memp_free(MEMP_IP6_REASSDATA, ipr);

  /* Finally, update number of pbufs in reassembly queue */
  LWIP_ASSERT("ip_reass_pbufcount >= clen", ip6_reass_pbufcount >= pbufs_freed);
  ip6_reass_pbufcount = (u16_t)(ip6_reass_pbufcount - pbufs_freed);
}
#if IP_REASS_FREE_OLDEST
ip6_reass_remove_oldest_datagram(struct ip6_reassdata *ipr, int pbufs_needed)
{
  struct ip6_reassdata *r, *oldest;

  /* Free datagrams until being allowed to enqueue 'pbufs_needed' pbufs,
   * but don't free the current datagram! */
  do {
    r = oldest = reassdatagrams;
    while (r != NULL) {
      if (r != ipr) {
        if (r->timer <= oldest->timer) {
          /* older than the previous oldest */
          oldest = r;
        }
      }
      r = r->next;
    }
    if (oldest == ipr) {
      /* nothing to free, ipr is the only element on the list */
      return;
    }
    if (oldest != NULL) {
      ip6_reass_free_complete_datagram(oldest);
    }
  } while (((ip6_reass_pbufcount + pbufs_needed) > IP_REASS_MAX_PBUFS) && (reassdatagrams != NULL));
}
#endif /* IP_REASS_FREE_OLDEST */
#if IP_REASS_FREE_OLDEST
#endif /* IP_REASS_FREE_OLDEST */
#if IPV6_FRAG_COPYHEADER
#endif /* IPV6_FRAG_COPYHEADER */
#if LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6_SCOPES */
#if IP_REASS_FREE_OLDEST
#endif /* IP_REASS_FREE_OLDEST */
#if IPV6_FRAG_COPYHEADER
#else /* IPV6_FRAG_COPYHEADER */
#endif /* IPV6_FRAG_COPYHEADER */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IP_REASS_CHECK_OVERLAP
#endif /* IP_REASS_CHECK_OVERLAP */
#if IPV6_FRAG_COPYHEADER
#endif
#if IPV6_FRAG_COPYHEADER
#endif
#endif /* LWIP_IPV6 && LWIP_IPV6_REASS */
#if LWIP_IPV6 && LWIP_IPV6_FRAG
#if !LWIP_NETIF_TX_SINGLE_PBUF
#endif /* !LWIP_NETIF_TX_SINGLE_PBUF */
#if !LWIP_NETIF_TX_SINGLE_PBUF
#endif
#if LWIP_NETIF_TX_SINGLE_PBUF
#else
#endif /* LWIP_NETIF_TX_SINGLE_PBUF */
#endif /* LWIP_IPV6 && LWIP_IPV6_FRAG */
