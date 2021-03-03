#include <pthread.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/param.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "1-1"
#define FUNCTION "pthread_getcpuclockid"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
