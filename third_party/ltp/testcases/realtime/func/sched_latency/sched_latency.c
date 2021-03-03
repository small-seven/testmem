#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <librttest.h>
#include <libstats.h>
#define PRIO 89
#define MIN_ITERATIONS 100
#define DEFAULT_ITERATIONS 10000
#define DEF_PERIOD 5*NS_PER_MS
#define DEF_LOAD_MS 1
#define PASS_US 100
#define HIST_BUCKETS 100
#define OVERHEAD 50000		// allow for 50 us of periodic overhead (context switch, etc.)
