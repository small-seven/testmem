#include "api_shell_fix.h"
#include <time.h>
#include <lwip/sys.h>
#include <lwip/snmp.h>
#include <lwip/etharp.h>
#include <lwip/netifapi.h>
#include <lwip/sockets.h>
#include <lwip/priv/api_msg.h>
#include "securec.h"
#define NETIFAPI_VAR_REF(name)      API_VAR_REF(name)
#define NETIFAPI_VAR_DECLARE(name)  API_VAR_DECLARE(struct netifapi_msg, name)
#define NETIFAPI_VAR_ALLOC(name)    API_VAR_ALLOC(struct netifapi_msg, MEMP_NETIFAPI_MSG, name, ERR_MEM)
#define NETIFAPI_VAR_FREE(name)     API_VAR_FREE(MEMP_NETIFAPI_MSG, name)
#if LWIP_ENABLE_LOS_SHELL_CMD
#if LWIP_DHCP
#include <lwip/dhcp.h>
#endif /* LWIP_DHCP */
#if LWIP_DHCPS
#include "dhcps.h"
#endif /* LWIP_DHCPS */
#if LWIP_TCP
#endif
#if LWIP_MPU_COMPATIBLE
#else
#endif /* LWIP_MPU_COMPATIBLE */
#define NETIF_MTU_MIN       1280
#ifndef IP_FRAG_MIN_MTU
#define IP_FRAG_MIN_MTU     68
#endif
#if LWIP_IPV6
#else
#endif
#if LWIP_IPV6 && LWIP_ND6_ALLOW_RA_UPDATES
#endif /* LWIP_IPV6 && LWIP_ND6_ALLOW_RA_UPDATES */
#if PF_PKT_SUPPORT
#endif
#if LWIP_ENABLE_IP_CONFLICT_SIGNAL
#endif
#endif
