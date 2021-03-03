#include <errno.h>
#include <sys/quota.h>
#include "tst_test.h"
#include "lapi/quotactl.h"
#include "tst_capability.h"
#define OPTION_INVALID 999
#define QFMT_VFS_V0     2
#define USRPATH MNTPOINT "/aquota.user"
#define FMTID QFMT_VFS_V0
#define MNTPOINT "mntpoint"
#define TESTDIR1 MNTPOINT "/testdir1"
#define TESTDIR2 MNTPOINT "/testdir2"
