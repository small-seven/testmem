#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "posixtest.h"
#define TEST "1-1"
#define FUNCTION "pthread_attr_setscope"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define CONSCOPE PTHREAD_SCOPE_SYSTEM
