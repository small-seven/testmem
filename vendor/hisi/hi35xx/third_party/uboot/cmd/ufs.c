#include <common.h>
#include <command.h>
#include <ufs.h>
#ifndef CONFIG_UFS
#else
#define UFS_BLKSIZE_SHIFT 12
#define b2m(a) (((a) >> 10) / 1000)
#define b2k(a) (((a) >> 10) % 1000)
#ifdef CONFIG_EXT4_SPARSE
#else
#endif
#endif
