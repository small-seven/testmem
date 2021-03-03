#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <ns16550.h>
#include <spl.h>
#include <asm/io.h>
#if IS_ENABLED(CONFIG_TEGRA_CLKRST)
#include <asm/arch/clock.h>
#endif
#if IS_ENABLED(CONFIG_TEGRA_PINCTRL)
#include <asm/arch/funcmux.h>
#endif
#if IS_ENABLED(CONFIG_TEGRA_MC)
#include <asm/arch/mc.h>
#endif
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/board.h>
#include <asm/arch-tegra/cboot.h>
#include <asm/arch-tegra/pmc.h>
#include <asm/arch-tegra/sys_proto.h>
#include <asm/arch-tegra/warmboot.h>
#ifndef CONFIG_SPL_BUILD
#endif
#if defined(CONFIG_TEGRA_SUPPORT_NON_SECURE)
#if !defined(CONFIG_TEGRA124)
#error tegra_cpu_is_non_secure has only been validated on Tegra124
#endif
#endif
#if IS_ENABLED(CONFIG_TEGRA_MC)
#if defined(CONFIG_TEGRA20)
#else
#ifndef CONFIG_PHYS_64BIT
#endif
#ifndef CONFIG_ARM64
#endif
#endif
#if defined(CONFIG_TEGRA30) || defined(CONFIG_TEGRA114)
#endif
#endif
#if IS_ENABLED(CONFIG_TEGRA_MC)
#endif
#if IS_ENABLED(CONFIG_TEGRA_PINCTRL)
#if defined(CONFIG_TEGRA20)
#endif
#elif defined(CONFIG_TEGRA30)
#elif defined(CONFIG_TEGRA114)
#elif defined(CONFIG_TEGRA124)
#else	/* Tegra210 */
#endif
#endif
#if IS_ENABLED(CONFIG_TEGRA_PINCTRL)
#ifdef CONFIG_TEGRA_ENABLE_UARTA
#endif
#ifdef CONFIG_TEGRA_ENABLE_UARTB
#endif
#ifdef CONFIG_TEGRA_ENABLE_UARTC
#endif
#ifdef CONFIG_TEGRA_ENABLE_UARTD
#endif
#ifdef CONFIG_TEGRA_ENABLE_UARTE
#endif
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF) && !defined(CONFIG_ARM64)
#endif
