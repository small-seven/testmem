#define _GNU_SOURCE
#include "tst_test.h"
#include "lapi/mkdirat.h"
#define MNT_POINT	"mntpoint"
#define TEST_DIR	"mntpoint/test_dir"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
