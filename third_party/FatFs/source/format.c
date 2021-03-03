#include "errno.h"
#include "fatfs.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include "errcode_fat.h"
#include "integer.h"
#ifdef LOSCFG_FS_FAT
#define DEV_NAME_SIZE	4
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#endif	/* #ifdef CONFIG_FS_FAT */
