#include <common.h>
#include <spl.h>
#include <asm/arch/cpu.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <power/tps65910.h>
#include <jffs2/load_kernel.h>
#include <mtd_node.h>
#include <fdt_support.h>
#include "board.h"
#ifdef CONFIG_SPL_BUILD
#define DDR_CLK_MHZ		400 /* DDR_DPLL_MULT value */
#define OSC	(V_OSCK / 1000000)
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#endif
