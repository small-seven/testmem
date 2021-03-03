#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <signal.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#define NCHILDREN  (20 * SCALABILITY_FACTOR)
#define TIMEOUT  (120 * SCALABILITY_FACTOR)
typedef struct {
	pthread_mutex_t *mtx;
	pthread_barrier_t *bar;
} testdata_t;
#ifndef WITHOUT_XOPEN
#endif
#ifndef WITHOUT_XOPEN
#endif
#define NSCENAR (sizeof(scenarii)/sizeof(scenarii[0]))
#if VERBOSE > 6
#endif
#if VERBOSE > 1
#endif
#ifndef WITHOUT_XOPEN
#endif
#if VERBOSE > 5
#endif
#if VERBOSE > 6
#endif
#if VERBOSE > 0
#endif
