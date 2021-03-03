#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <aio.h>
#include "posixtest.h"
#define TNAME "aio_suspend/2-1.c"
#define NENT	8
#define NAIOCB	3
#define BUF_SIZE 1024
