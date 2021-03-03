#include <common.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <fsl_ddr_sdram.h>
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 4)
#error Invalid setting for CONFIG_CHIP_SELECTS_PER_CTRL
#endif
#if defined(CONFIG_SYS_FSL_ERRATUM_NMG_DDR120) && defined(CONFIG_MPC85xx)
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_NMG_DDR120
#endif
