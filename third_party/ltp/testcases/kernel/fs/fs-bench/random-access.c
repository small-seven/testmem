#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1
#define MAXNUM 0x100000
#define BUFS 8192
