#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <librttest.h>
#include <libstats.h>
#define PRIO_A 63
#define PRIO_B 53
#define PRIO_C 43
#define PERIOD_A 40*NS_PER_MS
#define PERIOD_B 80*NS_PER_MS
#define PERIOD_C 160*NS_PER_MS
#define CALC_LOOPS_A (27*100)
#define CALC_LOOPS_B (50*100)
#define CALC_LOOPS_C (72*100)
#define NUM_GROUPS 3
#define THREADS_PER_GROUP 4
#define ITERATIONS 6000		/* about 15 minutes @ 2GHz on 1 CPU */
