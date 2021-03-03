#include "los_config.h"
#include "sys/mount.h"
#ifdef LOSCFG_SHELL
#include "los_typedef.h"
#include "los_typedef.h"
#include "shell.h"
#include "fs/fs.h"
#include "sys/stat.h"
#include "inode/inode.h"
#include "stdlib.h"
#include "unistd.h"
#include "fs_other.h"
#include "fcntl.h"
#include "sys/statfs.h"
#include "stdio.h"
#include "pthread.h"

#include "shcmd.h"
#include "securec.h"
#include "show.h"
#include "los_syscall.h"

#include "los_process_pri.h"
#include <ctype.h>

typedef enum
{
  RM_RECURSIVER,
  RM_FILE,
  RM_DIR,
  CP_FILE,
  CP_COUNT
} wildcard_type;
#define ERROR_OUT_IF(condition, message_function, handler) \
#define CAT_BUF_SIZE  512
#define CAT_TASK_PRIORITY  10
#define CAT_TASK_STACK_SIZE  0x3000
#define CP_BUF_SIZE 4096
#define SEPARATOR_EOF_LEN 2
#define MODE_BIT 3 /* 3 bits express 1 mode */
#ifdef LOSCFG_SHELL_CMD_DEBUG
#if (defined(LOSCFG_FS_FAT) || defined(LOSCFG_FS_RAMFS) ||  defined(LOSCFG_FS_JFFS))
#endif
#if (defined(LOSCFG_FS_FAT))
#endif
#endif
#if (defined(LOSCFG_FS_FAT) || defined(LOSCFG_FS_RAMFS) ||  defined(LOSCFG_FS_JFFS))
#endif
#if (defined(LOSCFG_FS_FAT) || defined(LOSCFG_FS_RAMFS) || defined(LOSCFG_FS_JFFS))
#endif
#endif
