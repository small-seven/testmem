#define _GNU_SOURCE
#include <stdio.h>
#include <sys/mount.h>
#include <time.h>
#include "tst_test.h"
#include "tst_safe_clocks.h"
#include "tst_safe_macros.h"
#include "tst_timer.h"
#include "lapi/stat.h"
#include "lapi/mount.h"
#include "lapi/fcntl.h"
#define MOUNT_POINT "mount_ext"
#define TEST_FILE MOUNT_POINT"/test_file.txt"
#define SIZE 2
