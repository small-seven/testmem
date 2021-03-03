#include <sys/prctl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#include "lapi/syscalls.h"
#include "lapi/prctl.h"
#include "tst_test.h"
#define PROC_TIMERSLACK_PATH "/proc/self/timerslack_ns"
