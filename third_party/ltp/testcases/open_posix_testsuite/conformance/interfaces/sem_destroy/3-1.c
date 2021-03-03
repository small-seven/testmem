#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include "posixtest.h"
#define TEST "3-1"
#define FUNCTION "sem_destroy"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
