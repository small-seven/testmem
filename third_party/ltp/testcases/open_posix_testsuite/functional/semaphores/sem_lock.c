#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <semaphore.h>
#include "posixtest.h"
#define SEM_NAME       "/tmp/semaphore"
#define BUF_SIZE	200
#define DEFAULT_THREADS 5
#ifndef	_POSIX_SEMAPHORES
#endif
