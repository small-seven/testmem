#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <env.h>
#include <linux/ctype.h>
#ifdef CONFIG_ARCH_CPU_INIT
#endif
#ifndef CONFIG_RCAR_GEN3
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#endif
#ifdef CONFIG_DISPLAY_CPUINFO
#ifndef CONFIG_RZA1
#ifdef CONFIG_ARCH_MISC_INIT
#endif
#else
#endif
#endif /* CONFIG_DISPLAY_CPUINFO */
