#include <common.h>
#include <env.h>
#include <serial.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <i2c.h>
#include <phy.h>
#include <cpsw.h>
#include "board.h"
#if defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_SPL_OS_BOOT
#endif
#define OSC	(V_OSCK/1000000)
#endif /* if CONFIG_SPL_BUILD */
#ifdef CONFIG_DRIVER_TI_CPSW
#endif /* if CONFIG_DRIVER_TI_CPSW */
