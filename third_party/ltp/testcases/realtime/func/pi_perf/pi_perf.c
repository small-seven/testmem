#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <librttest.h>
#include <libstats.h>
#define LOWPRIO 30
#define HIGHPRIO 40
#define BUSYPRIO 35
#define DEF_LOW_WORK_MS 6
#define DEF_HIGH_WORK_MS 1
#define DEF_BUSY_WORK_MS 6
#define DEF_ITERATIONS 100
#define HIST_BUCKETS 100
#define THRESHOLD 200		/* microseconds */
