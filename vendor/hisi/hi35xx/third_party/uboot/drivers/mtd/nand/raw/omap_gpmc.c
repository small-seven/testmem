#include <common.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/mem.h>
#include <linux/mtd/omap_gpmc.h>
#include <linux/mtd/nand_ecc.h>
#include <linux/bch.h>
#include <linux/compiler.h>
#include <nand.h>
#include <linux/mtd/omap_elm.h>
#define BADBLOCK_MARKER_LENGTH	2
#define SECTOR_BYTES		512
#define ECCCLEAR		(0x1 << 8)
#define ECCRESULTREG1		(0x1 << 0)
#define BCH4_BIT_PAD		4
#ifdef CONFIG_BCH
#endif
#if defined(CONFIG_NAND_OMAP_GPMC_WSCFG)
#else
#endif
#ifdef CONFIG_BCH
#endif
#ifdef CONFIG_BCH
#endif
#ifdef CONFIG_NAND_OMAP_GPMC_PREFETCH
#define PREFETCH_CONFIG1_CS_SHIFT	24
#define PREFETCH_FIFOTHRESHOLD_MAX	0x40
#define PREFETCH_FIFOTHRESHOLD(val)	((val) << 8)
#define PREFETCH_STATUS_COUNT(val)	(val & 0x00003fff)
#define PREFETCH_STATUS_FIFO_CNT(val)	((val >> 24) & 0x7F)
#define ENABLE_PREFETCH			(1 << 7)
#endif /* CONFIG_NAND_OMAP_GPMC_PREFETCH */
#ifdef CONFIG_NAND_OMAP_ELM
#endif /* CONFIG_NAND_OMAP_ELM */
#ifdef CONFIG_BCH
#ifdef DEBUG
#endif
#endif /* CONFIG_BCH */
#ifdef CONFIG_BCH
#else
#endif
#ifdef CONFIG_NAND_OMAP_ELM
#else
#endif
#ifdef CONFIG_NAND_OMAP_ELM
#else
#endif
#ifndef CONFIG_SPL_BUILD
#endif /* CONFIG_SPL_BUILD */
#if defined(CONFIG_SYS_NAND_BUSWIDTH_16BIT)
#else
#endif
#if defined(CONFIG_NAND_OMAP_ECCSCHEME)
#else
#endif
#ifdef CONFIG_NAND_OMAP_GPMC_PREFETCH
#else
#endif
