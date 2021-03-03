#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>
#include "fs/fs.h"
#include "driver/blockproxy.h"
#if !defined(CONFIG_DISABLE_MOUNTPOINT)
#ifdef LOSCFG_FS_VFS_BLOCK_DEVICE
#endif
#endif /* !CONFIG_DISABLE_MOUNTPOINT */
