#include <common.h>
#include <malloc.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <linux/compat.h>
#include <linux/err.h>
#include <asm/arch/dsim.h>
#include <asm/arch/mipi_dsim.h>
#include <asm/arch/power.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clk.h>
#include "exynos_mipi_dsi_lowlevel.h"
#include "exynos_mipi_dsi_common.h"
#define master_to_driver(a)	(a->dsim_lcd_drv)
#define master_to_device(a)	(a->dsim_lcd_dev)
