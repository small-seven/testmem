#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <librttest.h>
#include <libstats.h>
#define HIST_BUCKETS 100
#define DEFAULT_ITERATIONS 10000	/* 1000 is the min for 3 nines */
#define DEFAULT_PERIOD 5
#define DEFAULT_PRIO   90
#define DEFAULT_CALC_LOOPS 1000
#define LOOPS_MULTIPLIER 4.2
#define DEFAULT_FILENAME_PREFIX "pcl"
