#include "vfs_config.h"
#include "sys/select.h"
#include "string.h"
#include "unistd.h"
#include "poll.h"
#include "assert.h"
#include "errno.h"
#include "debug.h"
#include "stdlib.h"
#include "fs/fs.h"
#include "los_syscall.h"
#include "inode/inode.h"
#ifndef CONFIG_DISABLE_POLL
#define POLL_IN_SET (POLLIN | POLLRDNORM | POLLRDBAND | POLLHUP | POLLERR)
#define POLL_OUT_SET (POLLOUT | POLLWRBAND | POLLWRNORM | POLLERR)
#define POLL_EX_SET (POLLPRI)
#define POLL_STACK_CNT 5
#endif /* CONFIG_DISABLE_POLL */
