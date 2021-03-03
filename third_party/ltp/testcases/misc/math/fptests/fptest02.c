#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#define MAGIC	0.777807
#define DIFF	0.001
#define EVENTMX	256
#define BIG 1.e50
#define FALSE 0
#define TRUE  1
#define TRYCRIT   1
#define ENTERCRIT 2
#define LEAVECRIT 3
#define ATBARRIER 4
#define ENTERWORK 5
#define LEAVEWORK 6
#define NULLEVENT 999
#include "test.h"
