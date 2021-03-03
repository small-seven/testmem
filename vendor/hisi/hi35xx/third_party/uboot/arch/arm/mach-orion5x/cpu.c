#include <common.h>
#include <cpu_func.h>
#include <netdev.h>
#include <asm/cache.h>
#include <asm/io.h>
#include <u-boot/md5.h>
#include <asm/arch/cpu.h>
#define BUFLEN	16
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#ifdef CONFIG_ARCH_CPU_INIT
#ifdef CONFIG_SPL_BUILD
#endif
#endif /* CONFIG_ARCH_CPU_INIT */
#if defined(CONFIG_ARCH_MISC_INIT)
#endif /* CONFIG_ARCH_MISC_INIT */
#ifdef CONFIG_MVGBE
#endif
