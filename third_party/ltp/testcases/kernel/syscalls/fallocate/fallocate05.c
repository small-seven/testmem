#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "tst_test.h"
#include "lapi/fallocate.h"
#define MNTPOINT "mntpoint"
#define FALLOCATE_BLOCKS 16
#define DEALLOCATE_BLOCKS 4
#define TESTED_FLAGS "fallocate(FALLOC_FL_PUNCH_HOLE | FALLOC_FL_KEEP_SIZE)"
