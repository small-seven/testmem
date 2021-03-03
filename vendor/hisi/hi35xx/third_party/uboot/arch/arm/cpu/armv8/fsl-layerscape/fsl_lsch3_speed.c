#include <common.h>
#include <cpu_func.h>
#include <linux/compiler.h>
#include <fsl_ifc.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <asm/arch-fsl-layerscape/immap_lsch3.h>
#include <asm/arch/clock.h>
#include <asm/arch/soc.h>
#include "cpu.h"
#ifndef CONFIG_SYS_FSL_NUM_CC_PLLS
#define CONFIG_SYS_FSL_NUM_CC_PLLS	6
#endif
#if defined(CONFIG_ARCH_LS1028A) || defined(CONFIG_ARCH_LS1088A)
#endif
#ifdef CONFIG_DDR_CLK_FREQ
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
#else
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
#endif
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
#if defined(CONFIG_FSL_IFC)
#endif
#if defined(CONFIG_ARCH_LS1028A) || defined(CONFIG_ARCH_LS1088A)
#define HWA_CGA_M2_CLK_SEL      0x00380000
#define HWA_CGA_M2_CLK_SHIFT    19
#endif
#if defined(CONFIG_ARCH_LX2160A) || defined(CONFIG_ARCH_LS2080A)
#endif
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
#if defined(CONFIG_FSL_ESDHC)
#if defined(CONFIG_FSL_ESDHC_USE_PERIPHERAL_CLK)
#if defined(CONFIG_ARCH_LS1028A) || defined(CONFIG_ARCH_LX2160A)
#endif
#if defined(CONFIG_ARCH_LS2080A) || defined(CONFIG_ARCH_LS1088A)
#endif
#else
#endif
#endif /* defined(CONFIG_FSL_ESDHC) */
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
