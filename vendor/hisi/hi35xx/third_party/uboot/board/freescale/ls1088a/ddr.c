#include <common.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#include <asm/arch/soc.h>
#include <asm/arch/clock.h>
#include "ddr.h"
#if defined(CONFIG_VID) && (!defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD))
#endif
#if defined(CONFIG_VID) && (!defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD))
#endif
#ifdef CONFIG_TFABOOT
#else
#if defined(CONFIG_SPL) && !defined(CONFIG_SPL_BUILD)
#else
#endif
#endif /* CONFIG_TFABOOT */
