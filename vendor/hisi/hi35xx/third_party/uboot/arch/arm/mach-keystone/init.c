#include <common.h>
#include <cpu_func.h>
#include <ns16550.h>
#include <asm/io.h>
#include <asm/arch/msmc.h>
#include <asm/arch/clock.h>
#include <asm/arch/hardware.h>
#include <asm/arch/psc_defs.h>
#define MAX_PCI_PORTS		2
#define DEVCFG_MODE_MASK		(BIT(2) | BIT(1))
#define DEVCFG_MODE_SHIFT		1
#ifdef CONFIG_SOC_K2L
#endif
#if defined(CONFIG_SOC_K2E) || defined(CONFIG_SOC_K2L)
#endif
#ifdef CONFIG_SOC_K2L
#endif
#ifndef CONFIG_DM_SERIAL
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#ifdef CONFIG_SOC_K2G
#endif
#endif
