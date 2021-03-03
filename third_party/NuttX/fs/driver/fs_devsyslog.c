#include "los_task.h"
#include "vfs_config.h"
#include "sys/types.h"
#include "stdint.h"
#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "semaphore.h"
#include "assert.h"
#include "fs/fs.h"
#include "inode/inode.h"
#if defined(CONFIG_SYSLOG) && defined(CONFIG_SYSLOG_CHAR)
#define SYSLOG_OFLAGS (O_WRONLY | O_CREAT | O_APPEND)
#define NO_HOLDER     ((pid_t)-1)
#ifdef CONFIG_DEBUG
#endif
#ifndef CONFIG_DISABLE_MOUNTPOINT
#endif
#ifndef CONFIG_DISABLE_MOUNTPOINT
#else
#endif
#ifndef CONFIG_DISABLE_MOUNTPOINT
#endif
#ifndef CONFIG_DISABLE_MOUNTPOINT
#endif
#endif /* CONFIG_SYSLOG && CONFIG_SYSLOG_CHAR */
