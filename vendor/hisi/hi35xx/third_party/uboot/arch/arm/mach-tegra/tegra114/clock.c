#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/sysctr.h>
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/clk_rst.h>
#include <asm/arch-tegra/timer.h>
#include <div64.h>
#include <fdtdec.h>
#define CLK(x) CLOCK_ID_ ## x
#define TYPE(name, type) type
#define NONE(name) (-1)
#define OFFSET(name, value) PERIPHC_ ## name
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif /* CONFIG_IS_ENABLED(OF_CONTROL) */
