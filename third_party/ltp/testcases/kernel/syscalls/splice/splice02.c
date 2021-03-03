#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tst_test.h"
#include "lapi/splice.h"
#define SPLICE_SIZE (64*1024)
