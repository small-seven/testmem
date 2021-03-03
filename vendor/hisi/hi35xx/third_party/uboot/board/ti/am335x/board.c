#include <common.h>
#include <dm.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <spl.h>
#include <serial.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/clk_synthesizer.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mem.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <asm/omap_common.h>
#include <asm/omap_sec_common.h>
#include <asm/omap_mmc.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <power/tps65217.h>
#include <power/tps65910.h>
#include <env_internal.h>
#include <watchdog.h>
#include "../common/board_detect.h"
#include "board.h"
#define GPIO_TO_PIN(bank, gpio)		(32 * (bank) + (gpio))
#define GPIO_DDR_VTT_EN		GPIO_TO_PIN(0, 7)
#define ICE_GPIO_DDR_VTT_EN	GPIO_TO_PIN(0, 18)
#define GPIO_PR1_MII_CTRL	GPIO_TO_PIN(3, 4)
#define GPIO_MUX_MII_CTRL	GPIO_TO_PIN(3, 10)
#define GPIO_FET_SWITCH_CTRL	GPIO_TO_PIN(0, 7)
#define GPIO_PHY_RESET		GPIO_TO_PIN(2, 5)
#define GPIO_ETH0_MODE		GPIO_TO_PIN(0, 11)
#define GPIO_ETH1_MODE		GPIO_TO_PIN(1, 26)
#define GPIO0_RISINGDETECT	(AM33XX_GPIO0_BASE + OMAP_GPIO_RISINGDETECT)
#define GPIO1_RISINGDETECT	(AM33XX_GPIO1_BASE + OMAP_GPIO_RISINGDETECT)
#define GPIO0_IRQSTATUS1	(AM33XX_GPIO0_BASE + OMAP_GPIO_IRQSTATUS1)
#define GPIO1_IRQSTATUS1	(AM33XX_GPIO1_BASE + OMAP_GPIO_IRQSTATUS1)
#define GPIO0_IRQSTATUSRAW	(AM33XX_GPIO0_BASE + 0x024)
#define GPIO1_IRQSTATUSRAW	(AM33XX_GPIO1_BASE + 0x024)
#ifdef CONFIG_TI_I2C_BOARD_DETECT
#ifndef CONFIG_DM_I2C
#endif
#endif
#ifndef CONFIG_DM_SERIAL
#endif
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#ifdef CONFIG_SPL_OS_BOOT
#ifdef CONFIG_SPL_SERIAL_SUPPORT
#endif
#ifdef CONFIG_SPL_ENV_SUPPORT
#endif
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#endif
#if CONFIG_CONS_INDEX == 1
#elif CONFIG_CONS_INDEX == 2
#elif CONFIG_CONS_INDEX == 3
#elif CONFIG_CONS_INDEX == 4
#elif CONFIG_CONS_INDEX == 5
#elif CONFIG_CONS_INDEX == 6
#endif
#endif
#if defined(CONFIG_CLOCK_SYNTHESIZER) && (!defined(CONFIG_SPL_BUILD) || \
#define REQUEST_AND_SET_GPIO(N)	request_and_set_gpio(N, #N, 1);
#define REQUEST_AND_CLR_GPIO(N)	request_and_set_gpio(N, #N, 0);
#endif
#if defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_OF_CONTROL) && \
#define MAX_CPSW_SLAVES	2
#endif
#if defined(CONFIG_HW_WATCHDOG)
#endif
#if defined(CONFIG_NOR) || defined(CONFIG_MTD_RAW_NAND)
#endif
#if defined(CONFIG_CLOCK_SYNTHESIZER) && (!defined(CONFIG_SPL_BUILD) || \
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#if !defined(CONFIG_SPL_BUILD)
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#if !defined(CONFIG_SPL_BUILD)
#endif
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
#ifdef CONFIG_TI_SECURE_DEVICE
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
