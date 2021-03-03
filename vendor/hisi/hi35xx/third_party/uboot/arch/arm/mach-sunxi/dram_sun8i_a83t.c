#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/dram.h>
#include <asm/arch/prcm.h>
#define DRAM_CLK_MUL 2
#define DRAM_CLK_DIV 1
#if defined(CONFIG_MACH_SUN8I_A83T)
#if (CONFIG_DRAM_TYPE == 3) || (CONFIG_DRAM_TYPE == 7)
#else
#error Unsupported DRAM type, Please set DRAM type (3:DDR3, 7:LPDDR3)
#endif
#endif
