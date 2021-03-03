#include <common.h>
#include <i2c.h>
#include <hwconfig.h>
#include <asm/mmu.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#include <asm/fsl_law.h>
#include <asm/mpc85xx_gpio.h>
#if defined(CONFIG_SYS_FSL_DDR4)
#elif defined(CONFIG_SYS_FSL_DDR3)
#else
#error DDR type not defined
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_FORCE_DDR_DATA_BUS_WIDTH_32
#endif
#if defined(CONFIG_DEEP_SLEEP)
#endif
#if defined(CONFIG_SPL_BUILD) || !defined(CONFIG_RAMBOOT_PBL)
#else
#endif
#if defined(CONFIG_DEEP_SLEEP) && !defined(CONFIG_SPL_BUILD)
#endif
