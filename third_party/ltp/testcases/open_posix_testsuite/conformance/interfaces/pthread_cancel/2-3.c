#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "2-3"
#define FUNCTION "pthread_cancel"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
