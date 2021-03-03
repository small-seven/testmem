#include <common.h>
#include <vsprintf.h>
#include <asm/mmu.h>
#include <asm/immap_85xx.h>
#include <asm/processor.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#include <asm/io.h>
#include <asm/fsl_law.h>
#ifdef CONFIG_SYS_DDR_RAW_TIMING
#if defined(CONFIG_UCP1020) || defined(CONFIG_UCP1020T1)
#else
#error Missing raw timing data for this board
#endif
#endif /* CONFIG_SYS_DDR_RAW_TIMING */
#ifdef CONFIG_SYS_DDR_CS0_BNDS
#if CONFIG_CHIP_SELECTS_PER_CTRL > 1
#endif
#endif
