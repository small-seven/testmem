#include <common.h>
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
#include <dm.h>
#include <power/tps65217.h>
#include "../common/bur_common.h"
#include "../common/br_resetc.h"
#define ESC_KEY					(0 + 19)
#define LCD_PWR					(0 + 5)
#define	RSTCTRL_FORCE_PWR_NEN			0x04
#define	RSTCTRL_CAN_STB				0x40
#if defined(CONFIG_SPL_BUILD)
#define OSC	(V_OSCK / 1000000)
#endif /* CONFIG_SPL_BUILD */
#ifdef CONFIG_BOARD_LATE_INIT
#endif /* CONFIG_BOARD_LATE_INIT */
