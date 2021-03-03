#include "config.h"
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/quota.h>
#include "lapi/quotactl.h"
#include "tst_test.h"
#ifdef HAVE_XFS_XQM_H
# include <xfs/xqm.h>
#define MNTPOINT    "mntpoint"
#else
#endif
