#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "test.h"
#define MAXTIME 72000		/* Maximum # of secs to wait before failing */
#define NUMLOOPS 100000		/* # of loops */
#define NSECS_TO_WAIT	(1)
#if DEBUG
#endif
#ifdef USING_NPTL
#ifdef DEBUG
#else
#endif
#else
#endif
