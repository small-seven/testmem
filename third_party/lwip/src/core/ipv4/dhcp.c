#include "lwip/opt.h"
#if LWIP_IPV4 && LWIP_DHCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/stats.h"
#include "lwip/mem.h"
#include "lwip/udp.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/def.h"
#include "lwip/dhcp.h"
#include "lwip/autoip.h"
#include "lwip/dns.h"
#include "lwip/etharp.h"
#include "lwip/prot/dhcp.h"
#include "lwip/prot/iana.h"
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#ifndef LWIP_HOOK_DHCP_APPEND_OPTIONS
#define LWIP_HOOK_DHCP_APPEND_OPTIONS(netif, dhcp, state, msg, msg_type, options_len_ptr)
#endif
#ifndef LWIP_HOOK_DHCP_PARSE_OPTION
#define LWIP_HOOK_DHCP_PARSE_OPTION(netif, dhcp, state, msg, msg_type, option, len, pbuf, offset) do { LWIP_UNUSED_ARG(msg); } while(0)
#endif
#ifndef DHCP_CREATE_RAND_XID
#define DHCP_CREATE_RAND_XID        1
#endif
#ifdef DHCP_GLOBAL_XID_HEADER
#include DHCP_GLOBAL_XID_HEADER /* include optional starting XID generation prototypes */
#endif
#define DHCP_MAX_MSG_LEN(netif)        (netif->mtu)
#define DHCP_MAX_MSG_LEN_MIN_REQUIRED  576
#define DHCP_MIN_REPLY_LEN             44
#define REBOOT_TRIES                2
#if LWIP_DNS && LWIP_DHCP_MAX_DNS_SERVERS
#if DNS_MAX_SERVERS > LWIP_DHCP_MAX_DNS_SERVERS
#define LWIP_DHCP_PROVIDE_DNS_SERVERS LWIP_DHCP_MAX_DNS_SERVERS
#else
#define LWIP_DHCP_PROVIDE_DNS_SERVERS DNS_MAX_SERVERS
#endif
#else
#define LWIP_DHCP_PROVIDE_DNS_SERVERS 0
#endif
#if LWIP_DHCP_PROVIDE_DNS_SERVERS
#endif /* LWIP_DHCP_PROVIDE_DNS_SERVERS */
#if LWIP_DHCP_GET_NTP_SRV
#endif /* LWIP_DHCP_GET_NTP_SRV */
#if LWIP_DHCP_PROVIDE_DNS_SERVERS
#endif /* LWIP_DHCP_PROVIDE_DNS_SERVERS */
#if LWIP_DHCP_GET_NTP_SRV
#endif /* LWIP_DHCP_GET_NTP_SRV */
#ifdef DHCP_GLOBAL_XID
#endif /* DHCP_GLOBAL_XID */
#define dhcp_option_given(dhcp, idx)          (dhcp_rx_options_given[idx] != 0)
#define dhcp_got_option(dhcp, idx)            (dhcp_rx_options_given[idx] = 1)
#define dhcp_clear_option(dhcp, idx)          (dhcp_rx_options_given[idx] = 0)
#define dhcp_clear_all_options(dhcp)          (memset(dhcp_rx_options_given, 0, sizeof(dhcp_rx_options_given)))
#define dhcp_get_option_value(dhcp, idx)      (dhcp_rx_options_val[idx])
#define dhcp_set_option_value(dhcp, idx, val) (dhcp_rx_options_val[idx] = (val))
#if DHCP_DOES_ARP_CHECK
#endif /* DHCP_DOES_ARP_CHECK */
#if LWIP_NETIF_HOSTNAME
#endif /* LWIP_NETIF_HOSTNAME */
#if DHCP_DOES_ARP_CHECK
#endif /* DHCP_DOES_ARP_CHECK */
#if LWIP_NETIF_HOSTNAME
#endif /* LWIP_NETIF_HOSTNAME */
#if DHCP_DOES_ARP_CHECK
#endif /* DHCP_DOES_ARP_CHECK */
#if LWIP_DHCP_PROVIDE_DNS_SERVERS || LWIP_DHCP_GET_NTP_SRV
#endif /* LWIP_DHCP_PROVIDE_DNS_SERVERS || LWIP_DHCP_GET_NTP_SRV */
#if LWIP_DHCP_GET_NTP_SRV
#endif
#if LWIP_DHCP_BOOTP_FILE
#endif /* LWIP_DHCP_BOOTP_FILE */
#if LWIP_DHCP_BOOTP_FILE
#endif /* LWIP_DHCP_BOOTP_FILE */
#if LWIP_DHCP_GET_NTP_SRV
#endif /* LWIP_DHCP_GET_NTP_SRV */
#if LWIP_DHCP_PROVIDE_DNS_SERVERS
#endif /* LWIP_DHCP_PROVIDE_DNS_SERVERS */
void dhcp_cleanup(struct netif *netif)
{
  LWIP_ASSERT_CORE_LOCKED();
  LWIP_ASSERT("netif != NULL", netif != NULL);

  if (netif_dhcp_data(netif) != NULL) {
    mem_free(netif_dhcp_data(netif));
    netif_set_client_data(netif, LWIP_NETIF_CLIENT_DATA_INDEX_DHCP, NULL);
  }
}
#if LWIP_DHCP_AUTOIP_COOP
#endif /* LWIP_DHCP_AUTOIP_COOP */
#if DHCP_DOES_ARP_CHECK
#endif /* DHCP_DOES_ARP_CHECK */
#if LWIP_DHCP_AUTOIP_COOP
#endif /* LWIP_DHCP_AUTOIP_COOP */
#if LWIP_DHCP_AUTOIP_COOP
#endif /* LWIP_DHCP_AUTOIP_COOP */
#if LWIP_NETIF_HOSTNAME
#endif /* LWIP_NETIF_HOSTNAME */
#if LWIP_NETIF_HOSTNAME
#endif /* LWIP_NETIF_HOSTNAME */
#if LWIP_NETIF_HOSTNAME
#endif /* LWIP_NETIF_HOSTNAME */
dhcp_release_and_stop(struct netif *netif)
{
  struct dhcp *dhcp = netif_dhcp_data(netif);
  ip_addr_t server_ip_addr;

  LWIP_ASSERT_CORE_LOCKED();
  LWIP_DEBUGF(DHCP_DEBUG | LWIP_DBG_TRACE, ("dhcp_release_and_stop()\n"));
  if (dhcp == NULL) {
    return;
  }

  /* already off? -> nothing to do */
  if (dhcp->state == DHCP_STATE_OFF) {
    return;
  }

  ip_addr_copy(server_ip_addr, dhcp->server_ip_addr);

  /* clean old DHCP offer */
  ip_addr_set_zero_ip4(&dhcp->server_ip_addr);
  ip4_addr_set_zero(&dhcp->offered_ip_addr);
  ip4_addr_set_zero(&dhcp->offered_sn_mask);
  ip4_addr_set_zero(&dhcp->offered_gw_addr);
#if LWIP_DHCP_BOOTP_FILE
  ip4_addr_set_zero(&dhcp->offered_si_addr);
#endif /* LWIP_DHCP_BOOTP_FILE */
  dhcp->offered_t0_lease = dhcp->offered_t1_renew = dhcp->offered_t2_rebind = 0;
  dhcp->t1_renew_time = dhcp->t2_rebind_time = dhcp->lease_used = dhcp->t0_timeout = 0;

  /* send release message when current IP was assigned via DHCP */
  if (dhcp_supplied_address(netif)) {
    /* create and initialize the DHCP message header */
    struct pbuf *p_out;
    u16_t options_out_len;
    p_out = dhcp_create_msg(netif, dhcp, DHCP_RELEASE, &options_out_len);
    if (p_out != NULL) {
      struct dhcp_msg *msg_out = (struct dhcp_msg *)p_out->payload;
      options_out_len = dhcp_option(options_out_len, msg_out->options, DHCP_OPTION_SERVER_ID, 4);
      options_out_len = dhcp_option_long(options_out_len, msg_out->options, lwip_ntohl(ip4_addr_get_u32(ip_2_ip4(&server_ip_addr))));

      LWIP_HOOK_DHCP_APPEND_OPTIONS(netif, dhcp, dhcp->state, msg_out, DHCP_RELEASE, &options_out_len);
      dhcp_option_trailer(options_out_len, msg_out->options, p_out);

      udp_sendto_if(dhcp_pcb, p_out, &server_ip_addr, LWIP_IANA_PORT_DHCP_SERVER, netif);
      pbuf_free(p_out);
      LWIP_DEBUGF(DHCP_DEBUG | LWIP_DBG_TRACE | LWIP_DBG_STATE, ("dhcp_release: RELEASED, DHCP_STATE_OFF\n"));
    } else {
      /* sending release failed, but that's not a problem since the correct behaviour of dhcp does not rely on release */
      LWIP_DEBUGF(DHCP_DEBUG | LWIP_DBG_TRACE | LWIP_DBG_LEVEL_SERIOUS, ("dhcp_release: could not allocate DHCP request\n"));
    }
  }

  /* remove IP address from interface (prevents routing from selecting this interface) */
  netif_set_addr(netif, IP4_ADDR_ANY4, IP4_ADDR_ANY4, IP4_ADDR_ANY4);

#if LWIP_DHCP_AUTOIP_COOP
  if (dhcp->autoip_coop_state == DHCP_AUTOIP_COOP_STATE_ON) {
    autoip_stop(netif);
    dhcp->autoip_coop_state = DHCP_AUTOIP_COOP_STATE_OFF;
  }
#endif /* LWIP_DHCP_AUTOIP_COOP */

  dhcp_set_state(dhcp, DHCP_STATE_OFF);

  if (dhcp->pcb_allocated != 0) {
    dhcp_dec_pcb_refcount(); /* free DHCP PCB if not needed any more */
    dhcp->pcb_allocated = 0;
  }
}
dhcp_release(struct netif *netif)
{
  dhcp_release_and_stop(netif);
  return ERR_OK;
}
#if LWIP_NETIF_HOSTNAME
#endif /* LWIP_NETIF_HOSTNAME */
#if LWIP_DHCP_BOOTP_FILE
#endif
#if LWIP_DHCP_BOOTP_FILE
#endif /* LWIP_DHCP_BOOTP_FILE */
#if LWIP_DHCP_PROVIDE_DNS_SERVERS
#endif /* LWIP_DHCP_PROVIDE_DNS_SERVERS */
#if LWIP_DHCP_GET_NTP_SRV
#endif /* LWIP_DHCP_GET_NTP_SRV*/
#if LWIP_DHCP_BOOTP_FILE
#endif
#if LWIP_DHCP_BOOTP_FILE
#endif /* LWIP_DHCP_BOOTP_FILE */ 
#if DHCP_DOES_ARP_CHECK
#else
#endif
dhcp_create_msg(struct netif *netif, struct dhcp *dhcp, u8_t message_type, u16_t *options_out_len)
{
  u16_t i;
  struct pbuf *p_out;
  struct dhcp_msg *msg_out;
  u16_t options_out_len_loc;

#ifndef DHCP_GLOBAL_XID
  /** default global transaction identifier starting value (easy to match
   *  with a packet analyser). We simply increment for each new request.
   *  Predefine DHCP_GLOBAL_XID to a better value or a function call to generate one
   *  at runtime, any supporting function prototypes can be defined in DHCP_GLOBAL_XID_HEADER */
#if DHCP_CREATE_RAND_XID && defined(LWIP_RAND)
  static u32_t xid;
#else /* DHCP_CREATE_RAND_XID && defined(LWIP_RAND) */
  static u32_t xid = 0xABCD0000;
#endif /* DHCP_CREATE_RAND_XID && defined(LWIP_RAND) */
#else
  if (!xid_initialised) {
    xid = DHCP_GLOBAL_XID;
    xid_initialised = !xid_initialised;
  }
#endif
  LWIP_ERROR("dhcp_create_msg: netif != NULL", (netif != NULL), return NULL;);
  LWIP_ERROR("dhcp_create_msg: dhcp != NULL", (dhcp != NULL), return NULL;);
  p_out = pbuf_alloc(PBUF_TRANSPORT, sizeof(struct dhcp_msg), PBUF_RAM);
  if (p_out == NULL) {
    LWIP_DEBUGF(DHCP_DEBUG | LWIP_DBG_TRACE | LWIP_DBG_LEVEL_SERIOUS,
                ("dhcp_create_msg(): could not allocate pbuf\n"));
    return NULL;
  }
  LWIP_ASSERT("dhcp_create_msg: check that first pbuf can hold struct dhcp_msg",
              (p_out->len >= sizeof(struct dhcp_msg)));

  /* DHCP_REQUEST should reuse 'xid' from DHCPOFFER */
  if ((message_type != DHCP_REQUEST) || (dhcp->state == DHCP_STATE_REBOOTING)) {
    /* reuse transaction identifier in retransmissions */
    if (dhcp->tries == 0) {
#if DHCP_CREATE_RAND_XID && defined(LWIP_RAND)
      xid = LWIP_RAND();
#else /* DHCP_CREATE_RAND_XID && defined(LWIP_RAND) */
      xid++;
#endif /* DHCP_CREATE_RAND_XID && defined(LWIP_RAND) */
    }
    dhcp->xid = xid;
  }
  LWIP_DEBUGF(DHCP_DEBUG | LWIP_DBG_TRACE,
              ("transaction id xid(%"X32_F")\n", xid));

  msg_out = (struct dhcp_msg *)p_out->payload;
  memset(msg_out, 0, sizeof(struct dhcp_msg));

  msg_out->op = DHCP_BOOTREQUEST;
  /* @todo: make link layer independent */
  msg_out->htype = LWIP_IANA_HWTYPE_ETHERNET;
  msg_out->hlen = netif->hwaddr_len;
  msg_out->xid = lwip_htonl(dhcp->xid);
  /* we don't need the broadcast flag since we can receive unicast traffic
     before being fully configured! */
  /* set ciaddr to netif->ip_addr based on message_type and state */
  if ((message_type == DHCP_INFORM) || (message_type == DHCP_DECLINE) || (message_type == DHCP_RELEASE) ||
      ((message_type == DHCP_REQUEST) && /* DHCP_STATE_BOUND not used for sending! */
       ((dhcp->state == DHCP_STATE_RENEWING) || dhcp->state == DHCP_STATE_REBINDING))) {
    ip4_addr_copy(msg_out->ciaddr, *netif_ip4_addr(netif));
  }
  for (i = 0; i < LWIP_MIN(DHCP_CHADDR_LEN, NETIF_MAX_HWADDR_LEN); i++) {
    /* copy netif hardware address (padded with zeroes through memset already) */
    msg_out->chaddr[i] = netif->hwaddr[i];
  }
  msg_out->cookie = PP_HTONL(DHCP_MAGIC_COOKIE);
  /* Add option MESSAGE_TYPE */
  options_out_len_loc = dhcp_option(0, msg_out->options, DHCP_OPTION_MESSAGE_TYPE, DHCP_OPTION_MESSAGE_TYPE_LEN);
  options_out_len_loc = dhcp_option_byte(options_out_len_loc, msg_out->options, message_type);
  if (options_out_len) {
    *options_out_len = options_out_len_loc;
  }
  return p_out;
}
#endif /* LWIP_IPV4 && LWIP_DHCP */
