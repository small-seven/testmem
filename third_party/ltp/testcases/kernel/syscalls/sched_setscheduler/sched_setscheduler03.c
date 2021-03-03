#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <pwd.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "tst_test.h"
#define RLIMIT_NICE_NORMAL 20
#ifdef SCHED_IDLE
#endif
