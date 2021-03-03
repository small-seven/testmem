#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include <libstats.h>
#include <librttest.h>
#define NUMRUNS 1000
#define NUMLOOPS 1000000
#define NSEC_PER_SEC 1000000000
#define WORKLEN 64
#define ISLEEP 50000
