#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "test.h"
#include "safe_macros.h"
#ifdef HAVE_SYS_XATTR_H
#define XATTR_TEST_KEY "user.testkey"
#define XATTR_TEST_VALUE "test value"
#define XATTR_TEST_VALUE_SIZE (sizeof(XATTR_TEST_VALUE) - 1)
#define TESTFILE "getxattr03testfile"
#else /* HAVE_SYS_XATTR_H */
#endif
