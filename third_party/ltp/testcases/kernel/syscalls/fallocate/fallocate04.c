#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/fallocate.h"
#define MNTPOINT "fallocate"
#define FNAME MNTPOINT "/fallocate.txt"
#define NUM_OF_BLOCKS	3
