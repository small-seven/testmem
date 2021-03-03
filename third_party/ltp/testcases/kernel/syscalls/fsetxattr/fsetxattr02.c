#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "tst_test.h"
#ifdef HAVE_SYS_XATTR_H
#define XATTR_TEST_KEY "user.testkey"
#define XATTR_TEST_VALUE "this is a test value"
#define XATTR_TEST_VALUE_SIZE 20
#define MNTPOINT "mntpoint"
#define OFFSET    11
#define FILENAME "fsetxattr02testfile"
#define DIRNAME  "fsetxattr02testdir"
#define SYMLINK  "fsetxattr02symlink"
#define FIFO     MNTPOINT"/fsetxattr02fifo"
#define CHR      MNTPOINT"/fsetxattr02chr"
#define BLK      MNTPOINT"/fsetxattr02blk"
#define SOCK     "fsetxattr02sock"
#else /* HAVE_SYS_XATTR_H */
#endif
