#include <common.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#ifdef CONFIG_FSL_DEEP_SLEEP
#include <fsl_sleep.h>
#endif
#include <asm/arch/clock.h>
#include "ddr.h"
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_TFABOOT
#else
#if defined(CONFIG_SPL) && !defined(CONFIG_SPL_BUILD)
#else
#endif
#ifdef CONFIG_FSL_DEEP_SLEEP
#endif
#endif
