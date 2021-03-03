#include <common.h>
#include <linux/errno.h>
#include "yportenv.h"
#include "yaffs_trace.h"
#include "yaffs_mtdif2.h"
#include <linux/mtd/mtd.h>
#include <linux/types.h>
#include <linux/time.h>
#include "yaffs_trace.h"
#include "yaffs_packedtags2.h"
#define yaffs_dev_to_mtd(dev) ((struct mtd_info *)((dev)->driver_context))
#define yaffs_dev_to_lc(dev) ((struct yaffs_linux_context *)((dev)->os_context))
