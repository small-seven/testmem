#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "posixtest.h"
#define TEST "2-2"
#define FUNCTION "pthread_attr_setinheritsched"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
