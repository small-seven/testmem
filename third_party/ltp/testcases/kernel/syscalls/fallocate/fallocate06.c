#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include "tst_test.h"
#include "lapi/fallocate.h"
#define MNTPOINT "mntpoint"
#define TEMPFILE MNTPOINT "/test_file"
#define WRITE_BLOCKS 8
#define FALLOCATE_BLOCKS 2
#define DEALLOCATE_BLOCKS 3
#define TESTED_FLAGS "fallocate(FALLOC_FL_PUNCH_HOLE | FALLOC_FL_KEEP_SIZE)"
