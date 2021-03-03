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
#define SEM_NAME       "/tmp/semaphore"
#define READ_NUM	10
#define WRITE_NUM	15
#ifndef  _POSIX_SEMAPHORES
#endif
