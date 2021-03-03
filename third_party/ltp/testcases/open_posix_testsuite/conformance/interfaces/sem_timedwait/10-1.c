#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "posixtest.h"
#define TEST "10-1"
#define FUNCTION "sem_timedwait"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define SLEEP_SEC 1
#ifdef CLOCK_REALTIME
#else
#endif
#ifdef CLOCK_REALTIME
#else
#endif
