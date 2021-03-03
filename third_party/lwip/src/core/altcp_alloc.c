#include "lwip/opt.h"
#if LWIP_ALTCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/altcp.h"
#include "lwip/altcp_tcp.h"
#include "lwip/altcp_tls.h"
#include "lwip/priv/altcp_priv.h"
#include "lwip/mem.h"
#include <string.h>
#if LWIP_ALTCP_TLS
#endif /* LWIP_ALTCP_TLS */
#endif /* LWIP_ALTCP */
