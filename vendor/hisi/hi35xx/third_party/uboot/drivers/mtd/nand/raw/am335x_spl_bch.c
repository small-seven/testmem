#include <common.h>
#include <nand.h>
#include <asm/io.h>
#include <linux/mtd/nand_ecc.h>
#define ECCSTEPS	(CONFIG_SYS_NAND_PAGE_SIZE / \
#define ECCTOTAL	(ECCSTEPS * CONFIG_SYS_NAND_ECCBYTES)
#ifdef CONFIG_SYS_NAND_5_ADDR_CYCLE
#endif
#include "nand_spl_loaders.c"
