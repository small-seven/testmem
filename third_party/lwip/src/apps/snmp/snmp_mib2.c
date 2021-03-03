#include "lwip/apps/snmp_opts.h"
#if LWIP_SNMP && SNMP_LWIP_MIB2 /* don't build if not configured for use in lwipopts.h */
#if !LWIP_STATS
#error LWIP_SNMP MIB2 needs LWIP_STATS (for MIB2)
#endif
#if !MIB2_STATS
#error LWIP_SNMP MIB2 needs MIB2_STATS (for MIB2)
#endif
#include "lwip/snmp.h"
#include "lwip/apps/snmp.h"
#include "lwip/apps/snmp_core.h"
#include "lwip/apps/snmp_mib2.h"
#include "lwip/apps/snmp_scalar.h"
#if SNMP_USE_NETCONN
#include "lwip/tcpip.h"
#include "lwip/priv/tcpip_priv.h"
#if LWIP_TCPIP_CORE_LOCKING
#else
#endif
#endif
#if LWIP_ARP && LWIP_IPV4
#endif /* LWIP_ARP && LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_ICMP
#endif /* LWIP_ICMP */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_UDP
#endif /* LWIP_UDP */
#endif /* LWIP_SNMP && SNMP_LWIP_MIB2 */
