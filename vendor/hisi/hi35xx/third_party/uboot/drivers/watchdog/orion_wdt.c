#include <common.h>
#include <dm.h>
#include <clk.h>
#include <wdt.h>
#include <linux/kernel.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#define RSTOUT_ENABLE_BIT		BIT(8)
#define RSTOUT_MASK_BIT			BIT(10)
#define WDT_ENABLE_BIT			BIT(8)
#define TIMER_CTRL			0x0000
#define TIMER_A370_STATUS		0x04
#define WDT_AXP_FIXED_ENABLE_BIT	BIT(10)
#define WDT_A370_EXPIRED		BIT(31)
