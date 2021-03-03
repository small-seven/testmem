#include "common.h"
#include <clk.h>
#include <errno.h>
#include <malloc.h>
#include <mmc.h>
#include <asm/io.h>
#include <asm-generic/gpio.h>
#include "arm_pl180_mmci.h"
#ifdef CONFIG_DM_MMC
#include <dm.h>
#define MMC_CLOCK_MAX	48000000
#define MMC_CLOCK_MIN	400000
#endif
#ifndef CONFIG_DM_MMC
#endif
#ifdef CONFIG_DM_MMC
#endif
