#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <semaphore.h>
#include <pthread.h>
#include "posixtest.h"
#define	PH_NUM		5
#define LOOP_NUM	20
#define thinking	0
#define hungry		1
#define eating		2
#ifndef  _POSIX_SEMAPHORES
#endif
