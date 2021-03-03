#include "snmpv3_priv.h"
#include "lwip/apps/snmpv3.h"
#include "lwip/sys.h"
#include <string.h>
#if LWIP_SNMP && LWIP_SNMP_V3
#ifdef LWIP_SNMPV3_INCLUDE_ENGINE
#include LWIP_SNMPV3_INCLUDE_ENGINE
#endif
#define SNMP_MAX_TIME_BOOT 2147483647UL
#if LWIP_SNMP_V3_CRYPTO
#ifdef LWIP_RAND /* Based on RFC3826 */
#else /* Based on RFC3414 */
#endif
#endif /* LWIP_SNMP_V3_CRYPTO */
#endif
