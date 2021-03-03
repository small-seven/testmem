#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sched.h>
#include <errno.h>
#include <stdint.h>
#include <librttest.h>
#include <libtsc.h>
#define ITERATIONS 1000000
#ifdef TSC_UNSUPPORTED
#endif
