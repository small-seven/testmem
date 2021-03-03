#include "config.h"
#include <errno.h>
#include <sys/types.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "tst_test.h"
#ifdef HAVE_SYS_XATTR_H
#define SECURITY_KEY	"security.ltptest"
#define VALUE	"test"
#define VALUE_SIZE	(sizeof(VALUE) - 1)
#define TESTFILE    "testfile"
#else /* HAVE_SYS_XATTR_H */
#endif
