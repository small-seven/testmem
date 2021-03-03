#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <irq_func.h>
#include <netdev.h>
#include <status_led.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <asm/arch/ep93xx.h>
#define CLKSET2_VAL	(23 << SYSCON_CLKSET_PLL_X2IPD_SHIFT |	\
#define SMC_BCR6_VALUE	(2 << SMC_BCR_IDCY_SHIFT | 5 << SMC_BCR_WST1_SHIFT | \
#ifndef CONFIG_EP93XX_NO_FLASH_CFG
#else
#define flash_cfg()
#endif
#ifdef USE_920T_MMU
#endif
