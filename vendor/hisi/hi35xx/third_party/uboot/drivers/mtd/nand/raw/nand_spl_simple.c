#include <common.h>
#include <nand.h>
#include <asm/io.h>
#include <linux/mtd/nand_ecc.h>
#define ECCSTEPS	(CONFIG_SYS_NAND_PAGE_SIZE / \
#define ECCTOTAL	(ECCSTEPS * CONFIG_SYS_NAND_ECCBYTES)
#if (CONFIG_SYS_NAND_PAGE_SIZE <= 512)
#ifdef CONFIG_SYS_NAND_4_ADDR_CYCLE
#endif
#else
#ifdef CONFIG_SYS_NAND_5_ADDR_CYCLE
#endif
#endif
#if defined(CONFIG_SYS_NAND_HW_ECC_OOBFIRST)
#else
#endif
#ifdef CONFIG_SPL_NAND_SOFTECC
#endif
#include "nand_spl_loaders.c"
