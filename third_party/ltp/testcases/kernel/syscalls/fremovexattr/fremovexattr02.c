#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "tst_test.h"
#ifdef HAVE_SYS_XATTR_H
#define XATTR_TEST_KEY "user.testkey"
#define MNTPOINT "mntpoint"
#define FNAME MNTPOINT"/fremovexattr02testfile"
#else /* HAVE_SYS_XATTR_H */
#endif
