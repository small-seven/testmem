#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <asm/arch/hardware.h>
#include <asm/arch/pxa.h>
#include <asm/arch/regs-mmc.h>
#include <asm/arch/regs-uart.h>
#include <asm/io.h>
#include <dm/platdata.h>
#include <dm/platform_data/serial_pxa.h>
#include <netdev.h>
#include <serial.h>
#include <usb.h>
#include <asm/mach-types.h>
#include "../common/tdx-common.h"
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef	CONFIG_CMD_USB
#endif
#ifdef CONFIG_DRIVER_DM9000
#endif
#ifdef	CONFIG_CMD_MMC
#endif
