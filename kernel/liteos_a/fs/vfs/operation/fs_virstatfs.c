#include "vfs_config.h"
#include "sys/statfs.h"
#include "string.h"
#include "sched.h"
#include "inode/inode.h"
#include "errno.h"
#include "stdlib.h"
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#ifndef CONFIG_DISABLE_MOUNTPOINT
#endif
#endif
