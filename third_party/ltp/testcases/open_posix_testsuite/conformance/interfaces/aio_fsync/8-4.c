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
#define TNAME "aio_fsync/8-4.c"
#define BUF_SIZE 111
