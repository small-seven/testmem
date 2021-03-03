#include <common.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/sysmap.h>
#include <asm/kona-common/clk.h>
#include "clk-core.h"
#define CLOCK_1K		1000
#define CLOCK_1M		(CLOCK_1K * 1000)
#define DECLARE_REF_CLK(clk_name, clk_parent, clk_rate, clk_div) \
#define MKSTR(x) {&x, #x}
#ifdef CONFIG_BCM_SF2_ETH
#endif
#ifdef CONFIG_BCM_SF2_ETH
#endif
