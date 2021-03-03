#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <librttest.h>
#include <libstats.h>
#define DEF_MED_PRIO 60		// (softirqd-hrtimer,98)
#define DEF_ITERATIONS 10000
#define HIST_BUCKETS 100
#define DEF_BUSY_TIME 10	// Duration of busy work in milliseconds
#define DEF_SLEEP_TIME 10000	// Duration of nanosleep in nanoseconds
#define DEF_CRITERIA 10		// maximum timer latency in microseconds
