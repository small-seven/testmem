#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#define WITH_SYNCHRO
#ifndef VERBOSE
#define VERBOSE 2
#endif
#define INTERVAL (700)		/* ns, frequency (actually, period) for the condition signaling */
#ifdef WITH_SYNCHRO
#endif
typedef struct {
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
#ifdef WITH_SYNCHRO
#endif
#ifdef WITH_SYNCHRO
#endif
#if VERBOSE > 0
#ifdef WITH_SYNCHRO
#endif
#endif
