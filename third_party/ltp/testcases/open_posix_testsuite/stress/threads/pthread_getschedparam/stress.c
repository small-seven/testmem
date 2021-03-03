#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sched.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define NTHREADS 30
typedef struct _tdata {
	int policy;
	int prio;
	pthread_t thread;
} testdata_t;
#if VERBOSE > 1
#endif
