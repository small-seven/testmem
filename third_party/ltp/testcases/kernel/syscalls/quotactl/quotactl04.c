#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include "config.h"
#include "lapi/quotactl.h"
#include "tst_test.h"
#ifndef QFMT_VFS_V1
# define QFMT_VFS_V1 4
#endif
#define FMTID QFMT_VFS_V1
#define MNTPOINT	"mntpoint"
