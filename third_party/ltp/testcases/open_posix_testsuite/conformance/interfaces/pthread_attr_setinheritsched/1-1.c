#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "posixtest.h"
#define TEST "1-1"
#define FUNCTION "pthread_attr_setinheritsched"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define EXPLICIT PTHREAD_EXPLICIT_SCHED
#define INHERIT PTHREAD_INHERIT_SCHED
