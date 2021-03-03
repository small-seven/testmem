#include <common.h>
#include <env.h>
#include <net.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <mach/jz4780.h>
#include <mach/jz4780_dram.h>
#include <mach/jz4780_gpio.h>
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_MTD_RAW_NAND
#else
#endif
#ifdef CONFIG_JTAG
#endif
#ifndef CONFIG_JTAG
#endif
#ifdef CONFIG_DRIVER_DM9000
#endif /* CONFIG_DRIVER_DM9000 */
#endif
#ifdef CONFIG_SPL_BUILD
#if defined(CONFIG_SPL_MMC_SUPPORT)
#endif
#ifdef SDRAM_DISABLE_DLL
#else
#endif
#ifdef SDRAM_DISABLE_DLL
#else
#endif
#if (CONFIG_SYS_MHZ != 1200)
#error No DDR configuration for CPU speed
#endif
#endif
