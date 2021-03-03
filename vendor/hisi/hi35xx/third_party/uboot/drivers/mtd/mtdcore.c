#ifndef __UBOOT__
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/ptrace.h>
#include <linux/seq_file.h>
#include <linux/string.h>
#include <linux/timer.h>
#include <linux/major.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/ioctl.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/idr.h>
#include <linux/backing-dev.h>
#include <linux/gfp.h>
#include <linux/slab.h>
#else
#include <linux/err.h>
#include <ubi_uboot.h>
#endif
#include <linux/log2.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include "mtdcore.h"
#ifndef __UBOOT__
#else
#define MAX_IDR_ID	64
#define DEFINE_IDR(name)	struct idr name;
void idr_remove(struct idr *idp, int id)
{
	if (idp->id[id].used) {
		idp->id[id].used = 0;
		idp->updated = true;
	}

	return;
}
#endif
#ifndef __UBOOT__
#define MTD_DEVT(index) MKDEV(MTD_CHAR_MAJOR, (index)*2)
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
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
#if defined(CONFIG_CMD_MTDPARTS_SPREAD)
#endif /* defined(CONFIG_CMD_MTDPARTS_SPREAD) */
#ifndef __UBOOT__
#endif
int mtd_ooblayout_free(struct mtd_info *mtd, int section,
		       struct mtd_oob_region *oobfree)
{
	memset(oobfree, 0, sizeof(*oobfree));

	if (!mtd || section < 0)
		return -EINVAL;

	if (!mtd->ooblayout || !mtd->ooblayout->free)
		return -ENOTSUPP;

	return mtd->ooblayout->free(mtd, section, oobfree);
}
#ifndef __UBOOT__
#endif
#ifdef CONFIG_PROC_FS
#endif /* CONFIG_PROC_FS */
#ifndef __UBOOT__
#endif
