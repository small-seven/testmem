#define _GNU_SOURCE
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "tst_test.h"
#include "lapi/sync_file_range.h"
#include "check_sync_file_range.h"
#define MNTPOINT		"mnt_point"
#define FNAME1			MNTPOINT"/test1"
#define FNAME2			MNTPOINT"/test2"
#define FNAME3			MNTPOINT"/test3"
#define FILE_SZ_MB		32
#define FILE_SZ			(FILE_SZ_MB * TST_MB)
#define MODE			0644
