#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "4-2"
#define FUNCTION "pthread_mutex_destroy"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
