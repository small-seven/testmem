#define _GNU_SOURCE
#include "config.h"
#include <sys/ioctl.h>
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
#include "lapi/fs.h"
#include "tst_test.h"
#if defined HAVE_SYS_XATTR_H
#define XATTR_TEST_KEY "user.testkey"
#define XATTR_TEST_VALUE "this is a test value"
#define XATTR_TEST_VALUE_SIZE (sizeof(XATTR_TEST_VALUE) - 1)
#define IMMU_FILE "setxattr03immutable"
#define APPEND_FILE  "setxattr03appendonly"
#define set_immutable_on(fd) fsetflag(fd, 1, 1)
#define set_immutable_off(fd) fsetflag(fd, 0, 1)
#define set_append_on(fd) fsetflag(fd, 1, 0)
#define set_append_off(fd) fsetflag(fd, 0, 0)
#else
#endif /* defined HAVE_SYS_XATTR_H */
