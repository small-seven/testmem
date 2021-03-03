#define _GNU_SOURCE
#include "config.h"
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/quota.h>
#include "tst_test.h"
#include "lapi/quotactl.h"
#ifdef HAVE_XFS_XQM_H
# include <xfs/xqm.h>
#else
#endif
