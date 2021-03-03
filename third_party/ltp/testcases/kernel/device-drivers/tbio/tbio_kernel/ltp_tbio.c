#include <linux/module.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/vmalloc.h>
#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/buffer_head.h>
#include "tbio.h"
#define prk_err(fmt, ...) \
#define prk_info(fmt, ...) \
#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 10, 0)
#else
#endif
#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 10, 0)
#endif
