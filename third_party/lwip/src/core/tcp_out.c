#include "lwip/opt.h"
#if LWIP_TCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/priv/tcp_priv.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/inet_chksum.h"
#include "lwip/stats.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#if LWIP_TCP_TIMESTAMPS
#include "lwip/sys.h"
#endif
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#ifdef LWIP_HOOK_TCP_OUT_TCPOPT_LENGTH
#define LWIP_TCP_OPT_LENGTH_SEGMENT(flags, pcb) LWIP_HOOK_TCP_OUT_TCPOPT_LENGTH(pcb, LWIP_TCP_OPT_LENGTH(flags))
#else
#define LWIP_TCP_OPT_LENGTH_SEGMENT(flags, pcb) LWIP_TCP_OPT_LENGTH(flags)
#endif
#if TCP_CHECKSUM_ON_COPY
#define TCP_DATA_COPY(dst, src, len, seg) do { \
#define TCP_DATA_COPY2(dst, src, len, chksum, chksum_swapped)  \
#else /* TCP_CHECKSUM_ON_COPY*/
#define TCP_DATA_COPY(dst, src, len, seg)                     MEMCPY(dst, src, len)
#define TCP_DATA_COPY2(dst, src, len, chksum, chksum_swapped) MEMCPY(dst, src, len)
#endif /* TCP_CHECKSUM_ON_COPY*/
#ifndef TCP_CHECKSUM_ON_COPY_SANITY_CHECK
#define TCP_CHECKSUM_ON_COPY_SANITY_CHECK   0
#endif
#if TCP_CHECKSUM_ON_COPY_SANITY_CHECK
#ifndef TCP_CHECKSUM_ON_COPY_SANITY_CHECK_FAIL
#define TCP_CHECKSUM_ON_COPY_SANITY_CHECK_FAIL(msg) LWIP_DEBUGF(TCP_DEBUG | LWIP_DBG_LEVEL_WARNING, msg)
#endif
#endif
#if TCP_OVERSIZE
#ifndef TCP_OVERSIZE_CALC_LENGTH
#define TCP_OVERSIZE_CALC_LENGTH(length) ((length) + TCP_OVERSIZE)
#endif
#endif
tcp_create_segment(const struct tcp_pcb *pcb, struct pbuf *p, u8_t hdrflags, u32_t seqno, u8_t optflags)
{
  struct tcp_seg *seg;
  u8_t optlen;

  LWIP_ASSERT("tcp_create_segment: invalid pcb", pcb != NULL);
  LWIP_ASSERT("tcp_create_segment: invalid pbuf", p != NULL);

  optlen = LWIP_TCP_OPT_LENGTH_SEGMENT(optflags, pcb);

  if ((seg = (struct tcp_seg *)memp_malloc(MEMP_TCP_SEG)) == NULL) {
    LWIP_DEBUGF(TCP_OUTPUT_DEBUG | LWIP_DBG_LEVEL_SERIOUS, ("tcp_create_segment: no memory.\n"));
    pbuf_free(p);
    return NULL;
  }
  seg->flags = optflags;
  seg->next = NULL;
  seg->p = p;
  LWIP_ASSERT("p->tot_len >= optlen", p->tot_len >= optlen);
  seg->len = p->tot_len - optlen;
#if TCP_OVERSIZE_DBGCHECK
  seg->oversize_left = 0;
#endif /* TCP_OVERSIZE_DBGCHECK */
#if TCP_CHECKSUM_ON_COPY
  seg->chksum = 0;
  seg->chksum_swapped = 0;
  /* check optflags */
  LWIP_ASSERT("invalid optflags passed: TF_SEG_DATA_CHECKSUMMED",
              (optflags & TF_SEG_DATA_CHECKSUMMED) == 0);
#endif /* TCP_CHECKSUM_ON_COPY */

  /* build TCP header */
  if (pbuf_add_header(p, TCP_HLEN)) {
    LWIP_DEBUGF(TCP_OUTPUT_DEBUG | LWIP_DBG_LEVEL_SERIOUS, ("tcp_create_segment: no room for TCP header in pbuf.\n"));
    TCP_STATS_INC(tcp.err);
    tcp_seg_free(seg);
    return NULL;
  }
  seg->tcphdr = (struct tcp_hdr *)seg->p->payload;
  seg->tcphdr->src = lwip_htons(pcb->local_port);
  seg->tcphdr->dest = lwip_htons(pcb->remote_port);
  seg->tcphdr->seqno = lwip_htonl(seqno);
  /* ackno is set in tcp_output */
  TCPH_HDRLEN_FLAGS_SET(seg->tcphdr, (5 + optlen / 4), hdrflags);
  /* wnd and chksum are set in tcp_output */
  seg->tcphdr->urgp = 0;
  return seg;
}
#if TCP_OVERSIZE
tcp_pbuf_prealloc(pbuf_layer layer, u16_t length, u16_t max_length,
                  u16_t *oversize, const struct tcp_pcb *pcb, u8_t apiflags,
                  u8_t first_seg)
{
  struct pbuf *p;
  u16_t alloc = length;

  LWIP_ASSERT("tcp_pbuf_prealloc: invalid oversize", oversize != NULL);
  LWIP_ASSERT("tcp_pbuf_prealloc: invalid pcb", pcb != NULL);

#if LWIP_NETIF_TX_SINGLE_PBUF
  LWIP_UNUSED_ARG(max_length);
  LWIP_UNUSED_ARG(pcb);
  LWIP_UNUSED_ARG(apiflags);
  LWIP_UNUSED_ARG(first_seg);
  alloc = max_length;
#else /* LWIP_NETIF_TX_SINGLE_PBUF */
  if (length < max_length) {
    /* Should we allocate an oversized pbuf, or just the minimum
     * length required? If tcp_write is going to be called again
     * before this segment is transmitted, we want the oversized
     * buffer. If the segment will be transmitted immediately, we can
     * save memory by allocating only length. We use a simple
     * heuristic based on the following information:
     *
     * Did the user set TCP_WRITE_FLAG_MORE?
     *
     * Will the Nagle algorithm defer transmission of this segment?
     */
    if ((apiflags & TCP_WRITE_FLAG_MORE) ||
        (!(pcb->flags & TF_NODELAY) &&
         (!first_seg ||
          pcb->unsent != NULL ||
          pcb->unacked != NULL))) {
      alloc = LWIP_MIN(max_length, LWIP_MEM_ALIGN_SIZE(TCP_OVERSIZE_CALC_LENGTH(length)));
    }
  }
#endif /* LWIP_NETIF_TX_SINGLE_PBUF */
  p = pbuf_alloc(layer, alloc, PBUF_RAM);
  if (p == NULL) {
    return NULL;
  }
  LWIP_ASSERT("need unchained pbuf", p->next == NULL);
  *oversize = p->len - length;
  /* trim p->len to the currently used size */
  p->len = p->tot_len = length;
  return p;
}
#else /* TCP_OVERSIZE */
#define tcp_pbuf_prealloc(layer, length, mx, os, pcb, api, fst) pbuf_alloc((layer), (length), PBUF_RAM)
#endif /* TCP_OVERSIZE */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_OVERSIZE
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK*/
#endif /* TCP_OVERSIZE */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if LWIP_NETIF_TX_SINGLE_PBUF
#endif /* LWIP_NETIF_TX_SINGLE_PBUF */
#if LWIP_TCP_TIMESTAMPS
#endif /* LWIP_TCP_TIMESTAMPS */
#if TCP_OVERSIZE
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#endif /* TCP_OVERSIZE */
#if !LWIP_NETIF_TX_SINGLE_PBUF
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#endif /* !LWIP_NETIF_TX_SINGLE_PBUF */
#if TCP_OVERSIZE
#endif /* TCP_OVERSIZE */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_OVERSIZE
#endif /* TCP_OVERSIZE */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#if TCP_OVERSIZE
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#endif /* TCP_OVERSIZE */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#if TCP_CHECKSUM_ON_COPY
#endif /* TCP_CHECKSUM_ON_COPY */
#if TCP_OVERSIZE
#endif /* TCP_OVERSIZE */
#if LWIP_WND_SCALE
#endif /* LWIP_WND_SCALE */
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#if LWIP_TCP_TIMESTAMPS
#endif /* LWIP_TCP_TIMESTAMPS */
#if TCP_OVERSIZE
#endif /* TCP_OVERSIZE */
#if LWIP_TCP_TIMESTAMPS
#endif
#if LWIP_TCP_SACK_OUT
#endif
#if LWIP_WND_SCALE
#endif
#if TCP_CWND_DEBUG
#endif /* TCP_CWND_DEBUG */
#if TCP_CWND_DEBUG
#endif /* TCP_CWND_DEBUG */
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#if TCP_OVERSIZE
#endif /* TCP_OVERSIZE */
#if TCP_CHECKSUM_ON_COPY
#endif
#if LWIP_WND_SCALE
#endif /* LWIP_WND_SCALE */
#if TCP_CALCULATE_EFF_SEND_MSS
#else /* TCP_CALCULATE_EFF_SEND_MSS */
#endif /* TCP_CALCULATE_EFF_SEND_MSS */
#if LWIP_TCP_TIMESTAMPS
#endif
#if LWIP_WND_SCALE
#endif
#if LWIP_TCP_SACK_OUT
#endif
#ifdef LWIP_HOOK_TCP_OUT_ADD_TCPOPTS
#endif
#if CHECKSUM_GEN_TCP
#if TCP_CHECKSUM_ON_COPY
#if TCP_CHECKSUM_ON_COPY_SANITY_CHECK
#endif /* TCP_CHECKSUM_ON_COPY_SANITY_CHECK */
#if TCP_CHECKSUM_ON_COPY_SANITY_CHECK
#endif /* TCP_CHECKSUM_ON_COPY_SANITY_CHECK */
#else /* TCP_CHECKSUM_ON_COPY */
#endif /* TCP_CHECKSUM_ON_COPY */
#endif /* CHECKSUM_GEN_TCP */
#if TCP_CHECKSUM_ON_COPY
#endif
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#if TCP_OVERSIZE
#endif /* TCP_OVERSIZE */
tcp_output_alloc_header_common(u32_t ackno, u16_t optlen, u16_t datalen,
                        u32_t seqno_be /* already in network byte order */,
                        u16_t src_port, u16_t dst_port, u8_t flags, u16_t wnd)
{
  struct tcp_hdr *tcphdr;
  struct pbuf *p;

  p = pbuf_alloc(PBUF_IP, TCP_HLEN + optlen + datalen, PBUF_RAM);
  if (p != NULL) {
    LWIP_ASSERT("check that first pbuf can hold struct tcp_hdr",
                (p->len >= TCP_HLEN + optlen));
    tcphdr = (struct tcp_hdr *)p->payload;
    tcphdr->src = lwip_htons(src_port);
    tcphdr->dest = lwip_htons(dst_port);
    tcphdr->seqno = seqno_be;
    tcphdr->ackno = lwip_htonl(ackno);
    TCPH_HDRLEN_FLAGS_SET(tcphdr, (5 + optlen / 4), flags);
    tcphdr->wnd = lwip_htons(wnd);
    tcphdr->chksum = 0;
    tcphdr->urgp = 0;
  }
  return p;
}
tcp_output_alloc_header(struct tcp_pcb *pcb, u16_t optlen, u16_t datalen,
                        u32_t seqno_be /* already in network byte order */)
{
  struct pbuf *p;

  LWIP_ASSERT("tcp_output_alloc_header: invalid pcb", pcb != NULL);

  p = tcp_output_alloc_header_common(pcb->rcv_nxt, optlen, datalen,
    seqno_be, pcb->local_port, pcb->remote_port, TCP_ACK,
    TCPWND_MIN16(RCV_WND_SCALE(pcb, pcb->rcv_ann_wnd)));
  if (p != NULL) {
    /* If we're sending a packet, update the announced right window edge */
    pcb->rcv_ann_right_edge = pcb->rcv_nxt + pcb->rcv_ann_wnd;
  }
  return p;
}
#if LWIP_TCP_TIMESTAMPS
#endif
#if LWIP_TCP_SACK_OUT
#else
#endif
#ifdef LWIP_HOOK_TCP_OUT_ADD_TCPOPTS
#endif
#if CHECKSUM_GEN_TCP
#endif
#if LWIP_WND_SCALE
#else
#endif
#if LWIP_TCP_TIMESTAMPS
#endif
#if LWIP_TCP_SACK_OUT
#endif
#if LWIP_TCP_TIMESTAMPS
#endif
#endif /* LWIP_TCP */
