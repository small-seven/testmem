#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include "posixtest.h"
#define TIMEOUT 3
#define NOT_CREATED_THREAD 1
#define ENTERED_THREAD 2
#define EXITING_THREAD 3
#ifdef CLOCK_REALTIME
#else
#endif
#ifdef CLOCK_REALTIME
#else
#endif
