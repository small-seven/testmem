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
#ifdef CONFIG_BOARD_LATE_INIT
#endif
#if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) || \
#endif
#if ((defined(CONFIG_SPL_ETH_SUPPORT) || defined(CONFIG_SPL_USB_ETHER)) \
#if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) || \
#ifdef CONFIG_DRIVER_TI_CPSW
#endif
#define AR8051_PHY_DEBUG_ADDR_REG	0x1d
#define AR8051_PHY_DEBUG_DATA_REG	0x1e
#define AR8051_DEBUG_RGMII_CLK_DLY_REG	0x5
#define AR8051_RGMII_TX_CLK_DLY		0x100
#endif
#if defined(CONFIG_USB_ETHER) && \
#endif
#endif
