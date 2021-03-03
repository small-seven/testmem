#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include "tst_test.h"
#define RECLEN	100
#define MNTPOINT	"mntpoint"
#define TESTFILE	MNTPOINT"/testfile"
