#include <sys/stat.h>
#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "posixtest.h"
#include <time.h>
#define TNAME "aio_return/2-1.c"
#define BUF_SIZE 111
