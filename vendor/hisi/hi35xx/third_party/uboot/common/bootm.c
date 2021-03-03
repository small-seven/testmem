#ifndef USE_HOSTCC
#include <common.h>
#include <bootstage.h>
#include <cpu_func.h>
#include <env.h>
#include <errno.h>
#include <fdt_support.h>
#include <irq_func.h>
#include <lmb.h>
#include <malloc.h>
#include <mapmem.h>
#include <asm/io.h>
#if defined(CONFIG_CMD_USB)
#include <usb.h>
#endif
#else
#include "mkimage.h"
#endif
#include <command.h>
#include <bootm.h>
#include <image.h>
#ifndef CONFIG_SYS_BOOTM_LEN
#define CONFIG_SYS_BOOTM_LEN	0x800000
#endif
#define IH_INITRD_ARCH IH_ARCH_DEFAULT
#ifndef USE_HOSTCC
#ifdef CONFIG_LMB
#else
#define lmb_reserve(lmb, base, size)
#endif
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#if IMAGE_ENABLE_FIT
#endif
#ifdef CONFIG_ANDROID_BOOT_IMAGE
#endif
#if IMAGE_ENABLE_FIT
#endif
#if IMAGE_ENABLE_OF_LIBFDT
#endif
#if IMAGE_ENABLE_FIT
#if defined(CONFIG_FPGA)
#endif
#endif
#endif /* USE_HOSTC */
#if !defined(USE_HOSTCC) || defined(CONFIG_FIT_SIGNATURE)
#ifndef USE_HOSTCC
#endif
#endif
#ifndef USE_HOSTCC
#ifdef CONFIG_NETCONSOLE
# ifndef CONFIG_DM_ETH
# endif
#endif
#if defined(CONFIG_CMD_USB)
#endif
#if defined(CONFIG_SILENT_CONSOLE) && !defined(CONFIG_SILENT_U_BOOT_ONLY)
#define CONSOLE_ARG     "console="
#define CONSOLE_ARG_LEN (sizeof(CONSOLE_ARG) - 1)
#endif /* CONFIG_SILENT_CONSOLE */
#ifdef CONFIG_SYS_BOOT_RAMDISK_HIGH
#endif
#if IMAGE_ENABLE_OF_LIBFDT && defined(CONFIG_LMB)
#endif
#if defined(CONFIG_SILENT_CONSOLE) && !defined(CONFIG_SILENT_U_BOOT_ONLY)
#endif
#ifdef CONFIG_TRACE
#endif
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#if IMAGE_ENABLE_FIT
#endif
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#if IMAGE_ENABLE_FIT
#endif
#ifdef CONFIG_ANDROID_BOOT_IMAGE
#endif
#else /* USE_HOSTCC */
#if defined(CONFIG_FIT_SIGNATURE)
#endif
#endif /* ndef USE_HOSTCC */
