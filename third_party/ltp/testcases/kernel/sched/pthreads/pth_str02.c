#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "test.h"
#define DEFAULT_NUM_THREADS 		10
#define USAGE	"\nUsage: %s [-l | -n num_threads] [-d]\n\n" \
