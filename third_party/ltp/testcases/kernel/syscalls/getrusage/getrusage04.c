#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/posix_clocks.h"
#define RECORD_MAX    20
#define FACTOR_MAX    10
#ifndef RUSAGE_THREAD
#define RUSAGE_THREAD 1
#endif
#if (__powerpc__) || (__powerpc64__) || (__s390__) || (__s390x__)
#endif
