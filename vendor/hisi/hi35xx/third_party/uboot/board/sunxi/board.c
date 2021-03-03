#include <common.h>
#include <dm.h>
#include <env.h>
#include <mmc.h>
#include <axp_pmic.h>
#include <generic-phy.h>
#include <phy-sun4i-usb.h>
#include <asm/arch/clock.h>
#include <asm/arch/cpu.h>
#include <asm/arch/display.h>
#include <asm/arch/dram.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mmc.h>
#include <asm/arch/spl.h>
#include <u-boot/crc.h>
#ifndef CONFIG_ARM64
#include <asm/armv7.h>
#endif
#include <asm/gpio.h>
#include <asm/io.h>
#include <u-boot/crc.h>
#include <env_internal.h>
#include <linux/libfdt.h>
#include <nand.h>
#include <net.h>
#include <spl.h>
#include <sy8106a.h>
#include <asm/setup.h>
#if defined CONFIG_VIDEO_LCD_PANEL_I2C && !(defined CONFIG_SPL_BUILD)
#else
#endif
#ifdef CONFIG_I2C0_ENABLE
#if defined(CONFIG_MACH_SUN4I) || \
#elif defined(CONFIG_MACH_SUN6I)
#elif defined(CONFIG_MACH_SUN8I)
#elif defined(CONFIG_MACH_SUN50I)
#endif
#endif
#ifdef CONFIG_I2C1_ENABLE
#if defined(CONFIG_MACH_SUN4I) || \
#elif defined(CONFIG_MACH_SUN5I)
#elif defined(CONFIG_MACH_SUN6I)
#elif defined(CONFIG_MACH_SUN8I)
#elif defined(CONFIG_MACH_SUN50I)
#endif
#endif
#ifdef CONFIG_I2C2_ENABLE
#if defined(CONFIG_MACH_SUN4I) || \
#elif defined(CONFIG_MACH_SUN5I)
#elif defined(CONFIG_MACH_SUN6I)
#elif defined(CONFIG_MACH_SUN8I)
#elif defined(CONFIG_MACH_SUN50I)
#endif
#endif
#ifdef CONFIG_I2C3_ENABLE
#if defined(CONFIG_MACH_SUN6I)
#elif defined(CONFIG_MACH_SUN7I) || \
#endif
#endif
#ifdef CONFIG_I2C4_ENABLE
#if defined(CONFIG_MACH_SUN7I) || \
#endif
#endif
#ifdef CONFIG_R_I2C_ENABLE
#ifdef CONFIG_MACH_SUN50I
#else
#endif
#endif
#if defined(CONFIG_ENV_IS_IN_MMC) && defined(CONFIG_ENV_IS_IN_FAT)
#endif
#ifdef CONFIG_DM_MMC
#endif
#ifndef CONFIG_ARM64
#ifdef CONFIG_NON_SECURE
#else
#endif
#endif /* !CONFIG_ARM64 */
#ifdef CONFIG_SATAPWR
#endif
#ifdef CONFIG_MACPWR
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_MMC
#if CONFIG_MMC_SUNXI_SLOT_EXTRA != -1
#endif
#endif	/* CONFIG_DM_MMC */
#define INVALID_SPL_HEADER ((void *)~0UL)
#if defined(CONFIG_NAND_SUNXI)
#if defined CONFIG_MACH_SUN4I || defined CONFIG_MACH_SUN7I
#endif
#ifdef CONFIG_MACH_SUN7I
#endif
#if defined CONFIG_MACH_SUN6I || defined CONFIG_MACH_SUN8I || \
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#endif
#ifdef CONFIG_MMC
#if defined(CONFIG_MACH_SUN4I) || defined(CONFIG_MACH_SUN7I) || \
#elif defined(CONFIG_MACH_SUN5I)
#elif defined(CONFIG_MACH_SUN6I)
#elif defined(CONFIG_MACH_SUN8I)
#endif
#if defined(CONFIG_MACH_SUN4I) || defined(CONFIG_MACH_SUN7I)
#elif defined(CONFIG_MACH_SUN5I)
#elif defined(CONFIG_MACH_SUN6I)
#elif defined(CONFIG_MACH_SUN8I_R40)
#elif defined(CONFIG_MACH_SUN8I) || defined(CONFIG_MACH_SUN50I)
#elif defined(CONFIG_MACH_SUN50I_H6)
#elif defined(CONFIG_MACH_SUN9I)
#endif
#if defined(CONFIG_MACH_SUN4I) || defined(CONFIG_MACH_SUN7I) || \
#elif defined(CONFIG_MACH_SUN6I)
#endif
#if CONFIG_MMC_SUNXI_SLOT_EXTRA != -1
#endif
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_SY8106A_POWER
#endif
#if defined CONFIG_AXP152_POWER || defined CONFIG_AXP209_POWER || \
#if defined CONFIG_AXP221_POWER || defined CONFIG_AXP809_POWER || \
#endif
#if !defined(CONFIG_AXP209_POWER) && !defined(CONFIG_AXP818_POWER)
#endif
#if defined CONFIG_AXP221_POWER || defined CONFIG_AXP809_POWER || \
#endif
#if defined CONFIG_AXP221_POWER || defined CONFIG_AXP809_POWER || \
#endif
#if !defined(CONFIG_AXP152_POWER)
#endif
#ifdef CONFIG_AXP209_POWER
#endif
#if defined(CONFIG_AXP221_POWER) || defined(CONFIG_AXP809_POWER) || \
#if !defined CONFIG_AXP809_POWER
#endif
#endif
#ifdef CONFIG_AXP818_POWER
#endif
#if defined CONFIG_AXP809_POWER || defined CONFIG_AXP818_POWER
#endif
#endif
#endif
#ifdef CONFIG_USB_GADGET
#endif
#ifdef CONFIG_SERIAL_TAG
#endif
#if !defined(CONFIG_MACH_SUN4I) && !defined(CONFIG_MACH_SUN5I) && \
#endif
#ifdef CONFIG_USB_ETHER
#endif
#ifdef CONFIG_VIDEO_DT_SIMPLEFB
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#ifdef CONFIG_DEFAULT_DEVICE_TREE
#else
#endif
#ifdef CONFIG_PINE64_DT_SELECTION
#endif
#endif
