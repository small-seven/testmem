#include <common.h>
#include <asm/io.h>
#include <fsl_ddr_sdram.h>
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 4)
#error Invalid setting for CONFIG_CHIP_SELECTS_PER_CTRL
#endif
#if defined(CONFIG_ARCH_MPC8555) || defined(CONFIG_ARCH_MPC8541)
#endif
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif	/* CONFIG_DDR_ECC  && ! CONFIG_ECC_INIT_VIA_DDRCONTROLLER */
