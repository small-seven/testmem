#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pwd.h>
#include <sys/mount.h>
#include "test.h"
#include "lapi/syscalls.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#define TEST_FILE	"testfile"
#define TEST_EXIST	"testexist"
#define TEST_ELOOP	"testeloop"
#define TEST_EACCES	"./tmp/testeeacces"
#define TEST_EACCES2	"./tmp/testeeacces2"
#define TEST_EROFS	"mntpoint"
#define TEST_EROFS2	"mntpoint/testerofs2"
#define TEST_EMLINK	"emlink_dir/testfile0"
#define TEST_EMLINK2	"emlink_dir/testfile"
#define BASENAME	"mntpoint/basename"
