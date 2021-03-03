#include "lwip/opt.h"
#if LWIP_NETIF_API /* don't build if not configured for use in lwipopts.h */
#include "lwip/etharp.h"
#include "lwip/netifapi.h"
#include "lwip/memp.h"
#include "lwip/priv/tcpip_priv.h"
#include <string.h> /* strncpy */
#define NETIFAPI_VAR_REF(name)      API_VAR_REF(name)
#define NETIFAPI_VAR_DECLARE(name)  API_VAR_DECLARE(struct netifapi_msg, name)
#define NETIFAPI_VAR_ALLOC(name)    API_VAR_ALLOC(struct netifapi_msg, MEMP_NETIFAPI_MSG, name, ERR_MEM)
#define NETIFAPI_VAR_FREE(name)     API_VAR_FREE(MEMP_NETIFAPI_MSG, name)
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_ARP && LWIP_IPV4
#if ETHARP_SUPPORT_STATIC_ENTRIES && LWIP_TCPIP_CORE_LOCKING
#else
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES && LWIP_TCPIP_CORE_LOCKING */
netifapi_arp_remove(const ip4_addr_t *ipaddr, enum netifapi_arp_entry type)
{
  err_t err;

  /* We only support permanent entries currently */
  LWIP_UNUSED_ARG(type);

#if ETHARP_SUPPORT_STATIC_ENTRIES && LWIP_TCPIP_CORE_LOCKING
  LOCK_TCPIP_CORE();
  err = etharp_remove_static_entry(ipaddr);
  UNLOCK_TCPIP_CORE();
#else
  /* @todo add new vars to struct netifapi_msg and create a 'do' func */
  LWIP_UNUSED_ARG(ipaddr);
  err = ERR_VAL;
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES && LWIP_TCPIP_CORE_LOCKING */

  return err;
}
#endif /* LWIP_ARP && LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_MPU_COMPATIBLE
#else
#endif /* LWIP_MPU_COMPATIBLE */
#if !LWIP_MPU_COMPATIBLE
#endif /* LWIP_MPU_COMPATIBLE */
#if LWIP_MPU_COMPATIBLE
#endif /* LWIP_MPU_COMPATIBLE */
#endif /* LWIP_NETIF_API */
