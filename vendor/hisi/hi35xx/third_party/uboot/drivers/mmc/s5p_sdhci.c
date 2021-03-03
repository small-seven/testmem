#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <sdhci.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <asm/gpio.h>
#include <asm/arch/mmc.h>
#include <asm/arch/clk.h>
#include <errno.h>
#include <asm/arch/pinmux.h>
#ifdef CONFIG_DM_MMC
#endif
#ifndef CONFIG_BLK
#else
#endif
#ifdef CONFIG_DM_MMC
#endif /* CONFIG_DM_MMC */
