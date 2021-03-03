#include <common.h>
#include <linux/errno.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand_ecc.h>
#if !defined(CONFIG_NAND_SPL) || defined(CONFIG_SPL_NAND_SOFTECC)
#endif /* CONFIG_NAND_SPL */
