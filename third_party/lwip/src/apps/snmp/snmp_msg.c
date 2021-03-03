#include "lwip/apps/snmp_opts.h"
#if LWIP_SNMP /* don't build if not configured for use in lwipopts.h */
#include "snmp_msg.h"
#include "snmp_asn1.h"
#include "snmp_core_priv.h"
#include "lwip/ip_addr.h"
#include "lwip/stats.h"
#if LWIP_SNMP_V3
#include "lwip/apps/snmpv3.h"
#include "snmpv3_priv.h"
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#endif
#include <string.h>
#define SNMP_V3_AUTH_FLAG      0x01
#define SNMP_V3_PRIV_FLAG      0x02
#define SNMP_V3_NOAUTHNOPRIV   0x00
#define SNMP_V3_AUTHNOPRIV     SNMP_V3_AUTH_FLAG
#define SNMP_V3_AUTHPRIV       (SNMP_V3_AUTH_FLAG | SNMP_V3_PRIV_FLAG)
#if LWIP_SNMP_CONFIGURE_VERSIONS
#if LWIP_SNMP_V3
#endif
#if LWIP_SNMP_V3
#endif
#endif
#if LWIP_SNMP_V3
#endif
#if LWIP_HAVE_INT64
#endif
#define PARSE_EXEC(code, retValue) \
#define PARSE_ASSERT(cond, retValue) \
#define BUILD_EXEC(code, retValue) \
#define IF_PARSE_EXEC(code)   PARSE_EXEC(code, ERR_ARG)
#define IF_PARSE_ASSERT(code) PARSE_ASSERT(code, ERR_ARG)
#if LWIP_SNMP_V3
#endif
#if LWIP_SNMP_V3
#endif
#if LWIP_SNMP_CONFIGURE_VERSIONS
#endif
#if LWIP_SNMP_V3
#if LWIP_SNMP_V3_CRYPTO
#endif
#if LWIP_SNMP_V3_CRYPTO
#endif
#if LWIP_SNMP_V3_CRYPTO
#endif
#endif
#define OF_BUILD_EXEC(code) BUILD_EXEC(code, ERR_ARG)
#if LWIP_SNMP_V3
#endif
#if LWIP_SNMP_V3
#if LWIP_SNMP_V3_CRYPTO
#endif
#if LWIP_SNMP_V3_CRYPTO
#endif
#if LWIP_SNMP_V3_CRYPTO
#endif
#endif
#if LWIP_HAVE_INT64
#endif
#define OVB_BUILD_EXEC(code) BUILD_EXEC(code, ERR_ARG)
#if LWIP_HAVE_INT64
#endif
#if LWIP_SNMP_V3 && LWIP_SNMP_V3_CRYPTO
#endif
#if LWIP_SNMP_V3
#endif
#if LWIP_SNMP_V3 && LWIP_SNMP_V3_CRYPTO
#endif
#define VB_PARSE_EXEC(code)   PARSE_EXEC(code, SNMP_VB_ENUMERATOR_ERR_ASN1ERROR)
#define VB_PARSE_ASSERT(code) PARSE_ASSERT(code, SNMP_VB_ENUMERATOR_ERR_ASN1ERROR)
#if LWIP_HAVE_INT64
#endif
#endif /* LWIP_SNMP */
