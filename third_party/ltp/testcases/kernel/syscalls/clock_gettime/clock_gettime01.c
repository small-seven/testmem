#include "config.h"
#include "tst_timer.h"
#include "tst_safe_clocks.h"
#if (__NR_clock_gettime != __LTP__NR_INVALID_SYSCALL)
#endif
#if (__NR_clock_gettime64 != __LTP__NR_INVALID_SYSCALL)
#endif
