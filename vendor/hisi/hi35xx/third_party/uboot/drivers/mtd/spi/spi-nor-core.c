#include <common.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/log2.h>
#include <linux/math64.h>
#include <linux/sizes.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/spi-nor.h>
#include <spi-mem.h>
#include <spi.h>
#include "sf_internal.h"
#define HZ					CONFIG_SYS_HZ
#define DEFAULT_READY_WAIT_JIFFIES		(40UL * HZ)
#if defined(CONFIG_SPI_FLASH_SPANSION) || defined(CONFIG_SPI_FLASH_WINBOND)
#endif
#ifndef CONFIG_SPI_FLASH_BAR
#endif /* !CONFIG_SPI_FLASH_BAR */
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#if defined(CONFIG_SPI_FLASH_STMICRO) || defined(CONFIG_SPI_FLASH_SST)
#endif /* CONFIG_SPI_FLASH_STMICRO */
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SPI_FLASH_SST
#define SST26_BPR_8K_NUM		4
#define SST26_MAX_BPR_REG_LEN		(18 + 1)
#define SST26_BOUND_REG_SIZE		((32 + SST26_BPR_8K_NUM * 8) * SZ_1K)
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SPI_FLASH_MACRONIX
#endif
#if defined(CONFIG_SPI_FLASH_SPANSION) || defined(CONFIG_SPI_FLASH_WINBOND)
#if CONFIG_IS_ENABLED(SPI_FLASH_SFDP_SUPPORT)
#endif /* CONFIG_SPI_FLASH_SFDP_SUPPORT */
#endif /* CONFIG_SPI_FLASH_SPANSION */
#if CONFIG_IS_ENABLED(SPI_FLASH_SFDP_SUPPORT)
#define SFDP_PARAM_HEADER_ID(p)	(((p)->id_msb << 8) | (p)->id_lsb)
#define SFDP_PARAM_HEADER_PTP(p) \
#define SFDP_BFPT_ID		0xff00	/* Basic Flash Parameter Table */
#define SFDP_SECTOR_MAP_ID	0xff81	/* Sector Map Table */
#define SFDP_SIGNATURE		0x50444653U
#define SFDP_JESD216_MAJOR	1
#define SFDP_JESD216_MINOR	0
#define SFDP_JESD216A_MINOR	5
#define SFDP_JESD216B_MINOR	6
#define BFPT_DWORD(i)		((i) - 1)
#define BFPT_DWORD_MAX		16
#define BFPT_DWORD_MAX_JESD216			9
#define BFPT_DWORD1_FAST_READ_1_1_2		BIT(16)
#define BFPT_DWORD1_ADDRESS_BYTES_MASK		GENMASK(18, 17)
#define BFPT_DWORD1_ADDRESS_BYTES_3_ONLY	(0x0UL << 17)
#define BFPT_DWORD1_ADDRESS_BYTES_3_OR_4	(0x1UL << 17)
#define BFPT_DWORD1_ADDRESS_BYTES_4_ONLY	(0x2UL << 17)
#define BFPT_DWORD1_DTR				BIT(19)
#define BFPT_DWORD1_FAST_READ_1_2_2		BIT(20)
#define BFPT_DWORD1_FAST_READ_1_4_4		BIT(21)
#define BFPT_DWORD1_FAST_READ_1_1_4		BIT(22)
#define BFPT_DWORD5_FAST_READ_2_2_2		BIT(0)
#define BFPT_DWORD5_FAST_READ_4_4_4		BIT(4)
#define BFPT_DWORD11_PAGE_SIZE_SHIFT		4
#define BFPT_DWORD11_PAGE_SIZE_MASK		GENMASK(7, 4)
#define BFPT_DWORD15_QER_MASK			GENMASK(22, 20)
#define BFPT_DWORD15_QER_NONE			(0x0UL << 20) /* Micron */
#define BFPT_DWORD15_QER_SR2_BIT1_BUGGY		(0x1UL << 20)
#define BFPT_DWORD15_QER_SR1_BIT6		(0x2UL << 20) /* Macronix */
#define BFPT_DWORD15_QER_SR2_BIT7		(0x3UL << 20)
#define BFPT_DWORD15_QER_SR2_BIT1_NO_RD		(0x4UL << 20)
#define BFPT_DWORD15_QER_SR2_BIT1		(0x5UL << 20) /* Spansion */
#ifdef CONFIG_SPI_FLASH_USE_4K_SECTORS
#endif
#if defined(CONFIG_SPI_FLASH_SPANSION) || defined(CONFIG_SPI_FLASH_WINBOND)
#endif
#ifdef CONFIG_SPI_FLASH_MACRONIX
#endif
#if defined(CONFIG_SPI_FLASH_SPANSION) || defined(CONFIG_SPI_FLASH_WINBOND)
#endif
#else
#endif /* SPI_FLASH_SFDP_SUPPORT */
#ifdef CONFIG_SPI_FLASH_MACRONIX
#endif
#if defined(CONFIG_SPI_FLASH_SPANSION) || defined(CONFIG_SPI_FLASH_WINBOND)
#endif
#ifdef CONFIG_SPI_FLASH_USE_4K_SECTORS
#endif
#if defined(CONFIG_SPI_FLASH_STMICRO) || defined(CONFIG_SPI_FLASH_SST)
#endif
#ifdef CONFIG_SPI_FLASH_SST
#endif
#ifndef CONFIG_SPI_FLASH_BAR
#else
#endif
#ifndef CONFIG_SPL_BUILD
#endif
