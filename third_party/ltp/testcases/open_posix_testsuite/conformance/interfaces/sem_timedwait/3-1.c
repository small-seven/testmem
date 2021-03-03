#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#if __linux__
#include <features.h>
#endif
#include <semaphore.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "3-1"
#define FUNCTION "sem_timedwait"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
