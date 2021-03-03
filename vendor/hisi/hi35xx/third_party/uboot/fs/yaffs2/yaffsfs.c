#include <div64.h>
#include "yaffsfs.h"
#include "yaffs_guts.h"
#include "yaffscfg.h"
#include "yportenv.h"
#include "yaffs_trace.h"
#define YAFFSFS_MAX_SYMLINK_DEREFERENCES 5
#ifndef NULL
#define NULL ((void *)0)
#endif
#define YAFFSFS_RW_SHIFT (13)
#define YAFFSFS_RW_SIZE  (1<<YAFFSFS_RW_SHIFT)
#ifdef CONFIG_YAFFS_CASE_INSENSITIVE
#else
#endif
#if CONFIG_YAFFS_WINCE
#else
#endif
#ifndef CONFIG_YAFFS_WINCE
#endif
#ifdef CONFIG_YAFFS_WINCE
#endif
#if 0
#endif
