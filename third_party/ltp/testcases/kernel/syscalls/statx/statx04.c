#define _GNU_SOURCE
#include "tst_test.h"
#include "lapi/fs.h"
#include <stdlib.h>
#include "lapi/stat.h"
#define MOUNT_POINT "mntpoint"
#define TESTDIR_FLAGGED MOUNT_POINT"/test_dir1"
#define TESTDIR_UNFLAGGED MOUNT_POINT"/test_dir2"
