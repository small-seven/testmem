#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && ECP_SUPPORT  /* don't build if not configured for use in lwipopts.h */
#include <string.h>
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/fsm.h"
#include "netif/ppp/ecp.h"
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PPP_DATAINPUT
#endif /* PPP_DATAINPUT */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if 0 /* Not necessary, everything is cleared in ppp_new() */
#endif /* 0 */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#endif /* PPP_SUPPORT && ECP_SUPPORT */
