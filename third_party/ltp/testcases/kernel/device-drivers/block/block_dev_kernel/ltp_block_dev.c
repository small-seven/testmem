#include <linux/module.h>
#include <linux/device.h>
#include <linux/fs.h>
#define BLK_DEV_NAME		"ltp_block_dev"
#define MAX_MAJOR		255
#define prk_err(fmt, ...) \
#define prk_info(fmt, ...) \
#define prk_debug(fmt, ...) \
#define result_str(pass) ((pass == 0) ? ("FAIL") : ("PASS"))
#ifdef BLKDEV_MAJOR_MAX
#endif
#ifndef BLKDEV_MAJOR_MAX
#endif
