#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include "posixtest.h"
#define TIMEOUT 3		/* 3 seconds of timeout time for
