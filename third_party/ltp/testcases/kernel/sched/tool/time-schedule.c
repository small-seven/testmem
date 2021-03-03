#include <unistd.h>
#ifdef _POSIX_THREADS
#ifndef _REENTRANT
#define _REENTRANT
#endif
#ifndef _POSIX_THREAD_SAFE_FUNCTIONS
#define _POSIX_THREAD_SAFE_FUNCTIONS
#endif
#include <pthread.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#ifndef __KARMA__
#define mt_num_processors() 1	/*  Set to the number of processors   */
#define ERRSTRING strerror(errno)
#define FALSE 0
#define TRUE  1
#else
#include <karma.h>
#include <karma_mt.h>
#endif
#define MAX_ITERATIONS      1000
#ifdef _POSIX_THREADS
#else
#endif
#ifdef _POSIX_THREADS
#endif
