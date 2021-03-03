#include <sys/stat.h>
#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#define TNAME "aio_suspend/4-1.c"
#define NUM_AIOCBS	10
#define BUF_SIZE	(2 * 1024 * 1024)
#define WAIT_FOR_AIOCB	6
#define WAIT_FOR_AIOCB_BUF_SIZE (20 * 1024 * 1024)
