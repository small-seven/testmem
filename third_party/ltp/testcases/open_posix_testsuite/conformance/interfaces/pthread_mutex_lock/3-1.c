#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#define WITH_SYNCHRO
#ifndef VERBOSE
#define VERBOSE 1
#endif
#ifdef WITH_SYNCHRO
#endif
typedef struct {
	pthread_t *thr;
	int sig;
#ifdef WITH_SYNCHRO
	sem_t *sem;
#endif
} thestruct;
#ifdef WITH_SYNCHRO
#endif
#ifdef WITH_SYNCHRO
#endif
#ifdef WITH_SYNCHRO
#endif
#ifndef WITHOUT_XOPEN
#if VERBOSE >1
#endif
#else
#if VERBOSE > 0
#endif
#endif
#ifdef WITH_SYNCHRO
#if VERBOSE >1
#endif
#endif
#if VERBOSE >1
#endif
#ifdef WITH_SYNCHRO
#endif
#if VERBOSE >1
#endif
#if VERBOSE >1
#endif
#if VERBOSE >1
#endif
#if VERBOSE >1
#endif
#if VERBOSE > 0
#ifdef WITH_SYNCHRO
#endif
#endif
