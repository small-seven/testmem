#include <common.h>
#include <cpu_func.h>
#include <asm/system.h>
#include <asm/cache.h>
#include <linux/compiler.h>
#include <asm/armv7_mpu.h>
#if !(CONFIG_IS_ENABLED(SYS_ICACHE_OFF) && CONFIG_IS_ENABLED(SYS_DCACHE_OFF))
#ifdef CONFIG_SYS_ARM_MMU
#ifdef CONFIG_ARMV7_LPAE
#else
#endif
#ifdef CONFIG_ARMV7_LPAE
#else
#endif
#ifdef CONFIG_ARMV7_LPAE
#else
#endif
#if defined(CONFIG_SYS_ARM_CACHE_WRITETHROUGH)
#elif defined(CONFIG_SYS_ARM_CACHE_WRITEALLOC)
#else
#endif
#if defined(CONFIG_ARMV7_LPAE) && __LINUX_ARM_ARCH__ != 4
#if defined(CONFIG_SYS_ARM_CACHE_WRITETHROUGH)
#elif defined(CONFIG_SYS_ARM_CACHE_WRITEALLOC)
#else
#endif
#elif defined(CONFIG_CPU_V7A)
#if defined(CONFIG_SYS_ARM_CACHE_WRITETHROUGH)
#elif defined(CONFIG_SYS_ARM_CACHE_WRITEALLOC)
#else
#endif
#else
#endif
#endif /* CONFIG_SYS_ARM_MMU */
#ifdef CONFIG_SYS_ARM_MMU
#elif defined(CONFIG_SYS_ARM_MPU)
#endif
#ifdef CONFIG_SYS_ARM_MMU
#endif
#ifdef CONFIG_SYS_ARM_MMU
#elif defined(CONFIG_SYS_ARM_MPU)
#endif
#endif
#if CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
#else
#endif
#if CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#else
#endif
