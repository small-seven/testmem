#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <librttest.h>
#include <libstats.h>
#include <getopt.h>
#define SIGNAL_PRIO 89
#define HANDLER_PRIO 89
#define DEFAULT_ITERATIONS 1000000	/* about 1 minute @ 2GHz */
#define HIST_BUCKETS 100
#define PASS_US 100
#define CHILD_START   0
#define CHILD_WAIT    1
#define CHILD_HANDLED 2
#define CHILD_QUIT    3
