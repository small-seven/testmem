#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <aio.h>
#include "posixtest.h"
#define TNAME "aio_error/2-1.c"
#define BUF_NB		128
#define BUF_SIZE	1024
