#include "test_ip6.h"
#include "lwip/ethip6.h"
#include "lwip/ip6.h"
#include "lwip/inet_chksum.h"
#include "lwip/nd6.h"
#include "lwip/stats.h"
#include "lwip/prot/ethernet.h"
#include "lwip/prot/ip.h"
#include "lwip/prot/ip6.h"
#include "lwip/tcpip.h"
#if LWIP_IPV6 /* allow to build the unit tests without IPv6 support */
default_netif_remove(void)
{
  fail_unless(netif_default == &test_netif6);
  netif_remove(&test_netif6);
}
#if LWIP_IPV6_SCOPES
#endif
#if LWIP_IPV6_SCOPES
#endif
#else /* LWIP_IPV6 */
#endif /* LWIP_IPV6 */
