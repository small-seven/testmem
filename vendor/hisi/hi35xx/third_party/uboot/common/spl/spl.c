#include <common.h>
#include <bloblist.h>
#include <binman_sym.h>
#include <dm.h>
#include <handoff.h>
#include <irq_func.h>
#include <serial.h>
#include <spl.h>
#include <asm/u-boot.h>
#include <nand.h>
#include <fat.h>
#include <u-boot/crc.h>
#include <version.h>
#include <image.h>
#include <malloc.h>
#include <mapmem.h>
#include <dm/root.h>
#include <linux/compiler.h>
#include <fdt_support.h>
#include <bootcount.h>
#include <wdt.h>
#ifndef CONFIG_SYS_UBOOT_START
#define CONFIG_SYS_UBOOT_START	CONFIG_SYS_TEXT_BASE
#endif
#ifndef CONFIG_SYS_MONITOR_LEN
#define CONFIG_SYS_MONITOR_LEN	(200 * 1024)
#endif
#if defined(CONFIG_SPL_OS_BOOT) || CONFIG_IS_ENABLED(HANDOFF)
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif
#if defined(CONFIG_SPL_OF_LIBFDT) && defined(CONFIG_SYS_SPL_ARGS_ADDR)
#endif
#ifdef CONFIG_SPL_LOAD_FIT_FULL
#ifdef CONFIG_SPL_FIT_SIGNATURE
#endif
#ifdef CONFIG_SPL_FIT_SIGNATURE
#endif
#ifdef CONFIG_SPL_FIT_SIGNATURE
#endif
#endif
#ifdef CONFIG_SPL_LOAD_FIT_FULL
#endif
#ifdef CONFIG_SPL_LEGACY_IMAGE_SUPPORT
#ifdef CONFIG_SPL_LEGACY_IMAGE_CRC_CHECK
#endif
#ifdef CONFIG_SPL_LEGACY_IMAGE_CRC_CHECK
#endif
#else
#endif
#ifdef CONFIG_SPL_PANIC_ON_RAW_IMAGE
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif
#ifdef CONFIG_SPL_RAW_IMAGE_SUPPORT
#else
#endif
	typedef void __noreturn (*image_entry_noargs_t)(void);

	image_entry_noargs_t image_entry =
		(image_entry_noargs_t)spl_image->entry_point;

	debug("image entry point: 0x%lx\n", spl_image->entry_point);
	image_entry();
}
#if CONFIG_IS_ENABLED(HANDOFF)
#else
#endif /* HANDOFF */
#if CONFIG_VAL(SYS_MALLOC_F_LEN)
#ifdef CONFIG_MALLOC_F_ADDR
#endif
#endif
#ifdef CONFIG_BOOTSTAGE_STASH
#endif /* CONFIG_BOOTSTAGE_STASH */
#if CONFIG_IS_ENABLED(LOG)
#endif
#ifndef BOOT_DEVICE_NONE
#define BOOT_DEVICE_NONE 0xdeadbeef
#endif
#ifdef CONFIG_SPL_LEGACY_IMAGE_CRC_CHECK
#endif
#if defined(CONFIG_SPL_SERIAL_SUPPORT) && defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#if defined(CONFIG_SPL_FRAMEWORK_BOARD_INIT_F)
#endif
#if defined(CONFIG_SYS_SPL_MALLOC_START)
#endif
#if !defined(CONFIG_PPC) && !defined(CONFIG_ARCH_MX6)
#endif
#if CONFIG_IS_ENABLED(BOARD_INIT)
#endif
#if defined(CONFIG_SPL_WATCHDOG_SUPPORT) && CONFIG_IS_ENABLED(WDT)
#endif
#ifdef CONFIG_SYS_SPL_ARGS_ADDR
#endif
#ifdef CONFIG_CPU_V7M
#endif
#if CONFIG_IS_ENABLED(ATF)
#endif
#if CONFIG_IS_ENABLED(OPTEE)
#endif
#if CONFIG_IS_ENABLED(OPENSBI)
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif
#if CONFIG_VAL(SYS_MALLOC_F_LEN) && !defined(CONFIG_SYS_SPL_MALLOC_SIZE)
#endif
#ifdef CONFIG_BOOTSTAGE_STASH
#endif
#ifdef CONFIG_SPL_SERIAL_SUPPORT
#if CONFIG_IS_ENABLED(BANNER_PRINT)
#endif
#ifdef CONFIG_SPL_DISPLAY_PRINT
#endif
#endif
#if CONFIG_IS_ENABLED(SYS_REPORT_STACK_F_USAGE)
#endif
#ifdef CONFIG_SPL_STACK_R
#if defined(CONFIG_SPL_SYS_MALLOC_SIMPLE) && CONFIG_VAL(SYS_MALLOC_F_LEN)
#endif
#if CONFIG_IS_ENABLED(DM)
#endif
#if !defined(CONFIG_ARM) && !defined(CONFIG_RISCV)
#endif
#else
#endif
#if defined(CONFIG_BOOTCOUNT_LIMIT) && !defined(CONFIG_SPL_BOOTCOUNT_LIMIT)
#endif
