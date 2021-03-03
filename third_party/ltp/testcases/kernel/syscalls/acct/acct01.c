#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>
#include "tst_test.h"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#define FILE_EISDIR		"."
#define FILE_EACCES		"/dev/null"
#define FILE_ENOENT		"/tmp/does/not/exist"
#define FILE_ENOTDIR		"./tmpfile/"
#define TEST_TMPFILE		"./tmpfile"
#define TEST_ELOOP		"test_file_eloop1"
#define TEST_ENAMETOOLONG	nametoolong
#define TEST_EROFS		"mntpoint/file"
