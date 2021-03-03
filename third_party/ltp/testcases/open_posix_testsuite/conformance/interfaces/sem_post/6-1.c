#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include "posixtest.h"
#define TEST "6-1"
#define FUNCTION "sem_post"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define SEMINITVAL 0		//initial value of semaphore = 0
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
