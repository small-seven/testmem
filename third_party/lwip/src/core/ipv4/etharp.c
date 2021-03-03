#include "lwip/opt.h"
#if LWIP_IPV4 && LWIP_ARP /* don't build if not configured for use in lwipopts.h */
#include "lwip/etharp.h"
#include "lwip/stats.h"
#include "lwip/snmp.h"
#include "lwip/dhcp.h"
#include "lwip/autoip.h"
#include "lwip/prot/iana.h"
#include "netif/ethernet.h"
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#define ARP_AGE_REREQUEST_USED_UNICAST   (ARP_MAXAGE - 30)
#define ARP_AGE_REREQUEST_USED_BROADCAST (ARP_MAXAGE - 15)
#define ARP_MAXPENDING 5
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ARP_QUEUEING
#else /* ARP_QUEUEING */
#endif /* ARP_QUEUEING */
#if !LWIP_NETIF_HWADDRHINT
#endif /* !LWIP_NETIF_HWADDRHINT */
#define ETHARP_FLAG_TRY_HARD     1
#define ETHARP_FLAG_FIND_ONLY    2
#if ETHARP_SUPPORT_STATIC_ENTRIES
#define ETHARP_FLAG_STATIC_ENTRY 4
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if LWIP_NETIF_HWADDRHINT
#define ETHARP_SET_ADDRHINT(netif, addrhint)  do { if (((netif) != NULL) && ((netif)->hints != NULL)) { \
#else /* LWIP_NETIF_HWADDRHINT */
#define ETHARP_SET_ADDRHINT(netif, addrhint)  (etharp_cached_entry = (addrhint))
#endif /* LWIP_NETIF_HWADDRHINT */
#if (ARP_TABLE_SIZE > NETIF_ADDR_IDX_MAX)
#error "ARP_TABLE_SIZE must fit in an s16_t, you have to reduce it in your lwipopts.h"
#endif
#if ARP_QUEUEING
free_etharp_q(struct etharp_q_entry *q)
{
  struct etharp_q_entry *r;
  LWIP_ASSERT("q != NULL", q != NULL);
  while (q) {
    r = q;
    q = q->next;
    LWIP_ASSERT("r->p != NULL", (r->p != NULL));
    pbuf_free(r->p);
    memp_free(MEMP_ARP_QUEUE, r);
  }
}
#else /* ARP_QUEUEING */
#define free_etharp_q(q) pbuf_free(q)
#endif /* ARP_QUEUEING */
etharp_free_entry(int i)
{
  /* remove from SNMP ARP index tree */
  mib2_remove_arp_entry(arp_table[i].netif, &arp_table[i].ipaddr);
  /* and empty packet queue */
  if (arp_table[i].q != NULL) {
    /* remove all queued packets */
    LWIP_DEBUGF(ETHARP_DEBUG, ("etharp_free_entry: freeing entry %"U16_F", packet queue %p.\n", (u16_t)i, (void *)(arp_table[i].q)));
    free_etharp_q(arp_table[i].q);
    arp_table[i].q = NULL;
  }
  /* recycle entry for re-use */
  arp_table[i].state = ETHARP_STATE_EMPTY;
#ifdef LWIP_DEBUG
  /* for debugging, clean out the complete entry */
  arp_table[i].ctime = 0;
  arp_table[i].netif = NULL;
  ip4_addr_set_zero(&arp_table[i].ipaddr);
  arp_table[i].ethaddr = ethzero;
#endif /* LWIP_DEBUG */
}
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ETHARP_TABLE_MATCH_NETIF
#endif /* ETHARP_TABLE_MATCH_NETIF */
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ETHARP_TABLE_MATCH_NETIF
#endif /* ETHARP_TABLE_MATCH_NETIF */
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ARP_QUEUEING
#else /* ARP_QUEUEING */
#endif /* ARP_QUEUEING */
#if ETHARP_SUPPORT_STATIC_ENTRIES
etharp_remove_static_entry(const ip4_addr_t *ipaddr)
{
  s16_t i;
  LWIP_ASSERT_CORE_LOCKED();
  LWIP_DEBUGF(ETHARP_DEBUG | LWIP_DBG_TRACE, ("etharp_remove_static_entry: %"U16_F".%"U16_F".%"U16_F".%"U16_F"\n",
              ip4_addr1_16(ipaddr), ip4_addr2_16(ipaddr), ip4_addr3_16(ipaddr), ip4_addr4_16(ipaddr)));

  /* find or create ARP entry */
  i = etharp_find_entry(ipaddr, ETHARP_FLAG_FIND_ONLY, NULL);
  /* bail out if no entry could be found */
  if (i < 0) {
    return (err_t)i;
  }

  if (arp_table[i].state != ETHARP_STATE_STATIC) {
    /* entry wasn't a static entry, cannot remove it */
    return ERR_ARG;
  }
  /* entry found, free it */
  etharp_free_entry(i);
  return ERR_OK;
}
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
etharp_cleanup_netif(struct netif *netif)
{
  int i;

  for (i = 0; i < ARP_TABLE_SIZE; ++i) {
    u8_t state = arp_table[i].state;
    if ((state != ETHARP_STATE_EMPTY) && (arp_table[i].netif == netif)) {
      etharp_free_entry(i);
    }
  }
}
#if LWIP_AUTOIP
#endif /* LWIP_AUTOIP */
#if (LWIP_DHCP && DHCP_DOES_ARP_CHECK)
#endif /* (LWIP_DHCP && DHCP_DOES_ARP_CHECK) */
#if LWIP_AUTOIP
#endif /* LWIP_AUTOIP */
#ifdef LWIP_HOOK_ETHARP_GET_GW
#endif /* LWIP_HOOK_ETHARP_GET_GW */
#if LWIP_NETIF_HWADDRHINT
#endif /* LWIP_NETIF_HWADDRHINT */
#if ETHARP_TABLE_MATCH_NETIF
#endif
#if LWIP_NETIF_HWADDRHINT
#endif /* LWIP_NETIF_HWADDRHINT */
#if ETHARP_TABLE_MATCH_NETIF
#endif
#if ARP_QUEUEING
#if ARP_QUEUE_LEN
#endif
#else /* ARP_QUEUEING */
#endif /* ARP_QUEUEING */
#if LWIP_AUTOIP
#endif /* LWIP_AUTOIP */
#endif /* LWIP_IPV4 && LWIP_ARP */
