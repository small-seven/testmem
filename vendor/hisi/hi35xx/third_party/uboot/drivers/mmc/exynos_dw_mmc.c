#include <common.h>
#include <dwmmc.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <malloc.h>
#include <errno.h>
#include <asm/arch/dwmmc.h>
#include <asm/arch/clk.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/power.h>
#include <asm/gpio.h>
#define	DWMMC_MAX_CH_NUM		4
#define	DWMMC_MAX_FREQ			52000000
#define	DWMMC_MIN_FREQ			400000
#define	DWMMC_MMC0_SDR_TIMING_VAL	0x03030001
#define	DWMMC_MMC2_SDR_TIMING_VAL	0x03020001
#ifdef CONFIG_DM_MMC
#include <dm.h>
#endif
#ifdef CONFIG_DM_MMC
#endif
#ifdef CONFIG_DM_MMC
#else
#endif
#ifdef CONFIG_EXYNOS5420
#endif
#ifndef CONFIG_DM_MMC
#endif
#ifdef CONFIG_DM_MMC
#endif
