#include <common.h>
#include <i2c.h>
#include <hwconfig.h>
#include <asm/mmu.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#include <asm/fsl_law.h>
#include <asm/mpc85xx_gpio.h>
#ifdef CONFIG_FORCE_DDR_DATA_BUS_WIDTH_32
#endif
#ifdef CONFIG_TARGET_T1023RDB
#elif defined(CONFIG_TARGET_T1024RDB)
#endif
#ifdef CONFIG_SYS_DDR_RAW_TIMING
#endif
#if defined(CONFIG_DEEP_SLEEP)
#endif
#if defined(CONFIG_SPL_BUILD) || !defined(CONFIG_RAMBOOT_PBL)
#ifndef CONFIG_SYS_DDR_RAW_TIMING
#endif
#else
#endif
#if defined(CONFIG_DEEP_SLEEP) && !defined(CONFIG_SPL_BUILD)
#endif
