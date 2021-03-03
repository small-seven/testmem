#include "ubifs.h"
#ifndef __UBOOT__
#include <linux/slab.h>
#include <linux/random.h>
#include <linux/math64.h>
#else
#include <linux/compat.h>
#include <linux/err.h>
#include <ubi_uboot.h>
#include <linux/stat.h>
#endif
#define DEFAULT_JNL_PERCENT 5
#define DEFAULT_MAX_JNL (32*1024*1024)
#define DEFAULT_FANOUT 8
#define DEFAULT_JHEADS_CNT 1
#define DEFAULT_IDX_LEB  0
#define DEFAULT_DATA_LEB 1
#define DEFAULT_GC_LEB   2
#define DEFAULT_LSAVE_CNT 256
#define DEFAULT_RP_PERCENT 5
#define DEFAULT_MAX_RP_SIZE (5*1024*1024)
#define DEFAULT_TIME_GRAN 1000000000
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
