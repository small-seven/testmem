#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/dram.h>
#include <asm/arch/timer.h>
#include <asm/arch/sys_proto.h>
#define CPU_CFG_CHIP_VER(n) ((n) << 6)
#define CPU_CFG_CHIP_VER_MASK CPU_CFG_CHIP_VER(0x3)
#define CPU_CFG_CHIP_REV_A 0x0
#define CPU_CFG_CHIP_REV_C1 0x1
#define CPU_CFG_CHIP_REV_C2 0x2
#define CPU_CFG_CHIP_REV_B 0x3
#ifdef CONFIG_MACH_SUN4I
#endif
#ifdef CONFIG_MACH_SUN7I
#else
#endif
#ifdef CONFIG_MACH_SUN5I
#endif
#ifdef CONFIG_MACH_SUN4I
#endif
#ifdef CONFIG_MACH_SUN7I
#endif
#ifdef CONFIG_OLD_SUNXI_KERNEL_COMPAT
#endif
#if defined(CONFIG_MACH_SUN4I) || defined(CONFIG_MACH_SUN7I)
#endif
#ifdef CONFIG_MACH_SUN7I
#endif
#if defined(CONFIG_MACH_SUN5I) || defined(CONFIG_MACH_SUN7I)
#else
#endif
#if defined(CONFIG_MACH_SUN5I) || defined(CONFIG_MACH_SUN7I)
#else
#endif
#if defined(CONFIG_MACH_SUN5I) || defined(CONFIG_MACH_SUN7I)
#endif
#ifdef CONFIG_MACH_SUN4I
#endif
#ifndef CONFIG_MACH_SUN7I
#endif
#ifdef CONFIG_MACH_SUN7I
#endif
#ifdef CONFIG_MACH_SUN4I
#endif
#if (defined(CONFIG_MACH_SUN5I) || defined(CONFIG_MACH_SUN7I))
#endif
#ifdef CONFIG_MACH_SUN7I
#endif
#if defined(CONFIG_MACH_SUN4I) || defined(CONFIG_MACH_SUN5I)
#else
#endif
