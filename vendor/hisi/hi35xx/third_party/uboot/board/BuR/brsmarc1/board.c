#include <common.h>
#include <errno.h>
#include <init.h>
#include <spl.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mem.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/emif.h>
#include <power/tps65217.h>
#include "../common/bur_common.h"
#include "../common/br_resetc.h"
#define PER_RESET		(2 * 32 + 0)
#if defined(CONFIG_SPL_BUILD)
#define OSC	(V_OSCK / 1000000)
#endif /* CONFIG_SPL_BUILD */
#if !defined(CONFIG_SPL_BUILD)
#if defined(CONFIG_BOARD_LATE_INIT)
#endif /* CONFIG_BOARD_LATE_INIT */
#endif /* !CONFIG_SPL_BUILD */
