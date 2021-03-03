#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <pthread.h>
#include <librttest.h>
#include <libstats.h>
#include <libtsc.h>
#define HANDLER_PRIO 98
#define SIGNAL_PRIO 99
#define ITERATIONS 10000000
#define HIST_BUCKETS 100
#define PASS_US 100
#define CHILD_START   0
#define CHILD_WAIT    1
#define CHILD_HANDLED 2
#define CHILD_QUIT    3
#ifdef TSC_UNSUPPORTED
#endif
