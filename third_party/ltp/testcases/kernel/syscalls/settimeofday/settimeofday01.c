#include <sys/time.h>
#include <errno.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#define	VAL_SEC		100
#define	VAL_MSEC	100
#define ACCEPTABLE_DELTA 500
#define USEC_PER_SEC    1000000L
