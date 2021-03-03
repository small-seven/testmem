#include "tst_safe_timerfd.h"
#include "lapi/timerfd.h"
#include "tst_clocks.h"
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#define TTYPE (errno == ENOTSUP ? TCONF : TBROK)
