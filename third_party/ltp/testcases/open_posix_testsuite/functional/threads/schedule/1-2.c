#include "affinity.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "posixtest.h"
#include "safe_helpers.h"
#define TEST "5-5"
#define AREA "scheduler"
#define ERROR_PREFIX "unexpected error: " AREA " " TEST ": "
#define HIGH_PRIORITY 10
#define MID_PRIORITY 7
#define LOW_PRIORITY 5
#define RUNTIME 5
