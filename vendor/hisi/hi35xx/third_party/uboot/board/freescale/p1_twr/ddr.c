#include <common.h>
#include <vsprintf.h>
#include <asm/mmu.h>
#include <asm/immap_85xx.h>
#include <asm/processor.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#include <asm/io.h>
#include <asm/fsl_law.h>
#if CONFIG_CHIP_SELECTS_PER_CTRL > 1
#endif
