#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <sys/param.h>
#include <errno.h>
#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "2-1"
#define FUNCTION "pthread_attr_setstack"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
