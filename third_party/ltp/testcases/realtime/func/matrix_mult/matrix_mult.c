#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <librttest.h>
#include <libstats.h>
#define MAX_CPUS	8192
#define PRIO		43
#define MATRIX_SIZE	100
#define DEF_OPS		8	/* the higher the number, the more CPU intensive */
#define PASS_CRITERIA	0.75	/* Avg concurrent time * pass criteria < avg seq time - */
#define ITERATIONS	128
#define HIST_BUCKETS	100
#define THREAD_WAIT	1
#define THREAD_WORK	2
#define THREAD_DONE	3
#define THREAD_SLEEP	1 * NS_PER_US
