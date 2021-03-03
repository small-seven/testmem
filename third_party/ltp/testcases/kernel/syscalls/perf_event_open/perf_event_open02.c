#define _GNU_SOURCE
#include <errno.h>
#include <inttypes.h>
#include <sched.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include "config.h"
#include "tst_test.h"
#include "lapi/cpuset.h"
#include "lapi/syscalls.h"
#if HAVE_PERF_EVENT_ATTR
#include <linux/types.h>
#include <linux/perf_event.h>
#define MAX_CTRS	1000
#ifndef __s390__
#endif /* __s390__ */
#ifdef HAVE_SCHED_GETCPU
#endif
#ifdef __s390__
#else
#endif
#else /* HAVE_PERF_EVENT_ATTR */
#endif
