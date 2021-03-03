#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "posixtest.h"
#define INVALID_TIME 1000000000	/* Invalid value of 1,000 million
#define TIMEOUT 3		/* 3 seconds of timeout time for
