#define _GNU_SOURCE
#include <errno.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include "tst_test.h"
#ifdef SIGSTKFLT
#endif
#define MIN_RLIMIT_CORE (512 * 1024)
