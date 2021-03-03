#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include "posixtest.h"
#define TEST "3-2"
#define AREA "scheduler"
#define ERROR_PREFIX "unexpected error: " AREA " " TEST ": "
#define PRIORITY 20
#define POLICY SCHED_RR
