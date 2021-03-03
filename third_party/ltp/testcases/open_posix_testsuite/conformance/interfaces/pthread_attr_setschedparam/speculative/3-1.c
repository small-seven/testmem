#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "posixtest.h"
#define TEST "3-1"
#define FUNCTION "pthread_attr_setschedparam"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define FIFOPOLICY SCHED_FIFO
#define PRIORITY_OFFSET 1000
