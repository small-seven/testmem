#include <common.h>
#include <fsl_ddr_sdram.h>
#include <fsl_errata.h>
#include <fsl_ddr.h>
#include <fsl_immap.h>
#include <asm/io.h>
#if defined(CONFIG_FSL_LSCH2) || defined(CONFIG_FSL_LSCH3) || \
#include <asm/arch/clock.h>
#endif
#if defined(CONFIG_SYS_FSL_DDR1)
#elif defined(CONFIG_SYS_FSL_DDR2)
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#if !defined(CONFIG_SYS_FSL_DDR1)
#if CONFIG_DIMM_SLOTS_PER_CTLR == 1
#endif
#if CONFIG_DIMM_SLOTS_PER_CTLR == 2
#ifdef CONFIG_FSL_DDR_FIRST_SLOT_QUAD_CAPABLE
#endif
#endif
#if defined(CONFIG_SYS_FSL_DDR4) || defined(CONFIG_SYS_FSL_DDR3)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#elif defined(CONFIG_SYS_FSL_DDR3)
#else /* CONFIG_SYS_FSL_DDR2 */
#endif
#endif	/* !defined(CONFIG_SYS_FSL_DDR1) */
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR1)
#elif defined(CONFIG_SYS_FSL_DDR2)
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR3)
#endif
#if defined(CONFIG_SYS_FSL_DDR2)
#elif defined(CONFIG_SYS_FSL_DDR3)
#endif
#ifdef CONFIG_SYS_FSL_DDR3
#endif
#if defined(CONFIG_SYS_FSL_DDR1)
#elif defined(CONFIG_SYS_FSL_DDR2)
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR2)
#elif defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#elif defined(CONFIG_SYS_FSL_DDR3)
#else
#endif
#ifndef CONFIG_SYS_FSL_DDR4
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#else
#endif
#if (CONFIG_SYS_FSL_DDR_VER >= FSL_DDR_VER_4_7)
#endif
#if defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifndef CONFIG_SYS_FSL_DDR4
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#elif defined(CONFIG_SYS_FSL_DDR3)
#else /* for DDR2 and DDR1 */
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#if CONFIG_CHIP_SELECTS_PER_CTRL == 4
#endif
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#elif defined(CONFIG_SYS_FSL_DDR3)
#else /* !CONFIG_SYS_FSL_DDR3 */
#if defined(CONFIG_SYS_FSL_DDR1)
#elif defined(CONFIG_SYS_FSL_DDR2)
#endif
#if defined(CONFIG_SYS_FSL_DDR1)
#elif defined(CONFIG_SYS_FSL_DDR2)
#endif
#endif
#ifdef CONFIG_MEM_INIT_VALUE
#else
#endif
#if defined(CONFIG_ARCH_MPC8541) || defined(CONFIG_ARCH_MPC8555)
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#elif defined(CONFIG_SYS_FSL_DDR3)
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif	/* CONFIG_SYS_FSL_DDR4 */
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009942
#endif
#if (defined(CONFIG_SYS_FSL_ERRATUM_A008378) && \
#if defined(CONFIG_SYS_FSL_DDR2_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#endif
#if defined(CONFIG_SYS_FSL_DDR3_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 2)
#endif
#if defined(CONFIG_SYS_FSL_DDR4_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 3)
#endif
#endif
#if !defined(CONFIG_SYS_FSL_DDR1)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#ifdef CONFIG_SYS_FSL_DDR_EMU
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A004508
#endif
#if defined(CONFIG_SYS_FSL_ERRATUM_A008378) && defined(CONFIG_SYS_FSL_DDRC_GEN4)
#define IS_ACC_ECC_EN(v) ((v) & 0x4)
#define IS_DBI(v) ((((v) >> 12) & 0x3) == 0x2)
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009942
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009942
#endif
