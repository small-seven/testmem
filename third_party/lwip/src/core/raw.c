#include "lwip/opt.h"
#if LWIP_RAW /* don't build if not configured for use in lwipopts.h */
#include "lwip/def.h"
#include "lwip/memp.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/raw.h"
#include "lwip/priv/raw_priv.h"
#include "lwip/stats.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#include "lwip/inet_chksum.h"
#include <string.h>
#if LWIP_IPV4 && LWIP_IPV6
#if IP_SOF_BROADCAST_RECV
#endif /* IP_SOF_BROADCAST_RECV */
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IPV4
#if IP_SOF_BROADCAST_RECV
#endif /* IP_SOF_BROADCAST_RECV */
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#ifndef LWIP_NOASSERT
#endif
#if LWIP_IPV6 && LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6 && LWIP_IPV6_SCOPES */
#if LWIP_IPV6 && LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6 && LWIP_IPV6_SCOPES */
#if LWIP_IPV4 && LWIP_IPV6
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#elif LWIP_IPV4
#else
#endif
#if IP_SOF_BROADCAST
#endif /* IP_SOF_BROADCAST */
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#if LWIP_IPV6
#endif
#if LWIP_MULTICAST_TX_OPTIONS
#else /* LWIP_MULTICAST_TX_OPTIONS */
#endif /* LWIP_MULTICAST_TX_OPTIONS */
raw_remove(struct raw_pcb *pcb)
{
  struct raw_pcb *pcb2;
  LWIP_ASSERT_CORE_LOCKED();
  /* pcb to be removed is first in list? */
  if (raw_pcbs == pcb) {
    /* make list start at 2nd pcb */
    raw_pcbs = raw_pcbs->next;
    /* pcb not 1st in list */
  } else {
    for (pcb2 = raw_pcbs; pcb2 != NULL; pcb2 = pcb2->next) {
      /* find pcb in raw_pcbs list */
      if (pcb2->next != NULL && pcb2->next == pcb) {
        /* remove pcb from list */
        pcb2->next = pcb->next;
        break;
      }
    }
  }
  memp_free(MEMP_RAW_PCB, pcb);
}
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#if LWIP_IPV4 && LWIP_IPV6
#else /* LWIP_IPV4 && LWIP_IPV6 */
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#endif /* LWIP_RAW */
