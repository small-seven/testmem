#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sched.h>
#include <errno.h>
#include <limits.h>
#include <libstats.h>
#include <librttest.h>
#include <sys/mman.h>
#define ITERATIONS 10000000
#define MIN_ITERATION 10000
#define HIST_BUCKETS 20
#define SCATTER_FILENAME	0
#define HIST_FILENAME		1
#define SCATTER_TITLE		0
#define HIST_TITLE		1
#define SCATTER_LABELX		0
#define SCATTER_LABELY		1
#define HIST_LABELX		2
#define HIST_LABELY		3
