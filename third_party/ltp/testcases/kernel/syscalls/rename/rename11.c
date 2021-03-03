#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mount.h>
#include "test.h"
#include "safe_macros.h"
#define MNTPOINT	"mntpoint"
#define TEST_EROFS	"mntpoint/test_erofs"
#define TEST_NEW_EROFS	"mntpoint/new_test_erofs"
#define TEST_EMLINK	"test_emlink"
#define TEST_NEW_EMLINK	"emlink_dir/testdir"
#define TEST_NEW_ELOOP	"new_test_eloop"
#define ELOPFILE	"/test_eloop"
