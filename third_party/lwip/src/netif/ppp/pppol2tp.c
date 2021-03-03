#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && PPPOL2TP_SUPPORT /* don't build if not configured for use in lwipopts.h */
#include "lwip/err.h"
#include "lwip/memp.h"
#include "lwip/netif.h"
#include "lwip/udp.h"
#include "lwip/snmp.h"
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/lcp.h"
#include "netif/ppp/ipcp.h"
#include "netif/ppp/pppol2tp.h"
#include "netif/ppp/pppcrypt.h"
#include "netif/ppp/magic.h"
#if PPP_SERVER
#endif /* PPP_SERVER */
#if !PPPOL2TP_AUTH_SUPPORT
#endif /* !PPPOL2TP_AUTH_SUPPORT */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
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
#if PPP_IPV4_SUPPORT && VJ_SUPPORT
#endif /* PPP_IPV4_SUPPORT && VJ_SUPPORT */
#if PPP_IPV4_SUPPORT && VJ_SUPPORT
#endif /* PPP_IPV4_SUPPORT && VJ_SUPPORT */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
#endif /* PPP_SUPPORT && PPPOL2TP_SUPPORT */
