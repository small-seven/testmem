#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clock.h>
#include <axp_pmic.h>
#include <errno.h>
#ifdef CONFIG_MACH_SUN6I
#endif
#ifdef CONFIG_MACH_SUN8I
#endif
#ifdef CONFIG_DISPLAY_CPUINFO
#ifdef CONFIG_MACH_SUN4I
#elif defined CONFIG_MACH_SUN5I
#elif defined CONFIG_MACH_SUN6I
#elif defined CONFIG_MACH_SUN7I
#elif defined CONFIG_MACH_SUN8I_A23
#elif defined CONFIG_MACH_SUN8I_A33
#elif defined CONFIG_MACH_SUN8I_A83T
#elif defined CONFIG_MACH_SUN8I_H3
#elif defined CONFIG_MACH_SUN8I_R40
#elif defined CONFIG_MACH_SUN8I_V3S
#elif defined CONFIG_MACH_SUN9I
#elif defined CONFIG_MACH_SUN50I
#elif defined CONFIG_MACH_SUN50I_H5
#elif defined CONFIG_MACH_SUN50I_H6
#else
#warning Please update cpu_info.c with correct CPU information
#endif
#endif
#ifdef CONFIG_MACH_SUN8I_H3
#define SIDC_PRCTL 0x40
#define SIDC_RDKEY 0x60
#define SIDC_OP_LOCK 0xAC
#endif
#ifdef CONFIG_AXP221_POWER
#elif defined CONFIG_MACH_SUN8I_H3
#elif defined SUNXI_SID_BASE
#else
#endif
