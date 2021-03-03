#include "config.h"
#include "tst_timer.h"
#include "tst_safe_clocks.h"
#define DELTA_SEC 10
#define NSEC_PER_SEC (1000000000L)
#if (__NR_clock_settime != __LTP__NR_INVALID_SYSCALL)
#endif
#if (__NR_clock_settime64 != __LTP__NR_INVALID_SYSCALL)
#endif
