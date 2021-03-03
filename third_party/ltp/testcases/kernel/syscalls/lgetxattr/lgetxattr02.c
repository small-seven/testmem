#include "config.h"
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "tst_test.h"
#ifdef HAVE_SYS_XATTR_H
#define SECURITY_KEY	"security.ltptest"
#define VALUE	"this is a test value"
#else /* HAVE_SYS_XATTR_H */
#endif
