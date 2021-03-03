#include <unistd.h>
#include "tst_safe_timerfd.h"
#include "tst_test.h"
#include "tst_fuzzy_sync.h"
#include "tst_taint.h"
#define TIMERFD_FLAGS "timerfd_settime(TFD_TIMER_ABSTIME | TFD_TIMER_CANCEL_ON_SET)"
#ifndef TFD_TIMER_CANCEL_ON_SET
#define TFD_TIMER_CANCEL_ON_SET (1<<1)
#endif
