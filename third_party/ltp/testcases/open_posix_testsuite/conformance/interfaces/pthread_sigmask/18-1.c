#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <signal.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define WITH_SYNCHRO
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
#define NSIG (sizeof(signals)/sizeof(int))
#ifdef WITH_SYNCHRO
#endif
#ifdef WITH_SYNCHRO
#endif
#if VERBOSE > 0
#ifdef WITH_SYNCHRO
#endif
#endif
