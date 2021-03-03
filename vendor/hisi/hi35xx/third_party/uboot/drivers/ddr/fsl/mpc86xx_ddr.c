#include <common.h>
#include <asm/io.h>
#include <fsl_ddr_sdram.h>
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 4)
#error Invalid setting for CONFIG_CHIP_SELECTS_PER_CTRL
#endif
