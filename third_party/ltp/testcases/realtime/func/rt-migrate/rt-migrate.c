#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sched.h>
#include <pthread.h>
#include <librttest.h>
#include <libstats.h>
#define gettid() syscall(__NR_gettid)
#define VERSION_STRING "V 0.4LTP"
#define INTERVAL 100ULL * NS_PER_MS
#define RUN_INTERVAL 20ULL * NS_PER_MS
#define NR_RUNS 50
#define PRIO_START 2
#define MAX_ERR  1000 * NS_PER_US
#define PROGRESS_CHARS 70
