#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define WITH_LOCKS
typedef struct _teststruct {
	pthread_mutex_t mtx[10 * SCALABILITY_FACTOR];
	pthread_mutexattr_t ma[5];
	pthread_mutexattr_t *pma[10 * SCALABILITY_FACTOR];
	struct _teststruct *prev;
} teststruct_t;
#if VERBOSE > 1
#endif
#ifdef WITH_LOCKS
#endif
#if VERBOSE > 2
#endif
#ifdef WITH_LOCKS
#endif
#if VERBOSE > 0
#endif
#else /* WITHOUT_XOPEN */
#endif
