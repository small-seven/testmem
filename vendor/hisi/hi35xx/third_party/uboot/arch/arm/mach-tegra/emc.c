#include <common.h>
#include "emc.h"
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/emc.h>
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/clk_rst.h>
#include <asm/arch-tegra/pmu.h>
#include <asm/arch-tegra/sys_proto.h>
#define EMC_SDRAM_RATE_T20	(333000 * 2 * 1000)
#define EMC_SDRAM_RATE_T25	(380000 * 2 * 1000)
