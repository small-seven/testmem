#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sched.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdint.h>
#include <librttest.h>
#include <libtsc.h>
#define ITERATIONS 1000000ULL
#define INTERVALS 10
#ifdef TSC_UNSUPPORTED
#endif
