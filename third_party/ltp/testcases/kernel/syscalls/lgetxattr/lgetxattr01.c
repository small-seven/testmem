#include "config.h"
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "tst_test.h"
#ifdef HAVE_SYS_XATTR_H
#define SECURITY_KEY1   "security.ltptest1"
#define SECURITY_KEY2   "security.ltptest2"
#define VALUE1   "test1"
#define VALUE2   "test2"
#else
#endif /* HAVE_SYS_XATTR_H */
