#include <common.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <spl.h>
#include <i2c.h>
#include <watchdog.h>
#include <debug_uart.h>
#include <dm/ofnode.h>
#include <power/pmic.h>
#include <power/regulator.h>
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
#include "board.h"
#define I2C_ADDR_NODE_ID	0x50
#define I2C_REG_NODE_ID_BASE	0xfa
#define NODE_ID_BYTE_COUNT	6
#define I2C_ADDR_LEDS		0x60
#define I2C_REG_RUN_LED		0x06
#define RUN_LED_OFF		0x0
#define RUN_LED_RED		0x1
#define RUN_LED_GREEN		(0x1 << 2)
#define VDD_MPU_REGULATOR	"regulator@2"
#define VDD_CORE_REGULATOR	"regulator@3"
#define DEFAULT_CORE_VOLTAGE	1137500
#define CONFIG_SYS_RTC_SCRATCH0 0x60
#define BOOT_DEVICE_SAVE_REGISTER (RTC_BASE + CONFIG_SYS_RTC_SCRATCH0)
#ifdef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#define OSC	(V_OSCK / 1000000)
#endif /* CONFIG_SKIP_LOWLEVEL_INIT */
#ifdef CONFIG_DEBUG_UART
#endif
#ifdef CONFIG_HW_WATCHDOG
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#endif
