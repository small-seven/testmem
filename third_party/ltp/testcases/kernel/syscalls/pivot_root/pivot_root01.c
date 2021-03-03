#define _GNU_SOURCE
#include "config.h"
#include <errno.h>
#include <lapi/syscalls.h>
#include <sched.h>
#include <sys/mount.h>
#include <stdlib.h>
#include "tst_test.h"
#include "lapi/mount.h"
#ifdef HAVE_UNSHARE
#ifdef HAVE_LIBCAP
#include <sys/capability.h>
#endif
#define CHROOT_DIR	"chroot"
#define NEW_ROOT	"/new_root"
#define PUT_OLD		"/new_root/put_old"
#define PUT_OLD_FS	"/put_old_fs"
#define PUT_OLD_BAD	"/put_old_fs/put_old"
#ifdef HAVE_LIBCAP
#endif
#ifdef HAVE_LIBCAP
#else
#endif
#else
#endif
