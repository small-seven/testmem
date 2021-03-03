#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/pm.h>
#include <linux/genhd.h>
#include <linux/bio.h>
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/bio.h>
#include <linux/blk.h>
#include <linux/slab.h>
#include <linux/mempool.h>
#include <linux/workqueue.h>
#include <linux/namei.h>
#include <linux/mount.h>
#include <linux/quotaops.h>
#include <linux/pagemap.h>
#include <linux/dnotify.h>
#include <linux/smp_lock.h>
#include <linux/personality.h>
#include <linux/security.h>
#include <linux/buffer_head.h>
#include <asm/namei.h>
#include <asm/uaccess.h>
#define ACC_MODE(x) ("\000\004\002\006"[(x)&O_ACCMODE])
#define IS_POSIX(fl)	(fl->fl_flags & FL_POSIX)
#define TEST_MEM_SIZE  4096
#define FALSE          0
#include "Ltpfs.h"
