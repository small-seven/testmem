#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && PPPOS_SUPPORT /* don't build if not configured for use in lwipopts.h */
#include <string.h>
#include "lwip/arch.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/sys.h"
#include "lwip/memp.h"
#include "lwip/netif.h"
#include "lwip/snmp.h"
#include "lwip/priv/tcpip_priv.h"
#include "lwip/api.h"
#include "lwip/ip4.h" /* for ip4_input() */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/pppos.h"
#include "netif/ppp/vj.h"
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_INPROC_IRQ_SAFE
#endif /* PPP_INPROC_IRQ_SAFE */
#if PPP_SERVER
#endif /* PPP_SERVER */
#define ESCAPE_P(accm, c) ((accm)[(c) >> 3] & 1 << (c & 0x07))
#if PPP_FCS_TABLE
#define PPP_FCS(fcs, c) (((fcs) >> 8) ^ fcstab[((fcs) ^ (c)) & 0xff])
#else /* PPP_FCS_TABLE */
#define PPP_FCS_POLYNOMIAL 0x8408
#define PPP_FCS(fcs, c) (((fcs) >> 8) ^ ppp_get_fcs(((fcs) ^ (c)) & 0xff))
#endif /* PPP_FCS_TABLE */
#define PPP_INITFCS     0xffff  /* Initial FCS value */
#define PPP_GOODFCS     0xf0b8  /* Good final FCS value */
#if PPP_INPROC_IRQ_SAFE
#define PPPOS_DECL_PROTECT(lev) SYS_ARCH_DECL_PROTECT(lev)
#define PPPOS_PROTECT(lev) SYS_ARCH_PROTECT(lev)
#define PPPOS_UNPROTECT(lev) SYS_ARCH_UNPROTECT(lev)
#else
#define PPPOS_DECL_PROTECT(lev)
#define PPPOS_PROTECT(lev)
#define PPPOS_UNPROTECT(lev)
#endif /* PPP_INPROC_IRQ_SAFE */
#if PPP_INPROC_IRQ_SAFE
#endif /* PPP_INPROC_IRQ_SAFE */
#if PPP_SERVER
#if PPP_INPROC_IRQ_SAFE
#endif /* PPP_INPROC_IRQ_SAFE */
#endif /* PPP_SERVER */
#if !PPP_INPROC_IRQ_SAFE
#endif /* !PPP_INPROC_IRQ_SAFE */
pppos_destroy(ppp_pcb *ppp, void *ctx)
{
  pppos_pcb *pppos = (pppos_pcb *)ctx;
  LWIP_UNUSED_ARG(ppp);

#if PPP_INPROC_IRQ_SAFE
  /* input pbuf left ? */
  pppos_input_free_current_packet(pppos);
#endif /* PPP_INPROC_IRQ_SAFE */

  LWIP_MEMPOOL_FREE(PPPOS_PCB, pppos);
  return ERR_OK;
}
#if !NO_SYS && !PPP_INPROC_IRQ_SAFE
#endif /* !NO_SYS && !PPP_INPROC_IRQ_SAFE */
#if PPP_INPROC_IRQ_SAFE
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif
#endif /* PPP_INPROC_IRQ_SAFE */
#if !PPP_INPROC_IRQ_SAFE
#endif
#if IP_FORWARD || LWIP_IPV6_FORWARD
#endif /* IP_FORWARD || LWIP_IPV6_FORWARD */
#if PPP_INPROC_IRQ_SAFE
#else /* PPP_INPROC_IRQ_SAFE */
#endif /* PPP_INPROC_IRQ_SAFE */
#if 0
#endif
#if IP_FORWARD || LWIP_IPV6_FORWARD
#endif /* IP_FORWARD || LWIP_IPV6_FORWARD */
#if PPP_INPROC_IRQ_SAFE
#endif /* PPP_INPROC_IRQ_SAFE */
#if PPP_INPROC_IRQ_SAFE
#endif /* PPP_INPROC_IRQ_SAFE */
#if 0
#endif
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#endif /* PPP_SUPPORT && PPPOS_SUPPORT */
