#include <common.h>
#include <clk.h>
#include <dm.h>
#include <malloc.h>
#include <sdhci.h>
#include <asm/arch/clk.h>
#define ATMEL_SDHC_MIN_FREQ	400000
#define ATMEL_SDHC_GCK_RATE	240000000
#ifndef CONFIG_DM_MMC
#else
#endif
