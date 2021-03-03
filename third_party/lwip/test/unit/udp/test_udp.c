#include "test_udp.h"
#include "lwip/udp.h"
#include "lwip/stats.h"
#include "lwip/inet_chksum.h"
#if !LWIP_STATS || !UDP_STATS || !MEMP_STATS
#error "This tests needs UDP- and MEMP-statistics enabled"
#endif
#if LWIP_HAVE_LOOPIF
#else
#endif
default_netif_remove(void)
{
  fail_unless(netif_default == &test_netif1);
  netif_remove(&test_netif1);
  netif_remove(&test_netif2);
  fail_unless(netif_default == NULL);
#if LWIP_HAVE_LOOPIF
  fail_unless(netif_list != NULL); /* the loopif */
  fail_unless(netif_list->next == NULL);
#else
  fail_unless(netif_list == NULL);
#endif
}
#if SO_REUSE
#endif
#if SO_REUSE
#endif
#if SO_REUSE
#endif
#if SO_REUSE
#endif
#if SO_REUSE
#endif
#if SO_REUSE
#endif
#if SO_REUSE
#endif
#if SO_REUSE
#endif
