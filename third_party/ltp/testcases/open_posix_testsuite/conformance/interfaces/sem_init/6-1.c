#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "posixtest.h"
#include <limits.h>
#define TEST "6-1"
#define FUNCTION "sem_init"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
