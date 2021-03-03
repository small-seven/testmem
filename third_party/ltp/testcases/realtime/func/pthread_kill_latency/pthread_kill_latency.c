#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <errno.h>
#include <librttest.h>
#include <libstats.h>
#define PRIO 89
#define ITERATIONS 10000
#define HIST_BUCKETS 100
#define THRESHOLD 20
#define SIGNALNUMBER SIGUSR1
#define PTHREADOF(tid) get_thread(tid)->pthread
#if 0
#endif
