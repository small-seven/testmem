#include <common.h>
#include <cpu_func.h>
#include <mmc.h>
#include <i2c.h>
#include <serial.h>
#include <spl.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/arch/spl.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/timer.h>
#include <asm/arch/tzpc.h>
#include <asm/arch/mmc.h>
#include <linux/compiler.h>
#ifdef CONFIG_ARM64
#include <asm/armv8/mmu.h>
#endif
#if CONFIG_CONS_INDEX == 1 && defined(CONFIG_UART0_PORT_F)
#if defined(CONFIG_MACH_SUN4I) || \
#endif
#if defined(CONFIG_MACH_SUN8I) && !defined(CONFIG_MACH_SUN8I_R40)
#else
#endif
#elif CONFIG_CONS_INDEX == 1 && (defined(CONFIG_MACH_SUN4I) || \
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUN5I)
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUN6I)
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUN8I_A33)
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUNXI_H3_H5)
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUN50I)
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUN50I_H6)
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUN8I_A83T)
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUN8I_V3S)
#elif CONFIG_CONS_INDEX == 1 && defined(CONFIG_MACH_SUN9I)
#elif CONFIG_CONS_INDEX == 2 && defined(CONFIG_MACH_SUN5I)
#elif CONFIG_CONS_INDEX == 3 && defined(CONFIG_MACH_SUN8I)
#elif CONFIG_CONS_INDEX == 5 && defined(CONFIG_MACH_SUN8I)
#else
#error Unsupported console port number. Please fix pin mux settings in board.c
#endif
#ifdef CONFIG_MACH_SUN50I_H6
#endif
#if defined(CONFIG_SPL_BOARD_LOAD_IMAGE) && defined(CONFIG_SPL_BUILD)
#endif
#if defined CONFIG_MACH_SUN6I
#elif defined CONFIG_MACH_SUN8I
#if defined CONFIG_MACH_SUN8I_A23
#elif defined CONFIG_MACH_SUN8I_A33
#endif
#endif
#if !defined(CONFIG_ARM_CORTEX_CPU_IS_UP) && !defined(CONFIG_ARM64)
#endif
#if defined CONFIG_MACH_SUN6I || defined CONFIG_MACH_SUN8I_H3
#endif
#ifndef CONFIG_DM_I2C
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_SPL_I2C_SUPPORT
#endif
#endif
#if defined(CONFIG_SUNXI_GEN_SUN4I) || defined(CONFIG_MACH_SUN8I_R40)
#elif defined(CONFIG_SUNXI_GEN_SUN6I) || defined(CONFIG_MACH_SUN50I_H6)
#if defined(CONFIG_MACH_SUN50I_H6)
#else
#endif
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF) && !defined(CONFIG_ARM64)
#endif
