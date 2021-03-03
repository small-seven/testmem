#include <errno.h>
#include <float.h>
#include <pthread.h>
#include <sched.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "lapi/abisize.h"
#include "tst_test.h"
#include "tst_safe_pthread.h"
#ifdef TST_ABI32
#  define DISTANT_MMAP_SIZE (256*1024*1024)
#else
#  define DISTANT_MMAP_SIZE (2L*1024*1024*1024)
#endif
#define TEST_FILENAME "ashfile"
#define STOP_THRESHOLD 10
#define PROGRESS_SEC 3
