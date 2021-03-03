#include <config.h>
#include <common.h>
#include <asm/arch/cpu.h>
#include <asm/arch/cpucfg.h>
#include <asm/arch/prcm.h>
#include <asm/armv7.h>
#include <asm/gic.h>
#include <asm/io.h>
#include <asm/psci.h>
#include <asm/secure.h>
#include <asm/system.h>
#include <linux/bitops.h>
#define __irq		__attribute__ ((interrupt ("IRQ")))
#define	GICD_BASE	(SUNXI_GIC400_BASE + GIC_DIST_OFFSET)
#define	GICC_BASE	(SUNXI_GIC400_BASE + GIC_CPU_OFFSET_A15)
#define SUN8I_R40_PWROFF			(0x110)
#define SUN8I_R40_PWR_CLAMP(cpu)		(0x120 + (cpu) * 0x4)
#define SUN8I_R40_SRAMC_SOFT_ENTRY_REG0		(0xbc)
#define ONE_MS (COUNTER_FREQUENCY / 1000)
#if defined(CONFIG_MACH_SUN6I) || defined(CONFIG_MACH_SUN7I) || \
#endif
#if defined(CONFIG_MACH_SUN6I) || defined(CONFIG_MACH_SUN7I) || \
#endif
#ifdef CONFIG_MACH_SUN8I_R40
#else
#endif
#ifdef CONFIG_MACH_SUN7I
#elif defined CONFIG_MACH_SUN8I_R40
#else /* ! CONFIG_MACH_SUN7I && ! CONFIG_MACH_SUN8I_R40 */
#endif /* CONFIG_MACH_SUN7I */
