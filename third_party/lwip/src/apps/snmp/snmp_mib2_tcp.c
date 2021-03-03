#include "lwip/snmp.h"
#include "lwip/apps/snmp.h"
#include "lwip/apps/snmp_core.h"
#include "lwip/apps/snmp_mib2.h"
#include "lwip/apps/snmp_table.h"
#include "lwip/apps/snmp_scalar.h"
#include "lwip/tcp.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/stats.h"
#include <string.h>
#if LWIP_SNMP && SNMP_LWIP_MIB2 && LWIP_TCP
#if SNMP_USE_NETCONN
#define SYNC_NODE_NAME(node_name) node_name ## _synced
#define CREATE_LWIP_SYNC_NODE(oid, node_name) \
#else
#define SYNC_NODE_NAME(node_name) node_name
#define CREATE_LWIP_SYNC_NODE(oid, node_name)
#endif
#if LWIP_HAVE_INT64
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_HAVE_INT64
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_HAVE_INT64
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_HAVE_INT64
#endif
#endif /* LWIP_SNMP && SNMP_LWIP_MIB2 && LWIP_TCP */
