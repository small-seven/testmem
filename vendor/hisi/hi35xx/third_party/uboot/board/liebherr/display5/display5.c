#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/sys_proto.h>
#include <env.h>
#include <errno.h>
#include <asm/gpio.h>
#include <malloc.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <miiphy.h>
#include <netdev.h>
#include <i2c.h>
#include <dm.h>
#include <dm/platform_data/serial_mxc.h>
#include <dm/platdata.h>
#include "common.h"
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef CONFIG_CMD_BMODE
#else
#endif
