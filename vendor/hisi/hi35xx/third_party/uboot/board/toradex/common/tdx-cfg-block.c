#include <common.h>
#include "tdx-cfg-block.h"
#if defined(CONFIG_TARGET_APALIS_IMX6) || \
#include <asm/arch/sys_proto.h>
#else
#define is_cpu_type(cpu) (0)
#endif
#if defined(CONFIG_CPU_PXA27X)
#include <asm/arch-pxa/pxa.h>
#else
#define cpu_is_pxa27x(cpu) (0)
#endif
#include <cli.h>
#include <console.h>
#include <env.h>
#include <flash.h>
#include <malloc.h>
#include <mmc.h>
#include <nand.h>
#include <asm/mach-types.h>
#define TAG_VALID	0xcf01
#define TAG_MAC		0x0000
#define TAG_HW		0x0008
#define TAG_INVALID	0xffff
#define TAG_FLAG_VALID	0x1
#if defined(CONFIG_TDX_CFG_BLOCK_IS_IN_MMC)
#define TDX_CFG_BLOCK_MAX_SIZE 512
#elif defined(CONFIG_TDX_CFG_BLOCK_IS_IN_NAND)
#define TDX_CFG_BLOCK_MAX_SIZE 64
#elif defined(CONFIG_TDX_CFG_BLOCK_IS_IN_NOR)
#define TDX_CFG_BLOCK_MAX_SIZE 64
#else
#error Toradex config block location not set
#endif
#ifdef CONFIG_TDX_CFG_BLOCK_IS_IN_MMC
#endif
#ifdef CONFIG_TDX_CFG_BLOCK_IS_IN_NAND
#endif
#ifdef CONFIG_TDX_CFG_BLOCK_IS_IN_NOR
#endif
#if defined(CONFIG_TDX_CFG_BLOCK_IS_IN_MMC)
#elif defined(CONFIG_TDX_CFG_BLOCK_IS_IN_NAND)
#elif defined(CONFIG_TDX_CFG_BLOCK_IS_IN_NOR)
#else
#endif
#if defined(CONFIG_TARGET_APALIS_IMX8) || \
#endif
#ifdef CONFIG_TARGET_APALIS_IMX6
#elif CONFIG_TARGET_COLIBRI_IMX6
#elif CONFIG_TARGET_COLIBRI_IMX6ULL
#endif
#ifdef CONFIG_MACH_TYPE
#endif /* CONFIG_MACH_TYPE */
#if defined(CONFIG_TDX_CFG_BLOCK_IS_IN_NAND)
#elif defined(CONFIG_TDX_CFG_BLOCK_IS_IN_NOR)
#else
#endif
#if defined(CONFIG_TDX_CFG_BLOCK_IS_IN_MMC)
#elif defined(CONFIG_TDX_CFG_BLOCK_IS_IN_NAND)
#elif defined(CONFIG_TDX_CFG_BLOCK_IS_IN_NOR)
#else
#endif
