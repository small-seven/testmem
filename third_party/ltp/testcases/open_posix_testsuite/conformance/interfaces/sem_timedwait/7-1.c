#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#ifdef __linux__
#include <features.h>
#endif
#include <semaphore.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "7-1"
#define FUNCTION "sem_timedwait"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
