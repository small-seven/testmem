#include <common.h>
#include <nand.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <linux/err.h>
#include <linux/mtd/nand_ecc.h>
#include <linux/mtd/fsmc_nand.h>
#include <asm/arch/hardware.h>
#ifndef CONFIG_SPL_BUILD
#endif /* CONFIG_SPL_BUILD */
#if defined(CONFIG_SYS_FSMC_NAND_16BIT)
#elif defined(CONFIG_SYS_FSMC_NAND_8BIT)
#else
#error Please define CONFIG_SYS_FSMC_NAND_16BIT or CONFIG_SYS_FSMC_NAND_8BIT
#endif
#if defined(CONFIG_SYS_FSMC_NAND_16BIT)
#endif
