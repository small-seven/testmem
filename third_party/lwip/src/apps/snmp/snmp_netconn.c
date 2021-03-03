#include "lwip/apps/snmp_opts.h"
#if LWIP_SNMP && SNMP_USE_NETCONN
#include <string.h>
#include "lwip/api.h"
#include "lwip/ip.h"
#include "lwip/udp.h"
#include "snmp_msg.h"
#include "lwip/sys.h"
#include "lwip/prot/iana.h"
#if LWIP_IPV6
#else /* LWIP_IPV6 */
#endif /* LWIP_IPV6 */
#endif /* LWIP_SNMP && SNMP_USE_NETCONN */
