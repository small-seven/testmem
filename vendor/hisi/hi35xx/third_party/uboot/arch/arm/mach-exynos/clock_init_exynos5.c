#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/clock.h>
#include <asm/arch/spl.h>
#include <asm/arch/dwmmc.h>
#include "clock_init.h"
#include "common_setup.h"
#include "exynos5_setup.h"
#define FSYS1_MMC0_DIV_MASK	0xff0f
#define FSYS1_MMC0_DIV_VAL	0x0701
#ifdef CONFIG_EXYNOS5420
#else
#endif
#ifdef CONFIG_EXYNOS5420
#else
#endif
