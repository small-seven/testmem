#include "fs/fs.h"
#include "errno.h"
#include "string.h"
#include "stdlib.h"
#include "capability_api.h"
#include "inode/inode.h"
#include "sys/stat.h"
#ifndef CONFIG_DISABLE_MOUNTPOINT /* Check inode is not mount and has i_ops or like /dev dir */
#else
#endif
