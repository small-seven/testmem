#include <common.h>
#include <asm/io.h>
#include <fsl_ddr_sdram.h>
#include <asm/processor.h>
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 4)
#error Invalid setting for CONFIG_CHIP_SELECTS_PER_CTRL
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR111_DDR134
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR_A003
#endif
#if defined(CONFIG_SYS_FSL_DDR2_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#endif
#if defined(CONFIG_SYS_FSL_DDR3_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 2)
#endif
#if defined(CONFIG_SYS_FSL_DDR4_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 3)
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR111_DDR134
#endif
#ifndef CONFIG_SYS_FSL_DDR_EMU
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR_A003474
#endif /* CONFIG_SYS_FSL_ERRATUM_DDR_A003474 */
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR_A003
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#endif
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#endif
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#endif
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#endif
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR_115
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR111_DDR134
#endif	/* part 1 of the workaound */
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR111_DDR134
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_DDR111_DDR134
#if CONFIG_CHIP_SELECTS_PER_CTRL > 2
#endif
#endif /* CONFIG_SYS_FSL_ERRATUM_DDR111_DDR134 */
#ifdef CONFIG_DEEP_SLEEP
#endif
