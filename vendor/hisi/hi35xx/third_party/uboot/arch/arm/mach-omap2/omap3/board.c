#include <common.h>
#include <dm.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mem.h>
#include <asm/cache.h>
#include <asm/armv7.h>
#include <asm/gpio.h>
#include <asm/omap_common.h>
#include <linux/compiler.h>
#ifndef CONFIG_SYS_L2CACHE_OFF
#endif
#ifdef CONFIG_DM_GPIO
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#else
#endif
#ifndef CONFIG_SYS_L2CACHE_OFF
#endif
#ifdef CONFIG_USB_EHCI_OMAP
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#if defined(CONFIG_NAND_OMAP_GPMC) & !defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_NAND_OMAP_GPMC & !CONFIG_SPL_BUILD */
#ifdef CONFIG_DISPLAY_BOARDINFO
#endif	/* CONFIG_DISPLAY_BOARDINFO */
#ifndef CONFIG_SYS_L2CACHE_OFF
#endif /* !CONFIG_SYS_L2CACHE_OFF */
