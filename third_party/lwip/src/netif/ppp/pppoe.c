#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && PPPOE_SUPPORT /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <string.h>
#include <stdio.h>
#endif /* UNUSED */
#include "lwip/timeouts.h"
#include "lwip/memp.h"
#include "lwip/stats.h"
#include "lwip/snmp.h"
#include "netif/ethernet.h"
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/lcp.h"
#include "netif/ppp/ipcp.h"
#include "netif/ppp/pppoe.h"
#define PPPOE_ADD_16(PTR, VAL) \
#define PPPOE_ADD_HEADER(PTR, CODE, SESS, LEN)  \
#define PPPOE_DISC_TIMEOUT (5*1000)  /* base for quick timeout calculation */
#define PPPOE_SLOW_RETRY   (60*1000) /* persistent retry interval */
#define PPPOE_DISC_MAXPADI  4        /* retry PADI four times (quickly) */
#define PPPOE_DISC_MAXPADR  2        /* retry PADR twice */
#ifdef PPPOE_SERVER
#error "PPPOE_SERVER is not yet supported under lwIP!"
#define IFF_PASSIVE IFF_LINK0 /* wait passively for connection */
#endif
#define PPPOE_ERRORSTRING_LEN     64
#if 0 /* UNUSED */
#endif /* UNUSED */
#ifdef PPPOE_SERVER
#endif
#if PPP_SERVER
#endif /* PPP_SERVER */
#if MIB2_STATS
#else /* MIB2_STATS */
#endif /* MIB2_STATS */
#if MIB2_STATS
#endif /* MIB2_STATS */
#if MIB2_STATS
#else /* MIB2_STATS */
#endif /* MIB2_STATS */
#if MIB2_STATS
#endif /* MIB2_STATS */
pppoe_destroy(ppp_pcb *ppp, void *ctx)
{
  struct pppoe_softc *sc = (struct pppoe_softc *)ctx;
  struct pppoe_softc **copp, *freep;
  LWIP_UNUSED_ARG(ppp);

  sys_untimeout(pppoe_timeout, sc);

  /* remove interface from list */
  for (copp = &pppoe_softc_list; (freep = *copp); copp = &freep->next) {
    if (freep == sc) {
       *copp = freep->next;
       break;
    }
  }

#ifdef PPPOE_TODO
  if (sc->sc_concentrator_name) {
    mem_free(sc->sc_concentrator_name);
  }
  if (sc->sc_service_name) {
    mem_free(sc->sc_service_name);
  }
#endif /* PPPOE_TODO */
  LWIP_MEMPOOL_FREE(PPPOE_IF, sc);

  return ERR_OK;
}
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#ifdef PPPOE_SERVER
#endif
#ifdef PPPOE_SERVER
#endif
#ifdef PPPOE_SERVER
#endif
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#ifdef PPPOE_SERVER
#endif /* PPPOE_SERVER */
#ifdef PPPOE_SERVER
#else
#endif /* PPPOE_SERVER */
#if 0 /* UNUSED */
#endif /* UNUSED */
#ifdef PPPOE_TERM_UNKNOWN_SESSIONS
#endif
#ifdef PPPOE_TERM_UNKNOWN_SESSIONS
#endif
#ifdef PPPOE_TERM_UNKNOWN_SESSIONS
#endif
#ifdef PPPOE_TODO
#endif /* PPPOE_TODO */
#ifdef PPPOE_TODO
#endif /* PPPOE_TODO */
#ifdef PPPOE_TODO
#endif /* PPPOE_TODO */
#ifdef PPPOE_TODO
#endif /* PPPOE_TODO */
#if 0
#endif
#if PPP_IPV4_SUPPORT && VJ_SUPPORT
#endif /* PPP_IPV4_SUPPORT && VJ_SUPPORT */
#ifdef PPPOE_SERVER
#endif
#if PPP_IPV4_SUPPORT && VJ_SUPPORT
#endif /* PPP_IPV4_SUPPORT && VJ_SUPPORT */
#ifdef PPPOE_SERVER
#endif
#ifdef PPPOE_TODO
#endif /* PPPOE_TODO */
#ifdef PPPOE_TODO
#endif /* PPPOE_TODO */
#ifdef PPPOE_TODO
#endif /* PPPOE_TODO */
#ifdef PPPOE_SERVER
#endif
#if 0 /*def PFIL_HOOKS*/
#endif
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_SUPPORT && PPPOE_SUPPORT */
