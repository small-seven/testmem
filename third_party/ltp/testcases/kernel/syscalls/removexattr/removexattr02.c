#include "config.h"
#include <errno.h>
#include <sys/types.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#include "test.h"
#include "safe_macros.h"
#ifdef HAVE_SYS_XATTR_H
#else /* HAVE_SYS_XATTR_H */
#endif
