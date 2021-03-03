#include <clk.h>
#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include "mmc_private.h"
#include <linux/libfdt.h>
#include <malloc.h>
#include <sdhci.h>
#include <zynqmp_tap_delay.h>
#if defined(CONFIG_ARCH_ZYNQMP)
#define MMC_HS200_BUS_SPEED	5
#define SDHCI_TUNING_LOOP_COUNT	40
#endif
#if defined(CONFIG_ARCH_ZYNQMP)
#endif
#ifdef CONFIG_ZYNQ_HISPD_BROKEN
#endif
#if defined(CONFIG_ARCH_ZYNQMP)
#endif
