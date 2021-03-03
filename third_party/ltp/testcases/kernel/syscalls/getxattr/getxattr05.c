#define _GNU_SOURCE
#include "config.h"
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>
#include <stdlib.h>
#ifdef HAVE_SYS_XATTR_H
# include <sys/xattr.h>
#endif
#ifdef HAVE_LIBACL
# include <sys/acl.h>
#endif
#include "tst_test.h"
#include "lapi/namespaces_constants.h"
#if defined(HAVE_SYS_XATTR_H) && defined(HAVE_LIBACL)
#define TEST_FILE	"testfile"
#define SELF_USERNS	"/proc/self/ns/user"
#define MAX_USERNS	"/proc/sys/user/max_user_namespaces"
#define UID_MAP	"/proc/self/uid_map"
#else /* HAVE_SYS_XATTR_H && HAVE_LIBACL*/
#endif
