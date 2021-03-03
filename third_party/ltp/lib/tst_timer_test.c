#include <sys/prctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "tst_clocks.h"
#include "tst_timer_test.h"
#define MAX_SAMPLES 500
#ifdef PR_GET_TIMERSLACK
#else
#endif /* PR_GET_TIMERSLACK */
