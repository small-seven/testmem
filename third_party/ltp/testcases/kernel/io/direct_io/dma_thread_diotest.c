#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#include <pthread.h>
#include <getopt.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include "test.h"
#include "safe_macros.h"
#define FILESIZE	(12*1024*1024)
#define READSIZE	(1024*1024)
#define MNT_POINT	"mntpoint"
#define FILE_BASEPATH   MNT_POINT "/_dma_thread_test_%.04d.tmp"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#define FILECOUNT	100
#define PATTERN		(0xfa)
#define PAGE_SIZE	getpagesize()
#define MIN_WORKERS	2
#define MAX_WORKERS	(READSIZE/PAGE_SIZE)
typedef struct {
	pthread_t tid;
	int worker_number;
	int fd;
	int offset;
	int length;
	int pattern;
	unsigned char *buffer;
} worker_t;
