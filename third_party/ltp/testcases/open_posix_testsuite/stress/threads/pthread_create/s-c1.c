#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <assert.h>
#include <sys/wait.h>
#include <math.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define RESOLUTION (5 * SCALABILITY_FACTOR)
#ifdef PLOT_OUTPUT
#undef VERBOSE
#define VERBOSE 0
#endif
#include "threads_scenarii.c"
typedef struct __mes_t {
	int nthreads;
	long _data[NSCENAR];	/* As we store µsec values, a long type should be amply enough. */
	struct __mes_t *next;
} mes_t;
#ifdef PLOT_OUTPUT
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 5
#endif
#if VERBOSE > 3
#endif
#if VERBOSE > 3
#endif
#if VERBOSE > 3
#endif
#if VERBOSE > 5
#endif
#if (VERBOSE > 5) || defined(PLOT_OUTPUT)
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
