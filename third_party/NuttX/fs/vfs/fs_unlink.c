#include "vfs_config.h"
#include "unistd.h"
#include "errno.h"
#include "fs/fs.h"
#include "fcntl.h"
#include "inode/inode.h"
#include "stdlib.h"
#include "fs_other.h"
#undef FS_HAVE_WRITABLE_MOUNTPOINT
#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_WRITABLE) && \
#  define FS_HAVE_WRITABLE_MOUNTPOINT 1
#endif
#undef FS_HAVE_PSEUDOFS_OPERATIONS
#if !defined(CONFIG_DISABLE_PSEUDOFS_OPERATIONS) && CONFIG_NFILE_STREAMS > 0
#  define FS_HAVE_PSEUDOFS_OPERATIONS 1
#endif
#undef FS_HAVE_UNLINK
#if defined(FS_HAVE_WRITABLE_MOUNTPOINT) || defined(FS_HAVE_PSEUDOFS_OPERATIONS)
#  define FS_HAVE_UNLINK 1
#endif
#ifdef FS_HAVE_UNLINK
#ifndef CONFIG_DISABLE_MOUNTPOINT
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#ifndef CONFIG_DISABLE_MOUNTPOINT
#endif
#endif
#endif /* FS_HAVE_UNLINK */
