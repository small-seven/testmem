#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <wdt.h>
#include <watchdog.h>
#include <asm/arch/imx-regs.h>
#ifdef CONFIG_FSL_LSCH2
#include <asm/arch/immap_lsch2.h>
#endif
#include <fsl_wdog.h>
#if !defined(CONFIG_IMX_WATCHDOG) || \
#endif
#if defined(CONFIG_IMX_WATCHDOG)
#ifndef CONFIG_WATCHDOG_RESET_DISABLE
#endif /* CONFIG_WATCHDOG_RESET_DISABLE*/
#ifndef CONFIG_WATCHDOG_TIMEOUT_MSECS
#define CONFIG_WATCHDOG_TIMEOUT_MSECS 128000
#endif
#ifdef CONFIG_FSL_LSCH2
#else
#endif /* CONFIG_FSL_LSCH2*/
#if !CONFIG_IS_ENABLED(WDT)
#else
#endif
#endif
