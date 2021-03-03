#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sched.h>
#include "posixtest.h"
#define TRD_POLICY SCHED_FIFO
#define NOT_CREATED_THREAD 1
#define ENTERED_THREAD 2
#define PASSED_LOCK 3
#define EXITING_THREAD 4
#ifndef _POSIX_THREAD_PRIORITY_SCHEDULING
#endif
