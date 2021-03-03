#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "3-1"
#define FUNCTION "pthread_exit"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
