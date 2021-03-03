#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <time.h>
#include "tst_test.h"
#define BLOCKSIZE 8192
#define MAXBLKS 65536
#define TIME_LIMIT 120
#define BUF_SIZE 2048
#ifdef LARGEFILE
#endif
