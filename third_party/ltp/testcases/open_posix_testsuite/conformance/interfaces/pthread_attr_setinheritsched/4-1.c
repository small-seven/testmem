#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "posixtest.h"
#define TEST "4-1"
#define FUNCTION "pthread_attr_setinheritsched"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define INVALIDSCHED 999
