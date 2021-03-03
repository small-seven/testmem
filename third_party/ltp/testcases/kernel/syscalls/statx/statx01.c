#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include "tst_test.h"
#include "tst_safe_macros.h"
#include "lapi/stat.h"
#include <string.h>
#include <inttypes.h>
#define TESTFILE "test_file"
#define MNTPOINT "mntpoint/"
#define DEVICEFILE MNTPOINT"blk_dev"
#define MODE 0644
#define SIZE 256
#define MAJOR 8
#define MINOR 1
