#include "tool_setup.h"
#ifdef HAVE_FSETXATTR
#  include <sys/xattr.h> /* header from libc, not from libattr */
#  define USE_XATTR
#elif defined(__FreeBSD_version) && (__FreeBSD_version > 500000)
#  include <sys/types.h>
#  include <sys/extattr.h>
#  define USE_XATTR
#endif
#include "tool_xattr.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef USE_XATTR
#ifdef UNITTESTS
#else
#endif
#ifdef HAVE_FSETXATTR_6
#elif defined(HAVE_FSETXATTR_5)
#elif defined(__FreeBSD_version)
#endif
#else
#endif
