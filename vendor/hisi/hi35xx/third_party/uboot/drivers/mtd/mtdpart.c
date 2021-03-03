#ifndef __UBOOT__
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/kmod.h>
#endif
#include <common.h>
#include <malloc.h>
#include <linux/errno.h>
#include <linux/compat.h>
#include <ubi_uboot.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/err.h>
#include <linux/sizes.h>
#include "mtdcore.h"
#ifndef __UBOOT__
#else
#endif
#ifdef __UBOOT__
#endif
#define MTD_SIZE_REMAINING		(~0LLU)
#define MTD_OFFSET_NOT_SPECIFIED	(~0LLU)
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#define put_partition_parser(p) do { module_put((p)->owner); } while (0)
#endif
