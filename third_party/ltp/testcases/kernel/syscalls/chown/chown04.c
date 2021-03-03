#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include "test.h"
#include "safe_macros.h"
#include "compat_16.h"
#define MODE_RWX		 (S_IRWXU|S_IRWXG|S_IRWXO)
#define FILE_MODE		 (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#define DIR_MODE		 (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#define DIR_TEMP		 "testdir_1"
#define TEST_FILE1		 "tfile_1"
#define TEST_FILE2		 (DIR_TEMP "/tfile_2")
#define TEST_FILE3		 "t_file/tfile_3"
#define TEST_FILE4		 "test_eloop1"
#define TEST_FILE5		 "mntpoint"
