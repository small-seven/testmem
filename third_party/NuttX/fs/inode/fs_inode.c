#include "vfs_config.h"
#include "assert.h"
#include "errno.h"
#include "semaphore.h"
#include "stdlib.h"
#include "fs/fs.h"
#include "unistd.h"
#include "inode/inode.h"
#define NO_HOLDER ((pid_t)-1)
#ifdef CONFIG_HAVE_WEAKFUNCTIONS
#endif
