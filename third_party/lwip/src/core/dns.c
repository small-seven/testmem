#include "lwip/opt.h"
#if LWIP_DNS /* don't build if not configured for use in lwipopts.h */
#include "lwip/def.h"
#include "lwip/udp.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/dns.h"
#include "lwip/prot/dns.h"
#include <string.h>
#ifndef DNS_RAND_TXID
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_XID) != 0)
#define DNS_RAND_TXID LWIP_RAND
#else
#define DNS_RAND_TXID() (++dns_txid)
#endif
#endif
#ifndef DNS_PORT_ALLOWED
#define DNS_PORT_ALLOWED(port) ((port) >= 1024)
#endif
#ifndef DNS_MAX_TTL
#define DNS_MAX_TTL               604800
#elif DNS_MAX_TTL > 0x7FFFFFFF
#error DNS_MAX_TTL must be a positive 32-bit value
#endif
#if DNS_TABLE_SIZE > 255
#error DNS_TABLE_SIZE must fit into an u8_t
#endif
#if DNS_MAX_SERVERS > 255
#error DNS_MAX_SERVERS must fit into an u8_t
#endif
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING) != 0)
#ifndef DNS_MAX_REQUESTS
#define DNS_MAX_REQUESTS          DNS_TABLE_SIZE
#else
#if DNS_MAX_REQUESTS > 255
#error DNS_MAX_REQUESTS must fit into an u8_t
#endif
#endif
#else
#define DNS_MAX_REQUESTS          DNS_TABLE_SIZE
#endif
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) != 0)
#ifndef DNS_MAX_SOURCE_PORTS
#define DNS_MAX_SOURCE_PORTS      DNS_MAX_REQUESTS
#else
#if DNS_MAX_SOURCE_PORTS > 255
#error DNS_MAX_SOURCE_PORTS must fit into an u8_t
#endif
#endif
#else
#ifdef DNS_MAX_SOURCE_PORTS
#undef DNS_MAX_SOURCE_PORTS
#endif
#define DNS_MAX_SOURCE_PORTS      1
#endif
#if LWIP_IPV4 && LWIP_IPV6
#define LWIP_DNS_ADDRTYPE_IS_IPV6(t) (((t) == LWIP_DNS_ADDRTYPE_IPV6_IPV4) || ((t) == LWIP_DNS_ADDRTYPE_IPV6))
#define LWIP_DNS_ADDRTYPE_MATCH_IP(t, ip) (IP_IS_V6_VAL(ip) ? LWIP_DNS_ADDRTYPE_IS_IPV6(t) : (!LWIP_DNS_ADDRTYPE_IS_IPV6(t)))
#define LWIP_DNS_ADDRTYPE_ARG(x) , x
#define LWIP_DNS_ADDRTYPE_ARG_OR_ZERO(x) x
#define LWIP_DNS_SET_ADDRTYPE(x, y) do { x = y; } while(0)
#else
#if LWIP_IPV6
#define LWIP_DNS_ADDRTYPE_IS_IPV6(t) 1
#else
#define LWIP_DNS_ADDRTYPE_IS_IPV6(t) 0
#endif
#define LWIP_DNS_ADDRTYPE_MATCH_IP(t, ip) 1
#define LWIP_DNS_ADDRTYPE_ARG(x)
#define LWIP_DNS_ADDRTYPE_ARG_OR_ZERO(x) 0
#define LWIP_DNS_SET_ADDRTYPE(x, y)
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#define LWIP_DNS_ISMDNS_ARG(x) , x
#else
#define LWIP_DNS_ISMDNS_ARG(x)
#endif
#define SIZEOF_DNS_QUERY 4
#define SIZEOF_DNS_ANSWER 10
#define SIZEOF_DNS_ANSWER_ASSERT 12
typedef enum {
  DNS_STATE_UNUSED           = 0,
  DNS_STATE_NEW              = 1,
  DNS_STATE_ASKING           = 2,
  DNS_STATE_DONE             = 3
} dns_state_enum_t;
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) != 0)
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#endif
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING) != 0)
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if DNS_LOCAL_HOSTLIST
#if DNS_LOCAL_HOSTLIST_IS_DYNAMIC
#else /* DNS_LOCAL_HOSTLIST_IS_DYNAMIC */
#ifndef DNS_LOCAL_HOSTLIST_STORAGE_PRE
#define DNS_LOCAL_HOSTLIST_STORAGE_PRE static
#endif /* DNS_LOCAL_HOSTLIST_STORAGE_PRE */
#ifndef DNS_LOCAL_HOSTLIST_STORAGE_POST
#define DNS_LOCAL_HOSTLIST_STORAGE_POST
#endif /* DNS_LOCAL_HOSTLIST_STORAGE_POST */
#endif /* DNS_LOCAL_HOSTLIST_IS_DYNAMIC */
#endif /* DNS_LOCAL_HOSTLIST */
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) != 0)
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#ifdef DNS_SERVER_ADDRESS
#endif /* DNS_SERVER_ADDRESS */
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) == 0)
#endif
#if DNS_LOCAL_HOSTLIST
#endif
#if DNS_LOCAL_HOSTLIST
#if DNS_LOCAL_HOSTLIST_IS_DYNAMIC && defined(DNS_LOCAL_HOSTLIST_INIT)
#endif /* DNS_LOCAL_HOSTLIST_IS_DYNAMIC && defined(DNS_LOCAL_HOSTLIST_INIT) */
#if DNS_LOCAL_HOSTLIST_IS_DYNAMIC
#else /* DNS_LOCAL_HOSTLIST_IS_DYNAMIC */
#endif /* DNS_LOCAL_HOSTLIST_IS_DYNAMIC */
#if DNS_LOCAL_HOSTLIST_IS_DYNAMIC
#else /* DNS_LOCAL_HOSTLIST_IS_DYNAMIC */
#endif /* DNS_LOCAL_HOSTLIST_IS_DYNAMIC */
#if DNS_LOCAL_HOSTLIST_IS_DYNAMIC
#endif /* DNS_LOCAL_HOSTLIST_IS_DYNAMIC*/
#endif /* DNS_LOCAL_HOSTLIST */
#if DNS_LOCAL_HOSTLIST
#endif /* DNS_LOCAL_HOSTLIST */
#ifdef DNS_LOOKUP_LOCAL_EXTERN
#endif /* DNS_LOOKUP_LOCAL_EXTERN */
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#endif
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) != 0)
#else
#endif
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#if LWIP_IPV6
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#endif /* LWIP_DNS_SUPPORT_MDNS_QUERIES */
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) != 0)
dns_alloc_random_port(void)
{
  err_t err;
  struct udp_pcb *pcb;

  pcb = udp_new_ip_type(IPADDR_TYPE_ANY);
  if (pcb == NULL) {
    /* out of memory, have to reuse an existing pcb */
    return NULL;
  }
  do {
    u16_t port = (u16_t)DNS_RAND_TXID();
    if (DNS_PORT_ALLOWED(port)) {
      err = udp_bind(pcb, IP_ANY_TYPE, port);
    } else {
      /* this port is not allowed, try again */
      err = ERR_USE;
    }
  } while (err == ERR_USE);
  if (err != ERR_OK) {
    udp_remove(pcb);
    return NULL;
  }
  udp_recv(pcb, dns_recv, NULL);
  return pcb;
}
dns_alloc_pcb(void)
{
  u8_t i;
  u8_t idx;

  for (i = 0; i < DNS_MAX_SOURCE_PORTS; i++) {
    if (dns_pcbs[i] == NULL) {
      break;
    }
  }
  if (i < DNS_MAX_SOURCE_PORTS) {
    dns_pcbs[i] = dns_alloc_random_port();
    if (dns_pcbs[i] != NULL) {
      /* succeeded */
      dns_last_pcb_idx = i;
      return i;
    }
  }
  /* if we come here, creating a new UDP pcb failed, so we have to use
     an already existing one (so overflow is no issue) */
  for (i = 0, idx = (u8_t)(dns_last_pcb_idx + 1); i < DNS_MAX_SOURCE_PORTS; i++, idx++) {
    if (idx >= DNS_MAX_SOURCE_PORTS) {
      idx = 0;
    }
    if (dns_pcbs[idx] != NULL) {
      dns_last_pcb_idx = idx;
      return idx;
    }
  }
  return DNS_MAX_SOURCE_PORTS;
}
#endif /* ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) != 0) */
#if ((LWIP_DNS_SECURE & (LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING | LWIP_DNS_SECURE_RAND_SRC_PORT)) != 0)
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING) != 0)
#else
#endif
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) != 0)
#endif
dns_create_txid(void)
{
  u16_t txid;
  u8_t i;

again:
  txid = (u16_t)DNS_RAND_TXID();

  /* check whether the ID is unique */
  for (i = 0; i < DNS_TABLE_SIZE; i++) {
    if ((dns_table[i].state == DNS_STATE_ASKING) &&
        (dns_table[i].txid == txid)) {
      /* ID already used by another pending query */
      goto again;
    }
  }

  return txid;
}
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#endif /* LWIP_DNS_SUPPORT_MDNS_QUERIES */
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#endif /* LWIP_DNS_SUPPORT_MDNS_QUERIES */
#if LWIP_IPV4
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING) != 0)
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#endif
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING) != 0)
#else
#endif
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) != 0)
#endif
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#endif
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#endif
#if ((LWIP_DNS_SECURE & LWIP_DNS_SECURE_RAND_SRC_PORT) == 0)
#endif
#if LWIP_HAVE_LOOPIF
#endif /* LWIP_HAVE_LOOPIF */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#else /* LWIP_IPV4 && LWIP_IPV6 */
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_DNS_SUPPORT_MDNS_QUERIES
#endif /* LWIP_DNS_SUPPORT_MDNS_QUERIES */
#endif /* LWIP_DNS */
