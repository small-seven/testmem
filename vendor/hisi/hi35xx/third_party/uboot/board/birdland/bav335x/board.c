#include <common.h>
#include <env.h>
#include <errno.h>
#include <init.h>
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
#include <asm/arch/mem.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <power/tps65217.h>
#include <power/tps65910.h>
#include <env_internal.h>
#include <watchdog.h>
#include "board.h"
#define GPIO_DDR_VTT_EN		7
#if (CONFIG_BAV_VERSION == 1)
#elif (CONFIG_BAV_VERSION == 2)
#endif
#if (NOT_DEFINED == 2)
#error "SHOULD NEVER DISPLAY THIS"
#endif
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#ifdef CONFIG_SPL_OS_BOOT
#ifdef CONFIG_SPL_ENV_SUPPORT
#endif
#endif
#define OSC	(V_OSCK/1000000)
#if CONFIG_CONS_INDEX == 1
#elif CONFIG_CONS_INDEX == 2
#elif CONFIG_CONS_INDEX == 3
#elif CONFIG_CONS_INDEX == 4
#elif CONFIG_CONS_INDEX == 5
#elif CONFIG_CONS_INDEX == 6
#endif
#endif
#if defined(CONFIG_HW_WATCHDOG)
#endif
#if defined(CONFIG_NOR) || defined(CONFIG_MTD_RAW_NAND)
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#endif
#if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) || \
#endif
#if ((defined(CONFIG_SPL_ETH_SUPPORT) || defined(CONFIG_SPL_USB_ETHER)) &&\
#if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) || \
#ifdef CONFIG_DRIVER_TI_CPSW
#endif
#endif
#endif
