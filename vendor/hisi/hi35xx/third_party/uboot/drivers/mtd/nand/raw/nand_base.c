#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt
#include <common.h>
#if CONFIG_IS_ENABLED(OF_CONTROL)
#include <fdtdec.h>
#endif
#include <malloc.h>
#include <watchdog.h>
#include <linux/err.h>
#include <linux/compat.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/nand_ecc.h>
#include <linux/mtd/nand_bch.h>
#ifdef CONFIG_MTD_PARTITIONS
#include <linux/mtd/partitions.h>
#endif
#include <asm/io.h>
#include <linux/errno.h>
#include <hinfc_common.h>
#ifndef CONFIG_SYS_NAND_DRIVER_ECC_LAYOUT
#endif
#define NOTALIGNED(x)	((x & (chip->subpagesize - 1)) != 0)
#if defined(CONFIG_HIFMC_SPI_NAND)|| defined(CONFIG_HIFMC_NAND)
#endif
#ifdef CONFIG_SYS_NAND_ONFI_DETECTION
#endif
#ifdef CONFIG_SYS_NAND_ONFI_DETECTION
#endif
#ifdef CONFIG_SYS_NAND_ONFI_DETECTION
#else
#endif
#ifdef CONFIG_HIFMC
#endif
#ifdef CONFIG_HIFMC
#endif
#ifdef CONFIG_SYS_NAND_ONFI_DETECTION
#else
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#else
#endif /* CONFIG_IS_ENABLED(OF_CONTROL) */
#ifdef DEBUG
#endif
#ifndef CONFIG_SYS_NAND_DRIVER_ECC_LAYOUT
#endif
