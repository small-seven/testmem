#include "test_mem.h"
#include "lwip/mem.h"
#include "lwip/stats.h"
#if !LWIP_STATS || !MEM_STATS
#error "This tests needs MEM-statistics enabled"
#endif
#if LWIP_DNS
#error "This test needs DNS turned off (as it mallocs on init)"
#endif
#define SIZE1   16
#define SIZE1_2 12
#define SIZE2   16
#ifndef MIN_SIZE
#define MIN_SIZE 12
#endif
