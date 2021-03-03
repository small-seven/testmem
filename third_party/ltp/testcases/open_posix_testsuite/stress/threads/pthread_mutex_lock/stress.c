#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#if _POSIX_TIMEOUTS < 0
#error "This sample needs POSIX TIMEOUTS option support"
#endif
#if _POSIX_TIMEOUTS == 0
#warning "This sample needs POSIX TIMEOUTS option support"
#endif
#if _POSIX_TIMERS < 0
#error "This sample needs POSIX TIMERS option support"
#endif
#if _POSIX_TIMERS == 0
#warning "This sample needs POSIX TIMERS option support"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>		/* required for the pthread_mutex_timedlock() function */
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 2
#endif
#define N 2			/* N * 10 * 6 * SCALABILITY_FACTOR threads will be created */
#ifndef WITHOUT_XOPEN
#endif
typedef struct {
	pthread_t threads[10];	/* The 10 threads */
	pthread_mutex_t mtx;	/* The mutex those threads work on */
	char ctrl;		/* The value used to check the behavior */
	char sigok;		/* Used to tell the threads they can return */
	sem_t semsig;		/* Semaphore for synchronizing the signal handler */
	int id;			/* An identifier for the threads group */
	int tcnt;		/* we need to make sure the threads are started before killing 'em */
	pthread_mutex_t tmtx;
	unsigned long long sigcnt, opcnt;	/* We count every iteration */
} cell_t;
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#ifndef WITHOUT_XOPEN
#else
#endif
#if VERBOSE > 0
#endif
#ifndef WITHOUT_XOPEN		/* we have the mutex attribute types */
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 0
#endif
