#include "dhcps.h"
#include "dhcps_fix.h"
#if (LWIP_DHCP) && (LWIP_DHCPS) /* don't build if not configured for use in lwipopts.h */
#include <string.h>
#include "lwip/stats.h"
#include "lwip/mem.h"
#include "lwip/udp.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/def.h"
#include "lwip/prot/dhcp.h"
#include "lwip/dhcp.h"
#include "lwip/sys.h"
#include "netif/etharp.h"
#include "securec.h"
#define DHCPS_ADDRESS_FREE 0x0
#define DHCPS_ADDRESS_OFFERRED 0x1
#define DHCPS_ADDRESS_BOUND 0x2
#define DHCPS_ADDRESS_DECLINED 0x3
#define dhcps_option_given(dhcp, idx)          (dhcps_rx_options_given[idx] != 0)
#define dhcps_got_option(dhcp, idx)            (dhcps_rx_options_given[idx] = 1)
#define dhcps_clear_option(dhcp, idx)          (dhcps_rx_options_given[idx] = 0)
#define dhcps_get_option_value(dhcp, idx)      (dhcps_rx_options_val[idx])
#define dhcps_set_option_value(dhcp, idx, val) (dhcps_rx_options_val[idx] = (val))
LWIP_STATIC struct pbuf *dhcps_create_base_msg(struct dhcp_msg *client_msg)
{
  struct pbuf *srvr_msg_pbuf = NULL;
  struct dhcp_msg *srvr_msg = NULL;

  srvr_msg_pbuf = pbuf_alloc(PBUF_TRANSPORT, sizeof(struct dhcp_msg), PBUF_RAM);
  if (srvr_msg_pbuf == NULL) {
    LWIP_DEBUGF(DHCP_DEBUG | LWIP_DBG_TRACE | LWIP_DBG_LEVEL_SERIOUS,
                ("dhcps_create_base_msg(): could not allocate pbuf\n"));
    return NULL;
  }

  LWIP_ASSERT("dhcps_create_base_msg: check that first pbuf can hold struct dhcp_msg",
              (srvr_msg_pbuf->len >= sizeof(struct dhcp_msg)));
#if DRIVER_STATUS_CHECK
  srvr_msg_pbuf->flags |= PBUF_FLAG_DHCP_BUF;
#endif

  srvr_msg = (struct dhcp_msg *)srvr_msg_pbuf->payload;
  srvr_msg->op = DHCP_BOOTREPLY;
  srvr_msg->htype = client_msg->htype;
  srvr_msg->hlen = client_msg->hlen;
  srvr_msg->hops = 0;
  srvr_msg->xid = client_msg->xid;
  srvr_msg->secs = 0;
  srvr_msg->flags = client_msg->flags;
  ip4_addr_set_zero(&srvr_msg->ciaddr);
  ip4_addr_set_zero(&srvr_msg->yiaddr);
  ip4_addr_set_zero(&srvr_msg->siaddr);
  ip4_addr_copy(srvr_msg->giaddr, client_msg->giaddr);
  if (memcpy_s(srvr_msg->chaddr, sizeof(srvr_msg->chaddr), client_msg->chaddr, DHCP_CHADDR_LEN) != EOK) {
    (void)pbuf_free(srvr_msg_pbuf);
    return NULL;
  }
  (void)memset_s(srvr_msg->sname, sizeof(srvr_msg->sname), 0, DHCP_SNAME_LEN);
  (void)memset_s(srvr_msg->file, sizeof(srvr_msg->file), 0, DHCP_FILE_LEN);
  srvr_msg->cookie = PP_HTONL(DHCP_MAGIC_COOKIE);

  return srvr_msg_pbuf;
}
LWIP_STATIC void remove_stale_entries(struct dhcps *dhcps)
{
  int i = 0;
  u32_t curr_time = sys_now();

  for (i = 0; i < dhcps->lease_num; i++) {
    /* Slot should not be free or have infinite lease time */
    if ((dhcps->leasearr[i].flags != DHCPS_ADDRESS_FREE) && (dhcps->leasearr[i].leasetime != (u32_t)~0)) {
      if (dhcps->leasearr[i].leasetime < curr_time) {
        LWIP_DEBUGF(DHCP_DEBUG | LWIP_DBG_TRACE,
                    ("remove_stale_entries: Removing Client Entry at Index = %"U32_F"\n", i));
        (void)memset_s(&(dhcps->leasearr[i]), sizeof(struct dyn_lease_addr), 0, sizeof(struct dyn_lease_addr));
        dhcps->leasearr[i].flags = DHCPS_ADDRESS_FREE;
      }
    }
  }
}
#if (LWIP_DHCPS_LEASE_TIME != ~0)
#endif
LWIP_STATIC int find_free_slot(struct dhcps *dhcps)
{
  int i;
  for (i = 0; i < dhcps->lease_num; i++) {
    if ((dhcps->leasearr[i].flags == DHCPS_ADDRESS_FREE) &&
      (htonl(dhcps->start_addr.addr + (u32_t)i) != ip_2_ip4(&dhcps->netif->ip_addr)->addr)) {
      LWIP_DEBUGF(DHCP_DEBUG | LWIP_DBG_TRACE, ("find_free_slot: Found Free Slot at Index = %"U32_F"\n", i));
      return i;
    }
  }

  return -1;
}
#ifdef  LWIP_DEV_DEBUG
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#if (~0 != LWIP_DHCPS_LEASE_TIME)
#endif
#if !LWIP_DHCPS_DISCOVER_BROADCAST
#endif
#if !LWIP_DHCPS_DISCOVER_BROADCAST
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif
#endif
#if !LWIP_DHCPS_DISCOVER_BROADCAST
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif
#else
#endif
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#if ETHARP_SUPPORT_STATIC_ENTRIES
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#if LWIP_DHCP_BOOTP_FILE
#else
#endif
#if LWIP_DHCP_PROVIDE_DNS_SERVERS
#endif /* LWIP_DHCP_PROVIDE_DNS_SERVERS */
#if LWIP_DHCP_BOOTP_FILE
#endif /* LWIP_DHCP_BOOTP_FILE */
#ifdef  LWIP_DEV_DEBUG
#endif
#if LWIP_DHCP_BOOTP_FILE
#else
#endif
#if LWIP_SO_BINDTODEVICE
#endif
#ifdef  LWIP_DEV_DEBUG
#endif
#endif
