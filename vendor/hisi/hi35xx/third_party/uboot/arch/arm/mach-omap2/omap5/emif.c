#include <common.h>
#include <asm/emif.h>
#include <asm/arch/sys_proto.h>
#include <asm/utils.h>
#ifndef CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS
#define print_timing_reg(reg) debug(#reg" - 0x%08x\n", (reg))
#endif
#ifdef CONFIG_SYS_DEFAULT_LPDDR2_TIMINGS
#endif /* CONFIG_SYS_DEFAULT_LPDDR2_TIMINGS */
