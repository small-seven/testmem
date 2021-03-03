#include <pthread.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define DEFAULT_NUM_THREADS	10
#define DEFAULT_NUM_BYTES	(1024*1024*100)	/* 100Mb */
#define DEFAULT_FILE		"/dev/cdrom"
