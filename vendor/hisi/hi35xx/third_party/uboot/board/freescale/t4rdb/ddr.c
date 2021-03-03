#include <common.h>
#include <i2c.h>
#include <hwconfig.h>
#include <asm/mmu.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#include <asm/fsl_law.h>
#include "ddr.h"
#if defined(CONFIG_SPL_BUILD) || !defined(CONFIG_RAMBOOT_PBL)
#else
#endif
