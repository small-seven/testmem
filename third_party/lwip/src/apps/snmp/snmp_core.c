#include "lwip/apps/snmp_opts.h"
#if LWIP_SNMP /* don't build if not configured for use in lwipopts.h */
#include "lwip/apps/snmp.h"
#include "lwip/apps/snmp_core.h"
#include "snmp_core_priv.h"
#include "lwip/netif.h"
#include <string.h>
#if (LWIP_SNMP && (SNMP_TRAP_DESTINATIONS<=0))
#error "If you want to use SNMP, you have to define SNMP_TRAP_DESTINATIONS>=1 in your lwipopts.h"
#endif
#if (!LWIP_UDP && LWIP_SNMP)
#error "If you want to use SNMP, you have to define LWIP_UDP=1 in your lwipopts.h"
#endif
#if SNMP_MAX_OBJ_ID_LEN > 255
#error "SNMP_MAX_OBJ_ID_LEN must fit into an u8_t"
#endif
#if SNMP_LWIP_MIB2 && LWIP_SNMP_V3
#include "lwip/apps/snmp_mib2.h"
#include "lwip/apps/snmp_snmpv2_framework.h"
#include "lwip/apps/snmp_snmpv2_usm.h"
#elif SNMP_LWIP_MIB2
#include "lwip/apps/snmp_mib2.h"
#else
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 || LWIP_IPV6
#if LWIP_IPV6
#else /* LWIP_IPV6 */
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#else /* LWIP_IPV4 */
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#else /* LWIP_IPV4 */
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#else /* LWIP_IPV6 */
#endif /* LWIP_IPV6 */
#endif /* LWIP_IPV4 || LWIP_IPV6 */
#ifdef LWIP_DEBUG
#endif
#ifdef LWIP_DEBUG
#endif
#endif /* LWIP_SNMP */
