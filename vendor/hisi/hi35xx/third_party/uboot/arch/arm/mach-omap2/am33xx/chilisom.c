#include <common.h>
#include <asm/arch/clock.h>
#include <asm/arch/clk_synthesizer.h>
#include <asm/arch/cpu.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/mem.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/emif.h>
#include <asm/io.h>
#include <errno.h>
#include <i2c.h>
#include <power/tps65217.h>
#include <spl.h>
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#define OSC	(V_OSCK/1000000)
#endif /* CONFIG_SKIP_LOWLEVEL_INIT */
