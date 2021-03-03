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
#include <asm/arch/mem.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <power/tps65217.h>
#include <watchdog.h>
#include "board.h"
#ifdef CONFIG_SPL_BUILD
#define OSC	(V_OSCK/1000000)
#ifdef CONFIG_SPL_OS_BOOT
#endif
#endif
#if defined(CONFIG_HW_WATCHDOG)
#endif
#if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) || \
#endif
