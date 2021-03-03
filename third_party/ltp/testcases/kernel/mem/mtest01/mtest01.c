#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lapi/abisize.h"
#include "tst_test.h"
#define FIVE_HUNDRED_MB         (500ULL*1024*1024)
#if defined(__s390__) || defined(__s390x__)
#define ALLOC_THRESHOLD		FIVE_HUNDRED_MB
#elif defined(TST_ABI32)
#define ALLOC_THRESHOLD		(2*FIVE_HUNDRED_MB)
#elif defined(TST_ABI64)
#define ALLOC_THRESHOLD		(6*FIVE_HUNDRED_MB)
#endif
#define STOP_THRESHOLD 15	/* seconds remaining before reaching timeout */
