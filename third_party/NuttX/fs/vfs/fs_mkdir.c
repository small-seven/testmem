#include "vfs_config.h"
#include "errno.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fs/fs.h"
#include "stdlib.h"
#include "inode/inode.h"
#include "string.h"
#include "fs_other.h"
#include "capability_api.h"
#undef FS_HAVE_WRITABLE_MOUNTPOINT
#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_WRITABLE) && \
#  define FS_HAVE_WRITABLE_MOUNTPOINT 1
#endif
#undef FS_HAVE_PSEUDOFS_OPERATIONS
#if !defined(CONFIG_DISABLE_PSEUDOFS_OPERATIONS) && CONFIG_NFILE_STREAMS > 0
#  define FS_HAVE_PSEUDOFS_OPERATIONS 1
#endif
#undef FS_HAVE_MKDIR
#if defined(FS_HAVE_WRITABLE_MOUNTPOINT) || defined(FS_HAVE_PSEUDOFS_OPERATIONS)
#  define FS_HAVE_MKDIR 1
#endif
#ifdef FS_HAVE_MKDIR
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#endif
#ifndef CONFIG_DISABLE_MOUNTPOINT
#else
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#else
#endif
#endif /* FS_HAVE_MKDIR */
