#include <common.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/clock.h>
#include <asm/arch/emc.h>
#include <asm/arch/gp_padctrl.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/sdram_param.h>
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/apb_misc.h>
#include <asm/arch-tegra/clk_rst.h>
#include <asm/arch-tegra/pmc.h>
#include <asm/arch-tegra/fuse.h>
#include <asm/arch-tegra/warmboot.h>
#ifndef CONFIG_TEGRA_CLOCK_SCALING
#error "You must enable CONFIG_TEGRA_CLOCK_SCALING to use CONFIG_TEGRA_LP0"
#endif
#define SDRAM_PARAMS_BASE	(NV_PA_BASE_SRAM + 0x188)
