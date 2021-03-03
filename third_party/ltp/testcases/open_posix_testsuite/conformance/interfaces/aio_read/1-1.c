#include <sys/stat.h>
#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#define TNAME "aio_read/1-1.c"
#define WBUF_SIZE 1024
#define RBUF_SIZE 256
