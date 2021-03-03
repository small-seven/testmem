#include "lwip/opt.h"
#if LWIP_TCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/tcp.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#include "lwip/nd6.h"
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#ifndef TCP_LOCAL_PORT_RANGE_START
#define TCP_LOCAL_PORT_RANGE_START        0xc000
#define TCP_LOCAL_PORT_RANGE_END          0xffff
#define TCP_ENSURE_LOCAL_PORT_RANGE(port) ((u16_t)(((port) & (u16_t)~TCP_LOCAL_PORT_RANGE_START) + TCP_LOCAL_PORT_RANGE_START))
#endif
#if LWIP_TCP_KEEPALIVE
#define TCP_KEEP_DUR(pcb)   ((pcb)->keep_cnt * (pcb)->keep_intvl)
#define TCP_KEEP_INTVL(pcb) ((pcb)->keep_intvl)
#else /* LWIP_TCP_KEEPALIVE */
#define TCP_KEEP_DUR(pcb)   TCP_MAXIDLE
#define TCP_KEEP_INTVL(pcb) TCP_KEEPINTVL_DEFAULT
#endif /* LWIP_TCP_KEEPALIVE */
#if TCP_MSS > 536
#define INITIAL_MSS 536
#else
#define INITIAL_MSS TCP_MSS
#endif
#if LWIP_TCP_PCB_NUM_EXT_ARGS
#endif
#ifdef LWIP_RAND
#endif /* LWIP_RAND */
tcp_free(struct tcp_pcb *pcb)
{
  LWIP_ASSERT("tcp_free: LISTEN", pcb->state != LISTEN);
#if LWIP_TCP_PCB_NUM_EXT_ARGS
  tcp_ext_arg_invoke_callbacks_destroyed(pcb->ext_args);
#endif
  memp_free(MEMP_TCP_PCB, pcb);
}
tcp_free_listen(struct tcp_pcb *pcb)
{
  LWIP_ASSERT("tcp_free_listen: !LISTEN", pcb->state != LISTEN);
#if LWIP_TCP_PCB_NUM_EXT_ARGS
  tcp_ext_arg_invoke_callbacks_destroyed(pcb->ext_args);
#endif
  memp_free(MEMP_TCP_PCB_LISTEN, pcb);
}
#if LWIP_CALLBACK_API || TCP_LISTEN_BACKLOG
tcp_remove_listener(struct tcp_pcb *list, struct tcp_pcb_listen *lpcb)
{
  struct tcp_pcb *pcb;

  LWIP_ASSERT("tcp_remove_listener: invalid listener", lpcb != NULL);

  for (pcb = list; pcb != NULL; pcb = pcb->next) {
    if (pcb->listener == lpcb) {
      pcb->listener = NULL;
    }
  }
}
#endif
#if LWIP_CALLBACK_API || TCP_LISTEN_BACKLOG
#endif
#if TCP_LISTEN_BACKLOG
#endif /* TCP_LISTEN_BACKLOG */
#if LWIP_CALLBACK_API
#endif /* LWIP_CALLBACK_API */
#if LWIP_CALLBACK_API
#endif /* LWIP_CALLBACK_API */
#if TCP_QUEUE_OOSEQ
#endif /* TCP_QUEUE_OOSEQ */
#if LWIP_IPV6 && LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6 && LWIP_IPV6_SCOPES */
#if LWIP_IPV4
#else /* LWIP_IPV4 */
#endif /* LWIP_IPV4 */
#if SO_REUSE
#endif /* SO_REUSE */
#if LWIP_IPV6 && LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6 && LWIP_IPV6_SCOPES */
#if SO_REUSE
#endif /* SO_REUSE */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_CALLBACK_API
#endif /* LWIP_CALLBACK_API */
#if SO_REUSE
#endif /* SO_REUSE */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_TCP_PCB_NUM_EXT_ARGS
#endif
#if LWIP_CALLBACK_API
#endif /* LWIP_CALLBACK_API */
#if TCP_LISTEN_BACKLOG
#endif /* TCP_LISTEN_BACKLOG */
#if !LWIP_WND_SCALE
#endif
#if LWIP_IPV6 && LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6 && LWIP_IPV6_SCOPES */
#if SO_REUSE
#endif /* SO_REUSE */
#if TCP_CALCULATE_EFF_SEND_MSS
#endif /* TCP_CALCULATE_EFF_SEND_MSS */
#if LWIP_CALLBACK_API
#else /* LWIP_CALLBACK_API */
#endif /* LWIP_CALLBACK_API */
#if TCP_QUEUE_OOSEQ
#endif /* TCP_QUEUE_OOSEQ */
#if LWIP_CALLBACK_API
#endif /* LWIP_CALLBACK_API */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#else /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
tcp_segs_free(struct tcp_seg *seg)
{
  while (seg != NULL) {
    struct tcp_seg *next = seg->next;
    tcp_seg_free(seg);
    seg = next;
  }
}
tcp_seg_free(struct tcp_seg *seg)
{
  if (seg != NULL) {
    if (seg->p != NULL) {
      pbuf_free(seg->p);
#if TCP_DEBUG
      seg->p = NULL;
#endif /* TCP_DEBUG */
    }
    memp_free(MEMP_TCP_SEG, seg);
  }
}
#if TCP_QUEUE_OOSEQ
#endif /* TCP_QUEUE_OOSEQ */
#if LWIP_CALLBACK_API
#endif /* LWIP_CALLBACK_API */
tcp_alloc(u8_t prio)
{
  struct tcp_pcb *pcb;

  LWIP_ASSERT_CORE_LOCKED();

  pcb = (struct tcp_pcb *)memp_malloc(MEMP_TCP_PCB);
  if (pcb == NULL) {
    /* Try to send FIN for all pcbs stuck in TF_CLOSEPEND first */
    tcp_handle_closepend();

    /* Try killing oldest connection in TIME-WAIT. */
    LWIP_DEBUGF(TCP_DEBUG, ("tcp_alloc: killing off oldest TIME-WAIT connection\n"));
    tcp_kill_timewait();
    /* Try to allocate a tcp_pcb again. */
    pcb = (struct tcp_pcb *)memp_malloc(MEMP_TCP_PCB);
    if (pcb == NULL) {
      /* Try killing oldest connection in LAST-ACK (these wouldn't go to TIME-WAIT). */
      LWIP_DEBUGF(TCP_DEBUG, ("tcp_alloc: killing off oldest LAST-ACK connection\n"));
      tcp_kill_state(LAST_ACK);
      /* Try to allocate a tcp_pcb again. */
      pcb = (struct tcp_pcb *)memp_malloc(MEMP_TCP_PCB);
      if (pcb == NULL) {
        /* Try killing oldest connection in CLOSING. */
        LWIP_DEBUGF(TCP_DEBUG, ("tcp_alloc: killing off oldest CLOSING connection\n"));
        tcp_kill_state(CLOSING);
        /* Try to allocate a tcp_pcb again. */
        pcb = (struct tcp_pcb *)memp_malloc(MEMP_TCP_PCB);
        if (pcb == NULL) {
          /* Try killing oldest active connection with lower priority than the new one. */
          LWIP_DEBUGF(TCP_DEBUG, ("tcp_alloc: killing oldest connection with prio lower than %d\n", prio));
          tcp_kill_prio(prio);
          /* Try to allocate a tcp_pcb again. */
          pcb = (struct tcp_pcb *)memp_malloc(MEMP_TCP_PCB);
          if (pcb != NULL) {
            /* adjust err stats: memp_malloc failed multiple times before */
            MEMP_STATS_DEC(err, MEMP_TCP_PCB);
          }
        }
        if (pcb != NULL) {
          /* adjust err stats: memp_malloc failed multiple times before */
          MEMP_STATS_DEC(err, MEMP_TCP_PCB);
        }
      }
      if (pcb != NULL) {
        /* adjust err stats: memp_malloc failed multiple times before */
        MEMP_STATS_DEC(err, MEMP_TCP_PCB);
      }
    }
    if (pcb != NULL) {
      /* adjust err stats: memp_malloc failed above */
      MEMP_STATS_DEC(err, MEMP_TCP_PCB);
    }
  }
  if (pcb != NULL) {
    /* zero out the whole pcb, so there is no need to initialize members to zero */
    memset(pcb, 0, sizeof(struct tcp_pcb));
    pcb->prio = prio;
    pcb->snd_buf = TCP_SND_BUF;
    /* Start with a window that does not need scaling. When window scaling is
       enabled and used, the window is enlarged when both sides agree on scaling. */
    pcb->rcv_wnd = pcb->rcv_ann_wnd = TCPWND_MIN16(TCP_WND);
    pcb->ttl = TCP_TTL;
    /* As initial send MSS, we use TCP_MSS but limit it to 536.
       The send MSS is updated when an MSS option is received. */
    pcb->mss = INITIAL_MSS;
    pcb->rto = 3000 / TCP_SLOW_INTERVAL;
    pcb->sv = 3000 / TCP_SLOW_INTERVAL;
    pcb->rtime = -1;
    pcb->cwnd = 1;
    pcb->tmr = tcp_ticks;
    pcb->last_timer = tcp_timer_ctr;

    /* RFC 5681 recommends setting ssthresh abritrarily high and gives an example
    of using the largest advertised receive window.  We've seen complications with
    receiving TCPs that use window scaling and/or window auto-tuning where the
    initial advertised window is very small and then grows rapidly once the
    connection is established. To avoid these complications, we set ssthresh to the
    largest effective cwnd (amount of in-flight data) that the sender can have. */
    pcb->ssthresh = TCP_SND_BUF;

#if LWIP_CALLBACK_API
    pcb->recv = tcp_recv_null;
#endif /* LWIP_CALLBACK_API */

    /* Init KEEPALIVE timer */
    pcb->keep_idle  = TCP_KEEPIDLE_DEFAULT;

#if LWIP_TCP_KEEPALIVE
    pcb->keep_intvl = TCP_KEEPINTVL_DEFAULT;
    pcb->keep_cnt   = TCP_KEEPCNT_DEFAULT;
#endif /* LWIP_TCP_KEEPALIVE */
  }
  return pcb;
}
#if LWIP_IPV4 && LWIP_IPV6
#else
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_CALLBACK_API
#endif /* LWIP_CALLBACK_API */
#if LWIP_CALLBACK_API
#else /* LWIP_CALLBACK_API */
#endif /* LWIP_CALLBACK_API */
#if TCP_QUEUE_OOSEQ
#endif /* TCP_QUEUE_OOSEQ */
#if TCP_OVERSIZE
#endif /* TCP_OVERSIZE */
tcp_pcb_remove(struct tcp_pcb **pcblist, struct tcp_pcb *pcb)
{
  LWIP_ASSERT("tcp_pcb_remove: invalid pcb", pcb != NULL);
  LWIP_ASSERT("tcp_pcb_remove: invalid pcblist", pcblist != NULL);

  TCP_RMV(pcblist, pcb);

  tcp_pcb_purge(pcb);

  /* if there is an outstanding delayed ACKs, send it */
  if ((pcb->state != TIME_WAIT) &&
      (pcb->state != LISTEN) &&
      (pcb->flags & TF_ACK_DELAY)) {
    tcp_ack_now(pcb);
    tcp_output(pcb);
  }

  if (pcb->state != LISTEN) {
    LWIP_ASSERT("unsent segments leaking", pcb->unsent == NULL);
    LWIP_ASSERT("unacked segments leaking", pcb->unacked == NULL);
#if TCP_QUEUE_OOSEQ
    LWIP_ASSERT("ooseq segments leaking", pcb->ooseq == NULL);
#endif /* TCP_QUEUE_OOSEQ */
  }

  pcb->state = CLOSED;
  /* reset the local port to prevent the pcb from being 'bound' */
  pcb->local_port = 0;

  LWIP_ASSERT("tcp_pcb_remove: tcp_pcbs_sane()", tcp_pcbs_sane());
}
#ifdef LWIP_HOOK_TCP_ISN
#else /* LWIP_HOOK_TCP_ISN */
#endif /* LWIP_HOOK_TCP_ISN */
#if TCP_CALCULATE_EFF_SEND_MSS
#if LWIP_IPV6
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#endif /* TCP_CALCULATE_EFF_SEND_MSS */
#if LWIP_AUTOIP
#endif /* LWIP_AUTOIP */
#if TCP_QUEUE_OOSEQ
tcp_free_ooseq(struct tcp_pcb *pcb)
{
  if (pcb->ooseq) {
    tcp_segs_free(pcb->ooseq);
    pcb->ooseq = NULL;
#if LWIP_TCP_SACK_OUT
    memset(pcb->rcv_sacks, 0, sizeof(pcb->rcv_sacks));
#endif /* LWIP_TCP_SACK_OUT */
  }
}
#endif /* TCP_QUEUE_OOSEQ */
#if TCP_DEBUG || TCP_INPUT_DEBUG || TCP_OUTPUT_DEBUG
#endif /* TCP_DEBUG */
#if LWIP_TCP_PCB_NUM_EXT_ARGS
#if LWIP_TCP_PCB_NUM_EXT_ARGS >= 255
#error LWIP_TCP_PCB_NUM_EXT_ARGS
#endif
#endif /* LWIP_TCP_PCB_NUM_EXT_ARGS */
#endif /* LWIP_TCP */
