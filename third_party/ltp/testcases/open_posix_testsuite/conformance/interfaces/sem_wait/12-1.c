#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "posixtest.h"
#define TEST "12-1"
#define FUNCTION "sem_trywait"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
