#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include "posixtest.h"
#define BUF_SIZE	5
#define Max_Num		5
#define Max_Threads	127
typedef struct {
	int buffer[BUF_SIZE];
	sem_t full;
	sem_t empty;
	sem_t lock;
} buf_t;
#ifndef	_POSIX_SEMAPHORES
#endif
