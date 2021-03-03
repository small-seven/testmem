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
#define TNAME "lio_listio/6-1.c"
#ifndef LIO_READ
#endif
#ifndef LIO_WRITE
#endif
#ifndef LIO_WRITE
#endif
