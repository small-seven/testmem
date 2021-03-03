#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "posixtest.h"
#define TEST "3-2"
#define FUNCTION "pthread_attr_setschedpaarm"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define RRPOLICY SCHED_RR
#define PRIORITY_OFFSET 1000
