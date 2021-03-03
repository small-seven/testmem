#include "test_tcp.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/stats.h"
#include "tcp_helper.h"
#include "lwip/inet_chksum.h"
#ifdef _MSC_VER
#pragma warning(disable: 4307) /* we explicitly wrap around TCP seqnos */
#endif
#if !LWIP_STATS || !TCP_STATS || !MEMP_STATS
#error "This tests needs TCP- and MEMP-statistics enabled"
#endif
#if TCP_SND_BUF <= TCP_WND
#error "This tests needs TCP_SND_BUF to be > TCP_WND"
#endif
#define SEQNO1 (0xFFFFFF00 - TCP_MSS)
#define ISS    6510
#if 0
#endif
#if TCP_OVERSIZE
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#endif /* TCP_OVERSIZE */
#if TCP_OVERSIZE
#if TCP_OVERSIZE_DBGCHECK
#endif /* TCP_OVERSIZE_DBGCHECK */
#endif /* TCP_OVERSIZE */
