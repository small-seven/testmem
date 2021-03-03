#include "config.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "lapi/quotactl.h"
#include "tst_test.h"
#ifndef QFMT_VFS_V0
# define QFMT_VFS_V0	2
#endif
#define USRPATH MNTPOINT "/aquota.user"
#define GRPPATH MNTPOINT "/aquota.group"
#define FMTID	QFMT_VFS_V0
#define MNTPOINT	"mntpoint"
