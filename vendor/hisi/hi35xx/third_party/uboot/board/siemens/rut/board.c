#include <common.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <spi.h>
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
#include <video.h>
#include <watchdog.h>
#include "board.h"
#include "../common/factoryset.h"
#include "../../../drivers/video/da8xx-fb.h"
#ifdef CONFIG_SPL_BUILD
#define GPIO_TO_PIN(bank, gpio)		(32 * (bank) + (gpio))
#define ETH_PHY_RESET_GPIO		GPIO_TO_PIN(2, 18)
#define MAXTOUCH_RESET_GPIO		GPIO_TO_PIN(3, 18)
#define DISPLAY_RESET_GPIO		GPIO_TO_PIN(3, 19)
#define REQUEST_AND_PULSE_RESET(N) \
#endif /* if def CONFIG_SPL_BUILD */
#if defined(CONFIG_DRIVER_TI_CPSW)
#if defined(CONFIG_DRIVER_TI_CPSW) || \
#ifndef CONFIG_SPL_BUILD
#endif
#endif /* #if defined(CONFIG_DRIVER_TI_CPSW) */
#endif /* #if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) */
#if defined(CONFIG_HW_WATCHDOG)
#endif /* defined(CONFIG_HW_WATCHDOG) */
#if defined(CONFIG_VIDEO) && !defined(CONFIG_SPL_BUILD)
#define PLL_GET_M(v) ((v >> 8) & 0x7ff)
#define PLL_GET_N(v) (v & 0x7f)
#if defined(DISPL_PLL_SPREAD_SPECTRUM)
#endif
#if defined(DISPL_PLL_SPREAD_SPECTRUM)
#endif
#endif /* ifdef CONFIG_VIDEO */
#ifdef CONFIG_BOARD_LATE_INIT
#endif
#include "../common/board.c"
