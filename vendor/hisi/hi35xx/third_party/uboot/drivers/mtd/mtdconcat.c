#ifndef __UBOOT__
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/backing-dev.h>
#include <asm/div64.h>
#else
#include <div64.h>
#include <linux/compat.h>
#endif
#include <linux/mtd/mtd.h>
#include <linux/mtd/concat.h>
#include <ubi_uboot.h>
#define SIZEOF_STRUCT_MTD_CONCAT(num_subdev)	\
#define CONCAT(x)  ((struct mtd_concat *)(x))
#ifdef __UBOOT__
#endif
#ifdef __UBOOT__
#endif
#ifndef __UBOOT__
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
void mtd_concat_destroy(struct mtd_info *mtd)
{
	struct mtd_concat *concat = CONCAT(mtd);
	if (concat->mtd.numeraseregions)
		kfree(concat->mtd.eraseregions);
	kfree(concat);
}
