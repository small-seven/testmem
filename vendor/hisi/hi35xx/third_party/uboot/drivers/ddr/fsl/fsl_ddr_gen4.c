#include <common.h>
#include <env.h>
#include <asm/io.h>
#include <fsl_ddr_sdram.h>
#include <asm/processor.h>
#include <fsl_immap.h>
#include <fsl_ddr.h>
#include <fsl_errata.h>
#if defined(CONFIG_FSL_LSCH2) || defined(CONFIG_FSL_LSCH3) || \
#include <asm/arch/clock.h>
#endif
#define CTLR_INTLV_MASK	0x20000000
#if defined(CONFIG_SYS_FSL_ERRATUM_A008511) | \
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 4)
#error Invalid setting for CONFIG_CHIP_SELECTS_PER_CTRL
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A008511
#endif
#ifdef CONFIG_FSL_DDR_BIST
#endif
#ifdef CONFIG_FSL_DDR_BIST
#endif
#if defined(CONFIG_SYS_FSL_DDR2_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#endif
#if defined(CONFIG_SYS_FSL_DDR3_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 2)
#endif
#if defined(CONFIG_SYS_FSL_DDR4_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 3)
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009663
#else
#endif
#ifndef CONFIG_SYS_FSL_DDR_EMU
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009803
#else
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A008511
#endif
#if defined(CONFIG_SYS_FSL_ERRATUM_A009803) || \
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009801
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A010165
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#if defined(CONFIG_SYS_FSL_ERRATUM_A008511) || \
#ifdef CONFIG_SYS_FSL_ERRATUM_A008511
#endif /* CONFIG_SYS_FSL_ERRATUM_A008511 */
#ifdef CONFIG_SYS_FSL_ERRATUM_A009803
#endif
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 1)
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 3)
#endif
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009663
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_FSL_DDR_BIST
#define BIST_PATTERN1	0xFFFFFFFF
#define BIST_PATTERN2	0x0
#define BIST_CR		0x80010000
#define BIST_CR_EN	0x80000000
#define BIST_CR_STAT	0x00000001
#endif
