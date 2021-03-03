#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <mmc.h>
#include <clk.h>
#include <reset.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/cpu.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mmc.h>
#include <asm-generic/gpio.h>
#ifdef CONFIG_DM_MMC
#endif
#ifdef CONFIG_DM_MMC
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#ifdef SUNXI_MMC3_BASE
#endif
#endif
#if defined(CONFIG_MACH_SUN50I) || defined(CONFIG_MACH_SUN50I_H6)
#endif
#ifdef CONFIG_MACH_SUN9I
#elif defined(CONFIG_MACH_SUN50I_H6)
#else
#endif
#ifdef CONFIG_MACH_SUN9I
#else
#endif
#ifdef CONFIG_MMC_SUNXI_HAS_NEW_MODE
#ifdef CONFIG_MMC_SUNXI_HAS_MODE_SWITCH
#endif
#endif
#if defined(CONFIG_MACH_SUN50I) || defined(CONFIG_MACH_SUN50I_H6)
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#if defined(CONFIG_MACH_SUN50I) || defined(CONFIG_MACH_SUN8I) || defined(CONFIG_MACH_SUN50I_H6)
#endif
#if !defined(CONFIG_MACH_SUN50I_H6)
#ifdef CONFIG_SUNXI_GEN_SUN6I
#endif
#if defined(CONFIG_MACH_SUN9I)
#endif
#else /* CONFIG_MACH_SUN50I_H6 */
#endif
#else
#endif
