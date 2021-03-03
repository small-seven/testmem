#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#include "safe_helpers.h"
#define RUN_TIME_USEC (2*1000*1000)
#define SIGNALS_WITHOUT_DELAY 100
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define WITH_SYNCHRO
#include "../testfrmw/threads_scenarii.c"
#ifdef WITH_SYNCHRO
#endif
#ifdef WITH_SYNCHRO
#endif
#ifdef WITH_SYNCHRO
#endif
#ifdef WITH_SYNCHRO
#endif
#if VERBOSE > 5
#endif
#if VERBOSE > 5
#endif
#ifdef WITH_SYNCHRO
#endif
#ifdef WITH_SYNCHRO
#endif
#if VERBOSE > 0
#ifdef WITH_SYNCHRO
#endif
#endif
