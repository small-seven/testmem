#include "lwip/snmp.h"
#include "lwip/apps/snmp.h"
#include "lwip/apps/snmp_core.h"
#include "lwip/apps/snmp_mib2.h"
#include "lwip/apps/snmp_scalar.h"
#if LWIP_SNMP && SNMP_LWIP_MIB2
#define MIB2_AUTH_TRAPS_ENABLED  1
#define MIB2_AUTH_TRAPS_DISABLED 2
#endif /* LWIP_SNMP && SNMP_LWIP_MIB2 */
