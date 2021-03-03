#include <common.h>
#include <env.h>
#include <malloc.h>
#include <dm.h>
#include <dm/platform_data/serial_sh.h>
#include <env_internal.h>
#include <asm/processor.h>
#include <asm/mach-types.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/arch/rmobile.h>
#include <asm/arch/rcar-mstp.h>
#include <asm/arch/sh_sdhi.h>
#include <netdev.h>
#include <miiphy.h>
#include <i2c.h>
#include "qos.h"
#define CLK2MHZ(clk)	(clk / 1000 / 1000)
#define TMU0_MSTP125	BIT(25)
#define SD1CKCR		0xE6150078
#define SD2CKCR		0xE615026C
#define SD_97500KHZ	0x7
#define ETHERNET_PHY_RESET	176	/* GPIO 5 22 */
#define PHY_CONTROL1		0x1E
#define PHY_LED_MODE		0xC000
#define PHY_LED_MODE_ACK	0x4000
