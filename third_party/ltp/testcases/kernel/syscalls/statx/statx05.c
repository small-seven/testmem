#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tst_test.h"
#include "lapi/fs.h"
#include "lapi/stat.h"
#define MNTPOINT "mnt_point"
#define TESTDIR_FLAGGED MNTPOINT"/test_dir1"
#define TESTDIR_UNFLAGGED MNTPOINT"/test_dir2"
