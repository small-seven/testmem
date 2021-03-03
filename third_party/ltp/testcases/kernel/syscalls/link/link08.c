#include <errno.h>
#include "tst_test.h"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#define MNT_POINT	"mntpoint"
#define TEST_FILE	"testfile"
#define TEST_FILE1	"testfile1"
#define TEST_FILE2	"mntpoint/file"
#define TEST_FILE3	"mntpoint/testfile4"
