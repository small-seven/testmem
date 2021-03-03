#include <common.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#include <asm/arch/soc.h>
#include <asm/arch/clock.h>
#include "ddr.h"
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_SYS_DDR_RAW_TIMING
#endif
