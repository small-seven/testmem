#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "posixtest.h"
#define TEST "4-1"
#define FUNCTION "pthread_attr_setscope"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define INVALIDSCOPE 999
