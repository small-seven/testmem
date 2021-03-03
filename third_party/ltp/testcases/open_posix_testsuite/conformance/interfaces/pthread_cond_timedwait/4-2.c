#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <time.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define NCHILDREN (20)
#ifndef WITHOUT_ALTCLK
#define USE_ALTCLK		/* make tests with MONOTONIC CLOCK if supported */
#endif
#ifndef WITHOUT_XOPEN
typedef struct {
	pthread_mutex_t mtx;
	int ctrl;		/* Control value */
	int gotit;		/* Thread locked the mutex while ctrl == 0 */
	int status;		/* error code */
} testdata_t;
#ifdef USE_ALTCLK
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
#endif
#if VERBOSE > 1
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
#if VERBOSE > 3
#endif
#if VERBOSE > 2
#endif
#if VERBOSE > 2
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#else /* WITHOUT_XOPEN */
#endif
