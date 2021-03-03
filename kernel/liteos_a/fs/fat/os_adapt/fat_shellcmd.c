#include "los_config.h"
#if defined(LOSCFG_SHELL) && defined(LOSCFG_FS_FAT)
#include "stdlib.h"
#include "stdio.h"
#include "errno.h"
#include "shcmd.h"
#include "shell.h"
#include "fs/fs.h"
#include "fatfs.h"
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if defined(LOSCFG_FS_FAT_VIRTUAL_PARTITION) && defined(LOSCFG_SHELL_CMD_DEBUG)
#endif
#endif
