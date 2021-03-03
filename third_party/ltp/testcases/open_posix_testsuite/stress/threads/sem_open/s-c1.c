#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <semaphore.h>
#include <fcntl.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define BLOCKSIZE (100 * SCALABILITY_FACTOR)
#ifdef PLOT_OUTPUT
#undef VERBOSE
#define VERBOSE 0
#endif
typedef struct __mes_t {
	int nsem;
	long _data_open;	/* As we store µsec values, a long type should be enough. */
	long _data_close;	/* As we store µsec values, a long type should be enough. */

	struct __mes_t *next;

	struct __mes_t *prev;
} mes_t;
typedef struct __test_t {
	sem_t *sems[BLOCKSIZE];

	struct __test_t *next;

	struct __test_t *prev;
} test_t;
#if VERBOSE > 1
#endif
#ifdef PLOT_OUTPUT
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
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
