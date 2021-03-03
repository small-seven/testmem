#include "config.h"
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "tst_test.h"
#ifdef HAVE_SYS_XATTR_H
#define SECURITY_KEY1	"security.ltptest1"
#define VALUE	"test"
#define VALUE_SIZE	(sizeof(VALUE) - 1)
#define KEY_SIZE    (sizeof(SECURITY_KEY1) - 1)
#else
#endif /* HAVE_SYS_XATTR_H */
