#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "posixtest.h"
#define CHAIR_NUM	5
#define CUS_NUM		10
#define LOOP_NUM	30
#ifdef __GNUC__
#define my_printf(x...) do { \
#else
#define my_printf printf
#endif
#ifndef  _POSIX_SEMAPHORES
#endif
