#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "posixtest.h"
#define TEST "5-2"
#define FUNCTION "sem_init"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
