#include <sys/stat.h>
#include <sys/types.h>
#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "posixtest.h"
#define NUM_AIOCBS	3
#define BUF_SIZE	1024
#define TNAME "lio_listio/5-1.c"
