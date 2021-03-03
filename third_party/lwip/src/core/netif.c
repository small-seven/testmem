#include "lwip/opt.h"
#include <string.h> /* memset */
#include <stdlib.h> /* atoi */
#include "lwip/def.h"
#include "lwip/ip_addr.h"
#include "lwip/ip6_addr.h"
#include "lwip/netif.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/udp.h"
#include "lwip/priv/raw_priv.h"
#include "lwip/snmp.h"
#include "lwip/igmp.h"
#include "lwip/etharp.h"
#include "lwip/stats.h"
#include "lwip/sys.h"
#include "lwip/ip.h"
#if ENABLE_LOOPBACK
#if LWIP_NETIF_LOOPBACK_MULTITHREADING
#include "lwip/tcpip.h"
#endif /* LWIP_NETIF_LOOPBACK_MULTITHREADING */
#endif /* ENABLE_LOOPBACK */
#include "netif/ethernet.h"
#if LWIP_AUTOIP
#include "lwip/autoip.h"
#endif /* LWIP_AUTOIP */
#if LWIP_DHCP
#include "lwip/dhcp.h"
#endif /* LWIP_DHCP */
#if LWIP_IPV6_DHCP6
#include "lwip/dhcp6.h"
#endif /* LWIP_IPV6_DHCP6 */
#if LWIP_IPV6_MLD
#include "lwip/mld6.h"
#endif /* LWIP_IPV6_MLD */
#if LWIP_IPV6
#include "lwip/nd6.h"
#endif
#if LWIP_NETIF_STATUS_CALLBACK
#define NETIF_STATUS_CALLBACK(n) do{ if (n->status_callback) { (n->status_callback)(n); }}while(0)
#else
#define NETIF_STATUS_CALLBACK(n)
#endif /* LWIP_NETIF_STATUS_CALLBACK */
#if LWIP_NETIF_LINK_CALLBACK
#define NETIF_LINK_CALLBACK(n) do{ if (n->link_callback) { (n->link_callback)(n); }}while(0)
#else
#define NETIF_LINK_CALLBACK(n)
#endif /* LWIP_NETIF_LINK_CALLBACK */
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if !LWIP_SINGLE_NETIF
#endif /* !LWIP_SINGLE_NETIF */
#define netif_index_to_num(index)   ((index) - 1)
#if LWIP_NUM_NETIF_CLIENT_DATA > 0
#endif
#define NETIF_REPORT_TYPE_IPV4  0x01
#define NETIF_REPORT_TYPE_IPV6  0x02
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_HAVE_LOOPIF
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_LOOPIF_MULTICAST
#endif
#endif /* LWIP_HAVE_LOOPIF */
#if LWIP_HAVE_LOOPIF
#if LWIP_IPV4
#define LOOPIF_ADDRINIT &loop_ipaddr, &loop_netmask, &loop_gw,
#else /* LWIP_IPV4 */
#define LOOPIF_ADDRINIT
#endif /* LWIP_IPV4 */
#if NO_SYS
#else  /* NO_SYS */
#endif /* NO_SYS */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#endif /* LWIP_HAVE_LOOPIF */
#if LWIP_ETHERNET
#endif /* LWIP_ETHERNET */
#if LWIP_IPV4
#endif /* LWIP_IPV4*/
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif
#if LWIP_SINGLE_NETIF
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#if LWIP_IPV6_ADDRESS_LIFETIMES
#endif /* LWIP_IPV6_ADDRESS_LIFETIMES */
#endif /* LWIP_IPV6 */
#ifdef netif_get_client_data
#endif /* LWIP_NUM_NETIF_CLIENT_DATA */
#if LWIP_IPV6
#if LWIP_IPV6_AUTOCONFIG
#endif /* LWIP_IPV6_AUTOCONFIG */
#endif /* LWIP_IPV6 */
#if LWIP_NETIF_STATUS_CALLBACK
#endif /* LWIP_NETIF_STATUS_CALLBACK */
#if LWIP_NETIF_LINK_CALLBACK
#endif /* LWIP_NETIF_LINK_CALLBACK */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_IPV6 && LWIP_IPV6_MLD
#endif /* LWIP_IPV6 && LWIP_IPV6_MLD */
#if ENABLE_LOOPBACK
#endif /* ENABLE_LOOPBACK */
#if ENABLE_LOOPBACK && LWIP_LOOPBACK_MAX_PBUFS
#endif /* ENABLE_LOOPBACK && LWIP_LOOPBACK_MAX_PBUFS */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6 && LWIP_ND6_ALLOW_RA_UPDATES
#endif /* LWIP_IPV6 && LWIP_ND6_ALLOW_RA_UPDATES */
#if !LWIP_SINGLE_NETIF
#endif /* "LWIP_SINGLE_NETIF */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_IPV4
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#else
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#else
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#else
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#else
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#else
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#endif /* LWIP_IPV4*/
netif_remove(struct netif *netif)
{
#if LWIP_IPV6
  int i;
#endif

  LWIP_ASSERT_CORE_LOCKED();

  if (netif == NULL) {
    return;
  }

  netif_invoke_ext_callback(netif, LWIP_NSC_NETIF_REMOVED, NULL);

#if LWIP_IPV4
  if (!ip4_addr_isany_val(*netif_ip4_addr(netif))) {
    netif_do_ip_addr_changed(netif_ip_addr4(netif), NULL);
  }

#if LWIP_IGMP
  /* stop IGMP processing */
  if (netif->flags & NETIF_FLAG_IGMP) {
    igmp_stop(netif);
  }
#endif /* LWIP_IGMP */
#endif /* LWIP_IPV4*/

#if LWIP_IPV6
  for (i = 0; i < LWIP_IPV6_NUM_ADDRESSES; i++) {
    if (ip6_addr_isvalid(netif_ip6_addr_state(netif, i))) {
      netif_do_ip_addr_changed(netif_ip_addr6(netif, i), NULL);
    }
  }
#if LWIP_IPV6_MLD
  /* stop MLD processing */
  mld6_stop(netif);
#endif /* LWIP_IPV6_MLD */
#endif /* LWIP_IPV6 */
  if (netif_is_up(netif)) {
    /* set netif down before removing (call callback function) */
    netif_set_down(netif);
  }

  mib2_remove_ip4(netif);

  /* this netif is default? */
  if (netif_default == netif) {
    /* reset default netif */
    netif_set_default(NULL);
  }
#if !LWIP_SINGLE_NETIF
  /*  is it the first netif? */
  if (netif_list == netif) {
    netif_list = netif->next;
  } else {
    /*  look for netif further down the list */
    struct netif *tmp_netif;
    NETIF_FOREACH(tmp_netif) {
      if (tmp_netif->next == netif) {
        tmp_netif->next = netif->next;
        break;
      }
    }
    if (tmp_netif == NULL) {
      return; /* netif is not on the list */
    }
  }
#endif /* !LWIP_SINGLE_NETIF */
  mib2_netif_removed(netif);
#if LWIP_NETIF_REMOVE_CALLBACK
  if (netif->remove_callback) {
    netif->remove_callback(netif);
  }
#endif /* LWIP_NETIF_REMOVE_CALLBACK */
  LWIP_DEBUGF( NETIF_DEBUG, ("netif_remove: removed netif\n") );
}
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#if LWIP_ARP
#endif /* LWIP_ARP */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#endif /* LWIP_IPV6 */
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_IPV4 && LWIP_ARP
#endif /* LWIP_IPV4 && LWIP_ARP */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_NETIF_STATUS_CALLBACK
#endif /* LWIP_NETIF_STATUS_CALLBACK */
#if LWIP_NETIF_REMOVE_CALLBACK
#endif /* LWIP_NETIF_REMOVE_CALLBACK */
#if LWIP_DHCP
#endif /* LWIP_DHCP */
#if LWIP_AUTOIP
#endif /* LWIP_AUTOIP */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_NETIF_LINK_CALLBACK
#endif /* LWIP_NETIF_LINK_CALLBACK */
#if ENABLE_LOOPBACK
#if LWIP_LOOPBACK_MAX_PBUFS
#endif /* LWIP_LOOPBACK_MAX_PBUFS */
#if MIB2_STATS
#if LWIP_HAVE_LOOPIF
#else /* LWIP_HAVE_LOOPIF */
#endif /* LWIP_HAVE_LOOPIF */
#endif /* MIB2_STATS */
#if LWIP_NETIF_LOOPBACK_MULTITHREADING
#endif /* LWIP_NETIF_LOOPBACK_MULTITHREADING */
#if LWIP_LOOPBACK_MAX_PBUFS
#endif /* LWIP_LOOPBACK_MAX_PBUFS */
#if LWIP_NETIF_LOOPBACK_MULTITHREADING
#endif /* LWIP_NETIF_LOOPBACK_MULTITHREADING */
#if LWIP_NETIF_LOOPBACK_MULTITHREADING
#endif /* LWIP_NETIF_LOOPBACK_MULTITHREADING */
#if LWIP_HAVE_LOOPIF
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#endif /* LWIP_HAVE_LOOPIF */
#if MIB2_STATS
#if LWIP_HAVE_LOOPIF
#else /* LWIP_HAVE_LOOPIF */
#endif /* LWIP_HAVE_LOOPIF */
#endif /* MIB2_STATS */
#if LWIP_LOOPBACK_MAX_PBUFS
#endif /* LWIP_LOOPBACK_MAX_PBUFS */
#if LWIP_LOOPBACK_MAX_PBUFS
#endif /* LWIP_LOOPBACK_MAX_PBUFS */
#if LWIP_LOOPBACK_MAX_PBUFS
#endif /* LWIP_LOOPBACK_MAX_PBUFS */
#if !LWIP_NETIF_LOOPBACK_MULTITHREADING
#endif /* !LWIP_NETIF_LOOPBACK_MULTITHREADING */
#endif /* ENABLE_LOOPBACK */
#if LWIP_NUM_NETIF_CLIENT_DATA > 0
#if LWIP_NUM_NETIF_CLIENT_DATA > 256
#error LWIP_NUM_NETIF_CLIENT_DATA must be <= 256
#endif
#endif
#if LWIP_IPV6
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif
#if LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6_SCOPES */
netif_create_ip6_linklocal_address(struct netif *netif, u8_t from_mac_48bit)
{
  u8_t i, addr_index;

  LWIP_ASSERT_CORE_LOCKED();

  LWIP_ASSERT("netif_create_ip6_linklocal_address: invalid netif", netif != NULL);

  /* Link-local prefix. */
  ip_2_ip6(&netif->ip6_addr[0])->addr[0] = PP_HTONL(0xfe800000ul);
  ip_2_ip6(&netif->ip6_addr[0])->addr[1] = 0;

  /* Generate interface ID. */
  if (from_mac_48bit) {
    /* Assume hwaddr is a 48-bit IEEE 802 MAC. Convert to EUI-64 address. Complement Group bit. */
    ip_2_ip6(&netif->ip6_addr[0])->addr[2] = lwip_htonl((((u32_t)(netif->hwaddr[0] ^ 0x02)) << 24) |
        ((u32_t)(netif->hwaddr[1]) << 16) |
        ((u32_t)(netif->hwaddr[2]) << 8) |
        (0xff));
    ip_2_ip6(&netif->ip6_addr[0])->addr[3] = lwip_htonl((u32_t)(0xfeul << 24) |
        ((u32_t)(netif->hwaddr[3]) << 16) |
        ((u32_t)(netif->hwaddr[4]) << 8) |
        (netif->hwaddr[5]));
  } else {
    /* Use hwaddr directly as interface ID. */
    ip_2_ip6(&netif->ip6_addr[0])->addr[2] = 0;
    ip_2_ip6(&netif->ip6_addr[0])->addr[3] = 0;

    addr_index = 3;
    for (i = 0; (i < 8) && (i < netif->hwaddr_len); i++) {
      if (i == 4) {
        addr_index--;
      }
      ip_2_ip6(&netif->ip6_addr[0])->addr[addr_index] |= lwip_htonl(((u32_t)(netif->hwaddr[netif->hwaddr_len - i - 1])) << (8 * (i & 0x03)));
    }
  }

  /* Set a link-local zone. Even though the zone is implied by the owning
   * netif, setting the zone anyway has two important conceptual advantages:
   * 1) it avoids the need for a ton of exceptions in internal code, allowing
   *    e.g. ip6_addr_cmp() to be used on local addresses;
   * 2) the properly zoned address is visible externally, e.g. when any outside
   *    code enumerates available addresses or uses one to bind a socket.
   * Any external code unaware of address scoping is likely to just ignore the
   * zone field, so this should not create any compatibility problems. */
  ip6_addr_assign_zone(ip_2_ip6(&netif->ip6_addr[0]), IP6_UNICAST, netif);

  /* Set address state. */
#if LWIP_IPV6_DUP_DETECT_ATTEMPTS
  /* Will perform duplicate address detection (DAD). */
  netif_ip6_addr_set_state(netif, 0, IP6_ADDR_TENTATIVE);
#else
  /* Consider address valid. */
  netif_ip6_addr_set_state(netif, 0, IP6_ADDR_PREFERRED);
#endif /* LWIP_IPV6_AUTOCONFIG */
}
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_NETIF_EXT_STATUS_CALLBACK
#endif /* LWIP_NETIF_EXT_STATUS_CALLBACK */
