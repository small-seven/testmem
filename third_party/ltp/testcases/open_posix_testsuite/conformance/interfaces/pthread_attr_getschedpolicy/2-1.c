#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "posixtest.h"
#define TEST "1-1"
#define FUNCTION "pthread_attr_getschedpolicy"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define FIFOPOLICY SCHED_FIFO
#define RRPOLICY SCHED_RR
#define OTHERPOLICY SCHED_OTHER
