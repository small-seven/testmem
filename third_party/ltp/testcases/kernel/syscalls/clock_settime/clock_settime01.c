#include "config.h"
#include "tst_timer.h"
#include "tst_safe_clocks.h"
#define DELTA_SEC 10
#define DELTA_US (long long) (DELTA_SEC * 1000000)
#define DELTA_EPS (long long) (DELTA_US * 0.1)
#if (__NR_clock_settime != __LTP__NR_INVALID_SYSCALL)
#endif
#if (__NR_clock_settime64 != __LTP__NR_INVALID_SYSCALL)
#endif
