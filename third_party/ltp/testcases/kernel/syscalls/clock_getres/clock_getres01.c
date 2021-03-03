#include <errno.h>
#include "tst_timer.h"
#include "lapi/posix_clocks.h"
#if (__NR_clock_getres != __LTP__NR_INVALID_SYSCALL)
#endif
#if (__NR_clock_getres_time64 != __LTP__NR_INVALID_SYSCALL)
#endif
