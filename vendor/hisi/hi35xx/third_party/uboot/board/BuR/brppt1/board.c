#include <common.h>
#include <bootcount.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <spl.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mem.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <power/tps65217.h>
#include "../common/bur_common.h"
#include <watchdog.h>
#define	REPSWITCH	(0+20)	/* GPIO0_20 */
#if defined(CONFIG_SPL_BUILD)
#define OSC	(V_OSCK/1000000)
#endif /* CONFIG_SPL_BUILD */
#if defined(CONFIG_HW_WATCHDOG)
#endif
#ifdef CONFIG_MTD_RAW_NAND
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#endif /* CONFIG_BOARD_LATE_INIT */
