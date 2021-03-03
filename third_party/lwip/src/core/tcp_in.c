#include "lwip/opt.h"
#if LWIP_TCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/priv/tcp_priv.h"
#include "lwip/def.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/inet_chksum.h"
#include "lwip/stats.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#if LWIP_ND6_TCP_REACHABILITY_HINTS
#include "lwip/nd6.h"
#endif /* LWIP_ND6_TCP_REACHABILITY_HINTS */
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#define LWIP_TCP_CALC_INITIAL_CWND(mss) ((tcpwnd_size_t)LWIP_MIN((4U * (mss)), LWIP_MAX((2U * (mss)), 4380U)))
#if LWIP_TCP_SACK_OUT
#if defined(TCP_OOSEQ_BYTES_LIMIT) || defined(TCP_OOSEQ_PBUFS_LIMIT)
#endif /* TCP_OOSEQ_BYTES_LIMIT || TCP_OOSEQ_PBUFS_LIMIT */
#endif /* LWIP_TCP_SACK_OUT */
#if SO_REUSE
#endif /* SO_REUSE */
#if TCP_INPUT_DEBUG
#endif
#if CHECKSUM_CHECK_TCP
#endif /* CHECKSUM_CHECK_TCP */
#ifdef LWIP_HOOK_TCP_INPACKET_PCB
#endif
#if SO_REUSE
#else /* SO_REUSE */
#endif /* SO_REUSE */
#if SO_REUSE
#else /* SO_REUSE */
#endif /* SO_REUSE */
#if SO_REUSE
#endif /* SO_REUSE */
#ifdef LWIP_HOOK_TCP_INPACKET_PCB
#endif
#if TCP_INPUT_DEBUG
#endif /* TCP_INPUT_DEBUG */
#ifdef LWIP_HOOK_TCP_INPACKET_PCB
#endif
#if TCP_INPUT_DEBUG
#endif /* TCP_INPUT_DEBUG */
#if LWIP_WND_SCALE
#else
#endif
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#else /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_INPUT_DEBUG
#if TCP_DEBUG
#endif /* TCP_DEBUG */
#endif /* TCP_INPUT_DEBUG */
#if TCP_LISTEN_BACKLOG
#endif /* TCP_LISTEN_BACKLOG */
#if TCP_LISTEN_BACKLOG
#endif /* TCP_LISTEN_BACKLOG */
#if LWIP_CALLBACK_API || TCP_LISTEN_BACKLOG
#endif /* LWIP_CALLBACK_API || TCP_LISTEN_BACKLOG */
#if TCP_CALCULATE_EFF_SEND_MSS
#endif /* TCP_CALCULATE_EFF_SEND_MSS */
#if LWIP_TCP_PCB_NUM_EXT_ARGS
#endif
#if TCP_CALCULATE_EFF_SEND_MSS
#endif /* TCP_CALCULATE_EFF_SEND_MSS */
#if LWIP_CALLBACK_API || TCP_LISTEN_BACKLOG
#endif /* LWIP_CALLBACK_API || TCP_LISTEN_BACKLOG */
#if LWIP_CALLBACK_API
#endif
#if TCP_QUEUE_OOSEQ
#endif /* TCP_QUEUE_OOSEQ */
tcp_free_acked_segments(struct tcp_pcb *pcb, struct tcp_seg *seg_list, const char *dbg_list_name,
                        struct tcp_seg *dbg_other_seg_list)
{
  struct tcp_seg *next;
  u16_t clen;

  LWIP_UNUSED_ARG(dbg_list_name);
  LWIP_UNUSED_ARG(dbg_other_seg_list);

  while (seg_list != NULL &&
         TCP_SEQ_LEQ(lwip_ntohl(seg_list->tcphdr->seqno) +
                     TCP_TCPLEN(seg_list), ackno)) {
    LWIP_DEBUGF(TCP_INPUT_DEBUG, ("tcp_receive: removing %"U32_F":%"U32_F" from pcb->%s\n",
                                  lwip_ntohl(seg_list->tcphdr->seqno),
                                  lwip_ntohl(seg_list->tcphdr->seqno) + TCP_TCPLEN(seg_list),
                                  dbg_list_name));

    next = seg_list;
    seg_list = seg_list->next;

    clen = pbuf_clen(next->p);
    LWIP_DEBUGF(TCP_QLEN_DEBUG, ("tcp_receive: queuelen %"TCPWNDSIZE_F" ... ",
                                 (tcpwnd_size_t)pcb->snd_queuelen));
    LWIP_ASSERT("pcb->snd_queuelen >= pbuf_clen(next->p)", (pcb->snd_queuelen >= clen));

    pcb->snd_queuelen = (u16_t)(pcb->snd_queuelen - clen);
    recv_acked = (tcpwnd_size_t)(recv_acked + next->len);
    tcp_seg_free(next);

    LWIP_DEBUGF(TCP_QLEN_DEBUG, ("%"TCPWNDSIZE_F" (after freeing %s)\n",
                                 (tcpwnd_size_t)pcb->snd_queuelen,
                                 dbg_list_name));
    if (pcb->snd_queuelen != 0) {
      LWIP_ASSERT("tcp_receive: valid queue length",
                  seg_list != NULL || dbg_other_seg_list != NULL);
    }
  }
  return seg_list;
}
#if TCP_WND_DEBUG
#endif /* TCP_WND_DEBUG */
#if TCP_OVERSIZE
#endif /* TCP_OVERSIZE */
#if LWIP_IPV6 && LWIP_ND6_TCP_REACHABILITY_HINTS
#endif /* LWIP_IPV6 && LWIP_ND6_TCP_REACHABILITY_HINTS*/
#if TCP_QUEUE_OOSEQ
#endif /* TCP_QUEUE_OOSEQ */
#if TCP_QUEUE_OOSEQ
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#endif /* TCP_QUEUE_OOSEQ */
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#if LWIP_IPV6 && LWIP_ND6_TCP_REACHABILITY_HINTS
#endif /* LWIP_IPV6 && LWIP_ND6_TCP_REACHABILITY_HINTS*/
#if TCP_QUEUE_OOSEQ
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#if defined(TCP_OOSEQ_BYTES_LIMIT) || defined(TCP_OOSEQ_PBUFS_LIMIT)
#ifdef TCP_OOSEQ_BYTES_LIMIT
#endif
#ifdef TCP_OOSEQ_PBUFS_LIMIT
#endif
#ifdef TCP_OOSEQ_BYTES_LIMIT
#endif
#ifdef TCP_OOSEQ_PBUFS_LIMIT
#endif
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#endif /* TCP_OOSEQ_BYTES_LIMIT || TCP_OOSEQ_PBUFS_LIMIT */
#endif /* TCP_QUEUE_OOSEQ */
#if LWIP_TCP_TIMESTAMPS
#endif
#if LWIP_WND_SCALE
#endif /* LWIP_WND_SCALE */
#if LWIP_TCP_TIMESTAMPS
#endif /* LWIP_TCP_TIMESTAMPS */
#if LWIP_TCP_SACK_OUT
#endif /* LWIP_TCP_SACK_OUT */
#if LWIP_TCP_SACK_OUT
#if defined(TCP_OOSEQ_BYTES_LIMIT) || defined(TCP_OOSEQ_PBUFS_LIMIT)
#endif /* TCP_OOSEQ_BYTES_LIMIT || TCP_OOSEQ_PBUFS_LIMIT */
#endif /* LWIP_TCP_SACK_OUT */
#endif /* LWIP_TCP */
