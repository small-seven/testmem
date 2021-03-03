#include "test_pbuf.h"
#include "lwip/pbuf.h"
#include "lwip/stats.h"
#if !LWIP_STATS || !MEM_STATS ||!MEMP_STATS
#error "This tests needs MEM- and MEMP-statistics enabled"
#endif
#if LWIP_DNS
#error "This test needs DNS turned off (as it mallocs on init)"
#endif
#if !LWIP_TCP || !TCP_QUEUE_OOSEQ || !LWIP_WND_SCALE
#error "This test needs TCP OOSEQ queueing and window scaling enabled"
#endif
#define TESTBUFSIZE_1 65535
#define TESTBUFSIZE_2 65530
#define TESTBUFSIZE_3 50050
