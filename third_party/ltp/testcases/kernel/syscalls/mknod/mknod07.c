#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include "test.h"
#include "safe_macros.h"
#define DIR_TEMP		"testdir_1"
#define DIR_TEMP_MODE		(S_IRUSR | S_IXUSR)
#define DIR_MODE		(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#define MNT_POINT		"mntpoint"
#define FIFO_MODE	(S_IFIFO | S_IRUSR | S_IRGRP | S_IROTH)
#define SOCKET_MODE	(S_IFSOCK | S_IRWXU | S_IRWXG | S_IRWXO)
#define CHR_MODE	(S_IFCHR | S_IRUSR | S_IWUSR)
#define BLK_MODE	(S_IFBLK | S_IRUSR | S_IWUSR)
#define ELOPFILE	"/test_eloop"
