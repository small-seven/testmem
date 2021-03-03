#include "lwip/netdb.h"
#if LWIP_DNS && LWIP_SOCKET
#include "lwip/err.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/ip_addr.h"
#include "lwip/api.h"
#include "lwip/dns.h"
#include <string.h> /* memset */
#include <stdlib.h> /* atoi */
#if LWIP_DNS_API_DECLARE_H_ERRNO
#endif /* LWIP_DNS_API_DECLARE_H_ERRNO */
#ifndef LWIP_DNS_API_HOSTENT_STORAGE
#define LWIP_DNS_API_HOSTENT_STORAGE 0
#endif
#if LWIP_DNS_API_HOSTENT_STORAGE
#define HOSTENT_STORAGE
#else
#define HOSTENT_STORAGE static
#endif /* LWIP_DNS_API_STATIC_HOSTENT */
#if DNS_DEBUG
#endif /* DNS_DEBUG */
#if LWIP_DNS_API_HOSTENT_STORAGE
#else
#endif /* LWIP_DNS_API_HOSTENT_STORAGE */
lwip_freeaddrinfo(struct addrinfo *ai)
{
  struct addrinfo *next;

  while (ai != NULL) {
    next = ai->ai_next;
    memp_free(MEMP_NETDB, ai);
    ai = next;
  }
}
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#endif /* LWIP_DNS && LWIP_SOCKET */
