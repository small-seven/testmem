#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <math.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 1
#endif
#ifndef WITHOUT_ALTCLK
#define USE_ALTCLK		/* make tests with MONOTONIC CLOCK if supported */
#endif
#define MES_TIMEOUT  (1000000)	/* ns, offset for the pthread_cond_timedwait call */
#ifdef PLOT_OUTPUT
#undef VERBOSE
#define VERBOSE 0
#endif
typedef struct {
	pthread_cond_t *cnd;
	pthread_mutex_t *mtx;
	int *predicate;
	int *tnum;
} test_t;
#ifndef WITHOUT_XOPEN
#endif
#ifdef USE_ALTCLK
#ifndef WITHOUT_XOPEN
#endif
#endif
#define NSCENAR (sizeof(test_scenar) / sizeof(test_scenar[0]))
typedef struct __mes_t {
	int nthreads;
	long _data[NSCENAR];	/* As we store µsec values, a long type should be amply enough. */
	struct __mes_t *next;
} mes_t;
#ifdef USE_CANCEL
#endif
#ifdef USE_CANCEL
#endif
#ifdef PLOT_OUTPUT
#endif
#ifdef USE_ALTCLK
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#ifdef USE_CANCEL
#else
#endif
#if VERBOSE > 5
#endif
#if VERBOSE > 5
#endif
#if VERBOSE > 5
#endif
#if VERBOSE > 5
#endif
#ifdef PLOT_OUTPUT
#endif
#if VERBOSE > 2
#endif
#ifdef PLOT_OUTPUT
#endif
#ifndef USE_ALTCLK
#endif
#if VERBOSE > 0
#endif
#ifdef PLOT_OUTPUT
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
