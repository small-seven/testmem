#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include "posixtest.h"
#define TEST "7-1"
#define FUNCTION "sem_wait"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define CHILDPASS 1
#define CHILDFAIL 0
