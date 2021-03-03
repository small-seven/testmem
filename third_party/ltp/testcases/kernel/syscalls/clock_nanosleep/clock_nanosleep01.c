#include <limits.h>
#include "tst_safe_clocks.h"
#include "tst_sig_proc.h"
#include "tst_timer.h"
#define TYPE_NAME(x) .ttype = x, .desc = #x
#if (__NR_clock_nanosleep != __LTP__NR_INVALID_SYSCALL)
#endif
#if (__NR_clock_nanosleep_time64 != __LTP__NR_INVALID_SYSCALL)
#endif
