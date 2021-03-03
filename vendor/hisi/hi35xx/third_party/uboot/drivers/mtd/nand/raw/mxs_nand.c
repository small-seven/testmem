#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <linux/mtd/rawnand.h>
#include <linux/sizes.h>
#include <linux/types.h>
#include <malloc.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/mach-imx/regs-bch.h>
#include <asm/mach-imx/regs-gpmi.h>
#include <asm/arch/sys_proto.h>
#include <mxs_nand.h>
#define	MXS_NAND_DMA_DESCRIPTOR_COUNT		4
#if (defined(CONFIG_MX6) || defined(CONFIG_MX7))
#define	MXS_NAND_CHUNK_DATA_CHUNK_SIZE_SHIFT	2
#else
#define	MXS_NAND_CHUNK_DATA_CHUNK_SIZE_SHIFT	0
#endif
#define	MXS_NAND_METADATA_SIZE			10
#define	MXS_NAND_BITS_PER_ECC_LEVEL		13
#if !defined(CONFIG_SYS_CACHELINE_SIZE) || CONFIG_SYS_CACHELINE_SIZE < 32
#define	MXS_NAND_COMMAND_BUFFER_SIZE		32
#else
#define	MXS_NAND_COMMAND_BUFFER_SIZE		CONFIG_SYS_CACHELINE_SIZE
#endif
#define	MXS_NAND_BCH_TIMEOUT			10000
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#else
#endif
#ifdef CONFIG_SYS_NAND_USE_FLASH_BBT
#endif
#ifndef CONFIG_NAND_MXS_DT
#ifdef CONFIG_NAND_MXS_USE_MINIMUM_ECC
#endif
#endif
