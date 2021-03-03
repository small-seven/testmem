#include <common.h>
#include <asm/gpio.h>
#include <asm/arch/gpio.h>
#include <malloc.h>
#include <nand.h>
#include <watchdog.h>
#include <linux/mtd/nand_ecc.h>
#ifdef CONFIG_ATMEL_NAND_HWECC
#define ecc_readl(add, reg)				\
#define ecc_writel(add, reg, value)			\
#include "atmel_nand_ecc.h"	/* Hardware ECC registers */
#ifdef CONFIG_ATMEL_NAND_HW_PMECC
#ifdef CONFIG_SPL_BUILD
#undef CONFIG_SYS_NAND_ONFI_DETECTION
#endif
static void pmecc_data_free(struct atmel_nand_host *host)
{
	free(host->pmecc_partial_syn);
	free(host->pmecc_si);
	free(host->pmecc_lmu);
	free(host->pmecc_smu);
	free(host->pmecc_mu);
	free(host->pmecc_dmu);
	free(host->pmecc_delta);
}
#ifdef CONFIG_SYS_NAND_ONFI_DETECTION
#ifdef CONFIG_SAMA5D2
#else
#endif
#endif
#if defined(NO_GALOIS_TABLE_IN_ROM)
#endif
#ifdef CONFIG_SYS_NAND_ONFI_DETECTION
#ifdef CONFIG_PMECC_CAP
#endif
#ifdef CONFIG_PMECC_SECTOR_SIZE
#endif
#else	/* CONFIG_SYS_NAND_ONFI_DETECTION */
#endif
#if defined(NO_GALOIS_TABLE_IN_ROM)
#else
#endif
#if defined(NO_GALOIS_TABLE_IN_ROM)
#else
#endif
#else
#endif /* CONFIG_ATMEL_NAND_HW_PMECC */
#endif /* CONFIG_ATMEL_NAND_HWECC */
#ifdef CONFIG_SYS_NAND_ENABLE_PIN
#endif
#ifdef CONFIG_SYS_NAND_READY_PIN
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_SYS_NAND_5_ADDR_CYCLE
#endif
#ifdef CONFIG_SPL_NAND_ECC
#define ECCSTEPS (CONFIG_SYS_NAND_PAGE_SIZE / \
#define ECCTOTAL (ECCSTEPS * CONFIG_SYS_NAND_ECCBYTES)
#ifdef CONFIG_SYS_NAND_5_ADDR_CYCLE
#endif
#else
#endif /* CONFIG_SPL_NAND_ECC */
#ifdef CONFIG_SYS_NAND_DBW_16
#else
#endif
#ifdef CONFIG_SYS_NAND_READY_PIN
#else
#endif
#ifdef CONFIG_SYS_NAND_USE_FLASH_BBT
#endif
#ifdef CONFIG_ATMEL_NAND_HWECC
#ifdef CONFIG_ATMEL_NAND_HW_PMECC
#endif
#endif
#ifdef CONFIG_SPL_NAND_ECC
#endif
#include "nand_spl_loaders.c"
#else
#ifndef CONFIG_SYS_NAND_BASE_LIST
#define CONFIG_SYS_NAND_BASE_LIST { CONFIG_SYS_NAND_BASE }
#endif
#ifdef CONFIG_NAND_ECC_BCH
#else
#endif
#ifdef CONFIG_SYS_NAND_DBW_16
#endif
#ifdef CONFIG_SYS_NAND_READY_PIN
#endif
#ifdef CONFIG_SYS_NAND_USE_FLASH_BBT
#endif
#ifdef CONFIG_ATMEL_NAND_HWECC
#ifdef CONFIG_ATMEL_NAND_HW_PMECC
#else
#endif
#endif
#endif /* CONFIG_SPL_BUILD */
