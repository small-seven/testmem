#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <aio.h>
#include <time.h>
#include "posixtest.h"
#define TNAME "aio_cancel/3-1.c"
#define BUF_NB		128
#define BUF_SIZE	(1024 * 1024)
