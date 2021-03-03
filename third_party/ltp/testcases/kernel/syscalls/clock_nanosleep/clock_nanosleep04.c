#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "tst_safe_clocks.h"
#include "tst_timer.h"
#if (__NR_clock_nanosleep != __LTP__NR_INVALID_SYSCALL)
#endif
#if (__NR_clock_nanosleep_time64 != __LTP__NR_INVALID_SYSCALL)
#endif
