#include "vfs_config.h"
#include "stdarg.h"
#include "fcntl.h"
#include "errno.h"
#include "assert.h"
#include "fs/fs.h"
#include "inode/inode.h"
#if defined(LOSCFG_NET_LWIP_SACK)
#include "lwip/sockets.h"
#endif
#define FAPPEND     O_APPEND
#define FFSYNC      O_SYNC
#define FNONBLOCK   O_NONBLOCK
#define FNDELAY     O_NDELAY
#define FFCNTL      (FNONBLOCK | FNDELAY | FAPPEND | FFSYNC | FASYNC)
#if CONFIG_NFILE_DESCRIPTORS > 0
#endif /* CONFIG_NFILE_DESCRIPTORS > 0 */
#if CONFIG_NFILE_DESCRIPTORS > 0
#endif
#if defined(LOSCFG_NET_LWIP_SACK)
#endif
#if CONFIG_NFILE_DESCRIPTORS > 0
#endif
#if defined(LOSCFG_NET_LWIP_SACK)
#endif
