#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "posixtest.h"
#define TEST "1-1"
#define FUNCTION "pthread_attr_getscope"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define SYSTEMSCOPE PTHREAD_SCOPE_SYSTEM
#define PROCESSSCOPE PTHREAD_SCOPE_PROCESS
