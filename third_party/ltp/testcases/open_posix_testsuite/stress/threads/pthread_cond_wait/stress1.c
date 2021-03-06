#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <time.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define NCHILDREN (5)
#define TIMEOUT 120
#ifndef WITHOUT_ALTCLK
#define USE_ALTCLK		/* make tests with MONOTONIC CLOCK if supported */
#endif
#ifdef WITHOUT_XOPEN
#define PTHREAD_MUTEX_DEFAULT 0
#define PTHREAD_MUTEX_NORMAL 0
#define PTHREAD_MUTEX_ERRORCHECK 0
#define PTHREAD_MUTEX_RECURSIVE 0
#endif
#ifdef USE_ALTCLK
#endif
#define NSCENAR (sizeof(scenarii)/sizeof(scenarii[0]))
#define NTOT (NSCENAR * SCALABILITY_FACTOR * NCHILDREN)
typedef struct {
	struct childdata cd[NTOT];
	int boolean;
} testdata_t;
#if VERBOSE > 1
#endif
#if VERBOSE > 0
#endif
#ifndef USE_ALTCLK
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#ifdef WITHOUT_XOPEN
#endif
#endif
#ifndef WITHOUT_XOPEN
#if VERBOSE > 1
#endif
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#ifdef USE_ALTCLK
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#define CD (td->cd[i+(j*NSCENAR)])
#undef CD
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 0
#endif
