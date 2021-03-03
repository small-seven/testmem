#include <common.h>
#include <vsprintf.h>
#include <asm/mmu.h>
#include <asm/immap_85xx.h>
#include <asm/processor.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#include <asm/io.h>
#include <asm/fsl_law.h>
#ifndef CONFIG_SYS_DDR_RAW_TIMING
#define CONFIG_SYS_DRAM_SIZE	1024
#if defined(CONFIG_SYS_RAMBOOT)
#endif
#else /* CONFIG_SYS_DDR_RAW_TIMING */
#endif /* CONFIG_SYS_DDR_RAW_TIMING */
