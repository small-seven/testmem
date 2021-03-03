#define _GNU_SOURCE
#include "config.h"
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <err.h>
#include <limits.h>
#include <getopt.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/syscall.h>
#include <inttypes.h>
#include "test.h"
#ifdef HAVE_NUMA_V2
#include <numaif.h>
#include "../cpuset_lib/cpuset.h"
#include "../cpuset_lib/bitmask.h"
#define OPT_setaffinity		(SCHAR_MAX + 1)
#define OPT_getaffinity		(SCHAR_MAX + 2)
#define OPT_mbind		(SCHAR_MAX + 3)
#define OPT_set_mempolicy	(SCHAR_MAX + 4)
#define OPT_get_mempolicy	(SCHAR_MAX + 5)
#else
#endif
