#include <common.h>
#include <env.h>
#include <errno.h>
#include <serial.h>
#include <spl.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <watchdog.h>
#include <asm/mach-types.h>
#include "../common/factoryset.h"
#ifdef CONFIG_SPL_BUILD
#endif /* #ifdef CONFIG_SPL_BUILD */
#ifndef CONFIG_SPL_BUILD
#if defined(CONFIG_HW_WATCHDOG)
#endif /* defined(CONFIG_HW_WATCHDOG) */
#ifdef CONFIG_MACH_TYPE
#endif
#ifdef CONFIG_FACTORYSET
#endif
#ifdef CONFIG_NAND_CS_INIT
#endif
#ifdef CONFIG_VIDEO
#endif
#endif /* #ifndef CONFIG_SPL_BUILD */
#define OSC	(V_OSCK/1000000)
#ifndef CONFIG_SPL_BUILD
#define MAX_NR_LEDS	10
#define MAX_PIN_NUMBER	128
#define STARTUP	0
#if defined(BOARD_DFU_BUTTON_GPIO)
#endif
#endif /* !CONFIG_SPL_BUILD */
