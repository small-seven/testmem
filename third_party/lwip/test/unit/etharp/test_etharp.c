#include "test_etharp.h"
#include "lwip/udp.h"
#include "lwip/etharp.h"
#include "netif/ethernet.h"
#include "lwip/stats.h"
#include "lwip/prot/iana.h"
#if !LWIP_STATS || !UDP_STATS || !MEMP_STATS || !ETHARP_STATS
#error "This tests needs UDP-, MEMP- and ETHARP-statistics enabled"
#endif
#if !ETHARP_SUPPORT_STATIC_ENTRIES
#error "This test needs ETHARP_SUPPORT_STATIC_ENTRIES enabled"
#endif
default_netif_remove(void)
{
  fail_unless(netif_default == &test_netif);
  netif_remove(&test_netif);
}
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
