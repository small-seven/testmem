#include <common.h>
#include <asm/io.h>
#include <fsl_ddr_sdram.h>
#include <asm/processor.h>
#include <fsl_immap.h>
#include <fsl_ddr.h>
#include <asm/arch/clock.h>
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 4)
#error Invalid setting for CONFIG_CHIP_SELECTS_PER_CTRL
#endif
#if defined(CONFIG_SYS_FSL_DDR2_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#endif
#if defined(CONFIG_SYS_FSL_DDR3_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 2)
#endif
#if defined(CONFIG_SYS_FSL_DDR4_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 3)
#endif
#ifndef CONFIG_SYS_FSL_DDR_EMU
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
