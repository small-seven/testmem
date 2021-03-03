#include "affinity.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "posixtest.h"
#include "safe_helpers.h"
#define TEST "5-4"
#define AREA "scheduler"
#define ERROR_PREFIX "unexpected error: " AREA " " TEST ": "
#define HIGH_PRIORITY 10
#define LOW_PRIORITY 5
#define RUNTIME 5
