#include <stdlib.h>
#include "tst_safe_clocks.h"
#include "tst_timer.h"
#include "lapi/namespaces_constants.h"
#define OFFSET_S 10
#define SLEEP_US 100000
#if (__NR_clock_nanosleep != __LTP__NR_INVALID_SYSCALL)
#endif
#if (__NR_clock_nanosleep_time64 != __LTP__NR_INVALID_SYSCALL)
#endif
