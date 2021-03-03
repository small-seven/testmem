#include "config.h"
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "tst_test.h"
#ifdef HAVE_SYS_XATTR_H
#define MNTPOINT	"mntpoint"
#define TEST_FILE	MNTPOINT "/file"
#define TRUSTED_BIG	"trusted.big"
#define TRUSTED_SMALL	"trusted.small"
#else /* HAVE_SYS_XATTR_H */
#endif
