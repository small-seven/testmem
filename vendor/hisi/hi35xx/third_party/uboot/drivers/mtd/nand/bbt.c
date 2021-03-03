#define pr_fmt(fmt)	"nand-bbt: " fmt
#include <common.h>
#include <linux/mtd/nand.h>
#ifndef __UBOOT__
#include <linux/slab.h>
#endif
