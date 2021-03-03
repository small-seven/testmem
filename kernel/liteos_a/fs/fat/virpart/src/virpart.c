#include "virpart.h"
#include "errno.h"
#include "fatfs.h"
#include "dirop_fat.h"
#include "errcode_fat.h"
#include "disk.h"
#ifdef LOSCFG_FS_FAT_CACHE
#include "bcache.h"
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#include "virpartff.h"
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#if FF_MAX_SS != FF_MIN_SS
#else
#endif
#if FF_USE_LFN
#else
#endif
#endif