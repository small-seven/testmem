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
#define TNAME "lio_listio/9-1.c"
#define BUF_SIZE 512
