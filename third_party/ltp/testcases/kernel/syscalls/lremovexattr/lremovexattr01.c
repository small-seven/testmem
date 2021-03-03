#include "config.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "tst_test.h"
#ifdef HAVE_SYS_XATTR_H
#define ENOATTR ENODATA
#define XATTR_KEY		"trusted.key1"
#define XATTR_VALUE		"file and link"
#define XATTR_VALUE_SIZE	13
#define MNTPOINT "mntpoint"
#define FILENAME MNTPOINT"/lremovexattr01testfile"
#define SYMLINK  MNTPOINT"/lremovexattr01symlink"
#else /* HAVE_SYS_XATTR_H */
#endif
