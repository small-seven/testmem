#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <aio.h>
#include <time.h>
#include "posixtest.h"
#define TNAME "aio_write/2-1.c"
#define BUF_SIZE0 512
#define BUF_SIZE1 1024
#define BUF_SIZE2 1536
#define CHECK_SIZE (BUF_SIZE0+BUF_SIZE1+BUF_SIZE2)
