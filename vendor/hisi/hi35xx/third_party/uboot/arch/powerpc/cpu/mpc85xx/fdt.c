#include <common.h>
#include <env.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/processor.h>
#include <linux/ctype.h>
#include <asm/io.h>
#include <asm/fsl_fdt.h>
#include <asm/fsl_portals.h>
#include <fsl_qbman.h>
#include <hwconfig.h>
#ifdef CONFIG_FSL_ESDHC
#include <fsl_esdhc.h>
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#include <fsl_fman.h>
#endif
#ifdef CONFIG_MP
#include "mp.h"
#if defined(T1040_TDM_QUIRK_CCSR_BASE)
#endif
#ifdef CONFIG_FSL_CORENET
#else
#endif
#if defined(T1040_TDM_QUIRK_CCSR_BASE)
#define	CONFIG_MEM_HOLE_16M	0x1000000
#endif
#ifndef CONFIG_MPC8xxx_DISABLE_BPTR
#endif
#ifdef CONFIG_DEEP_SLEEP
#ifdef CONFIG_SPL_MMC_BOOT
#elif defined(CONFIG_SPL_SPI_BOOT)
#endif
#endif
#endif
#ifdef CONFIG_SYS_FSL_CPC
#ifdef CONFIG_SYS_CACHE_STASHING
#endif
#else
#define ft_fixup_l3cache(x, y)
#endif
#if defined(CONFIG_L2_CACHE) || \
#endif
#if defined(CONFIG_L2_CACHE)
#elif defined(CONFIG_BACKSIDE_L2_CACHE) || \
#ifdef	CONFIG_BACKSIDE_L2_CACHE
#else
#endif
#ifdef CONFIG_SYS_CACHE_STASHING
#if defined(CONFIG_SYS_FSL_QORIQ_CHASSIS2) && defined(CONFIG_E6500)
#else
#endif
#endif
#else
#define ft_fixup_l2cache(x)
#endif
#ifdef CONFIG_SYS_CACHE_STASHING
#endif
#if defined(CONFIG_SYS_DPAA_FMAN) || defined(CONFIG_SYS_DPAA_PME)
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#if (CONFIG_SYS_NUM_FMAN == 2)
#endif
#endif
#ifdef CONFIG_SYS_DPAA_QBMAN
#endif
#ifdef CONFIG_SYS_DPAA_PME
#endif
#else
#define ft_fixup_dpaa_clks(x)
#endif
#ifdef CONFIG_QE
#endif
#if defined(CONFIG_ARCH_P4080)
#else
#define fdt_fixup_usb(x)
#endif
#if defined(CONFIG_ARCH_T2080) || defined(CONFIG_ARCH_T4240) || \
#define CONFIG_SYS_ELO3_DMA3 (0xffe000000 + 0x102300)
#if defined(CONFIG_ARCH_T2080)
#elif defined(CONFIG_ARCH_T4240) || defined(CONFIG_ARCH_T4160)
#endif
#else
#define fdt_fixup_dma3(x)
#endif
#if defined(CONFIG_ARCH_T1040)
#else
#define fdt_fixup_l2_switch(x)
#endif
#if CONFIG_SYS_FSL_SEC_COMPAT >= 4
#endif
#ifndef CONFIG_FSL_TBCLK_EXTRA_DIV
#define CONFIG_FSL_TBCLK_EXTRA_DIV 1
#endif
#ifdef CONFIG_QE
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifdef CONFIG_SYS_NS16550
#endif
#ifdef CONFIG_CPM2
#endif
#ifdef CONFIG_FSL_CORENET
#else
#endif
#ifdef CONFIG_MP
#endif
#if defined(CONFIG_FSL_ESDHC)
#endif
#if defined(CONFIG_SYS_BMAN_MEM_PHYS)
#endif
#if defined(CONFIG_SYS_QMAN_MEM_PHYS)
#endif
#ifdef CONFIG_SYS_SRIO
#endif
#define CCSR_VIRT_TO_PHYS(x) \
#ifdef CONFIG_SYS_NS16550_COM1
#endif
#ifdef CONFIG_SYS_NS16550_COM2
#endif
#ifdef CONFIG_SYS_LBC_ADDR
#endif
