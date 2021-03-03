#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/clk.h>
#define CLK_M	0
#define CLK_D	1
#define CLK_P	2
#ifndef CONFIG_SYS_CLK_FREQ_C100
#define CONFIG_SYS_CLK_FREQ_C100	12000000
#endif
#ifndef CONFIG_SYS_CLK_FREQ_C110
#define CONFIG_SYS_CLK_FREQ_C110	24000000
#endif
