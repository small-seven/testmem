#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <sched.h>
#include <errno.h>
#include <unistd.h>
#include "librttest.h"
#if HAS_PTHREAD_MUTEXTATTR_ROBUST_APIS
#define NUM_MUTEXES 5000
#define NUM_THREADS 50
#define NUM_CONCURRENT_LOCKS 50
#define DELAY 1000		/* how long to sleep in the worker thread in us */
#else
#endif
