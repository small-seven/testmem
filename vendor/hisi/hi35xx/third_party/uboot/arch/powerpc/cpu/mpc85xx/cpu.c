#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <irq_func.h>
#include <vsprintf.h>
#include <watchdog.h>
#include <command.h>
#include <fsl_esdhc.h>
#include <asm/cache.h>
#include <asm/io.h>
#include <asm/mmu.h>
#include <fsl_ifc.h>
#include <asm/fsl_law.h>
#include <asm/fsl_lbc.h>
#include <post.h>
#include <asm/processor.h>
#include <fsl_ddr_sdram.h>
#include <asm/ppc.h>
#if defined(CONFIG_DDR_CLK_FREQ) || defined(CONFIG_FSL_CORENET)
#endif
#ifdef CONFIG_FSL_CORENET
#ifdef CONFIG_SYS_FSL_QORIQ_CHASSIS2
#else
#endif /* CONFIG_SYS_FSL_QORIQ_CHASSIS2 */
#else	/* CONFIG_FSL_CORENET */
#ifdef CONFIG_DDR_CLK_FREQ
#else
#endif /* CONFIG_DDR_CLK_FREQ */
#endif /* CONFIG_FSL_CORENET */
#ifdef CONFIG_HETROGENOUS_CLUSTERS
#endif
#if defined(CONFIG_SYS_FSL_QORIQ_CHASSIS2) && defined(CONFIG_E6500)
#endif
#ifndef CONFIG_MP
#endif
#ifdef CONFIG_SYS_FSL_SINGLE_SOURCE_CLK
#endif
#ifdef CONFIG_HETROGENOUS_CLUSTERS
#endif
#ifdef CONFIG_FSL_CORENET
#else
#endif
#if defined(CONFIG_FSL_LBC)
#endif
#if defined(CONFIG_FSL_IFC)
#endif
#ifdef CONFIG_CPM2
#endif
#ifdef CONFIG_QE
#endif
#if defined(CONFIG_SYS_CPRI)
#endif
#if defined(CONFIG_SYS_MAPLE)
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifdef CONFIG_SYS_DPAA_QBMAN
#endif
#ifdef CONFIG_SYS_DPAA_PME
#endif
#ifdef CONFIG_FSL_CORENET
#endif
#if defined(CONFIG_ARCH_MPC8540) || defined(CONFIG_ARCH_MPC8541) || \
#else
#endif
#ifndef CONFIG_SYS_FSL_TBCLK_DIV
#define CONFIG_SYS_FSL_TBCLK_DIV 8
#endif
#if defined(CONFIG_WATCHDOG)
#define WATCHDOG_MASK (TCR_WP(63) | TCR_WRC(3) | TCR_WIE)
#endif	/* CONFIG_WATCHDOG */
#ifdef CONFIG_FSL_ESDHC
#else
#endif
#if defined(CONFIG_FSL_LBC)
#endif
#ifdef CONFIG_FSL_IFC
#endif
#ifndef CONFIG_FSL_CORENET
#if (defined(CONFIG_SYS_RAMBOOT) || defined(CONFIG_SPL)) && \
#if defined(CONFIG_SPD_EEPROM) || defined(CONFIG_DDR_SPD) || \
#else
#endif
#else /* CONFIG_SYS_RAMBOOT */
#if defined(CONFIG_SYS_FSL_ERRATUM_DDR_MSYNC_IN)
#endif
#if	defined(CONFIG_SPD_EEPROM)	|| \
#else
#endif
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#if defined(CONFIG_FSL_LBC)
#endif
#endif /* CONFIG_SYS_RAMBOOT */
#endif
#if CONFIG_POST & CONFIG_SYS_POST_MEMORY
#if defined(CONFIG_SYS_FSL_DDR2_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#endif
#if defined(CONFIG_SYS_FSL_DDR3_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 2)
#endif
#if defined(CONFIG_SYS_FSL_DDR4_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 3)
#endif
#if !defined(CONFIG_PHYS_64BIT) || \
#else
#endif
#if !defined(CONFIG_PHYS_64BIT) || \
#endif
#endif
