#include <librttest.h>
#include <libstats.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>
#include <errno.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/prctl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <math.h>
#if HAS_PRIORITY_INHERIT
#endif
#ifndef PR_SET_TRACING
#define PR_SET_TRACING 0
#endif
