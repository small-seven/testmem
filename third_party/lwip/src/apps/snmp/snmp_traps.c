#include "lwip/apps/snmp_opts.h"
#if LWIP_SNMP /* don't build if not configured for use in lwipopts.h */
#include <string.h>
#include "lwip/snmp.h"
#include "lwip/sys.h"
#include "lwip/apps/snmp.h"
#include "lwip/apps/snmp_core.h"
#include "lwip/prot/iana.h"
#include "snmp_msg.h"
#include "snmp_asn1.h"
#include "snmp_core_priv.h"
#define BUILD_EXEC(code) \
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#endif /* LWIP_SNMP */
