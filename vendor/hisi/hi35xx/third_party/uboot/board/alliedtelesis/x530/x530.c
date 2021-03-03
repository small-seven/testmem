#include <common.h>
#include <command.h>
#include <dm.h>
#include <env.h>
#include <i2c.h>
#include <wdt.h>
#include <asm/gpio.h>
#include <linux/mbus.h>
#include <linux/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "../common/gpio_hog.h"
#include "../drivers/ddr/marvell/a38x/ddr3_init.h"
#include <../serdes/a38x/high_speed_env_spec.h>
#define MVEBU_DEV_BUS_BASE		(MVEBU_REGISTER(0x10400))
#define CONFIG_NVS_LOCATION		0xf4800000
#define CONFIG_NVS_SIZE			(512 << 10)
#ifdef CONFIG_WATCHDOG
#endif
#ifdef CONFIG_MISC_INIT_R
#ifdef MTDPARTS_MTDOOPS
#endif
#endif
#ifdef CONFIG_DISPLAY_BOARDINFO
#endif
