#include <common.h>
#include <cpu_func.h>
#include <linux/compiler.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <asm/arch/clock.h>
#include <asm/arch/soc.h>
#include <fsl_ifc.h>
#include "cpu.h"
#ifndef CONFIG_SYS_FSL_NUM_CC_PLLS
#define CONFIG_SYS_FSL_NUM_CC_PLLS      2
#endif
#if defined(CONFIG_SYS_DPAA_FMAN) || \
#endif
#ifndef CONFIG_CLUSTER_CLK_FREQ
#define CONFIG_CLUSTER_CLK_FREQ	CONFIG_SYS_CLK_FREQ
#endif
#ifdef CONFIG_DDR_CLK_FREQ
#else
#endif
#ifdef CONFIG_ARCH_LS1012A
#else
#endif
#define HWA_CGA_M1_CLK_SEL	0xe0000000
#define HWA_CGA_M1_CLK_SHIFT	29
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifdef CONFIG_FSL_ESDHC
#define HWA_CGA_M2_CLK_SEL	0x00000007
#define HWA_CGA_M2_CLK_SHIFT	0
#if defined(CONFIG_TARGET_LS1046ARDB) || defined(CONFIG_TARGET_LS1043ARDB)
#if defined(CONFIG_TARGET_LS1046ARDB)
#endif
#if defined(CONFIG_TARGET_LS1046ARDB)
#endif
#endif
#endif
#if defined(CONFIG_FSL_IFC)
#endif
#ifdef CONFIG_SYS_DPAA_QBMAN
#endif
#ifdef CONFIG_SYS_DPAA_QBMAN
#endif
#ifdef CONFIG_FSL_ESDHC
#if defined(CONFIG_FSL_ESDHC_USE_PERIPHERAL_CLK)
#if defined(CONFIG_TARGET_LS1046ARDB)
#endif
#if defined(CONFIG_TARGET_LS1043ARDB)
#endif
#if defined(CONFIG_TARGET_LS1012ARDB)
#endif
#else
#endif
#endif
#ifdef CONFIG_FSL_LPUART
#endif
#ifdef CONFIG_FSL_LPUART
#endif
