#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "posixtest.h"
#define TEST "1-3"
#define FUNCTION "sem_open"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
