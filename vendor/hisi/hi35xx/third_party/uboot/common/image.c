#ifndef USE_HOSTCC
#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <u-boot/crc.h>
#include <watchdog.h>
#ifdef CONFIG_SHOW_BOOT_PROGRESS
#include <status_led.h>
#endif
#include <rtc.h>
#include <gzip.h>
#include <image.h>
#include <lz4.h>
#include <mapmem.h>
#if IMAGE_ENABLE_FIT || IMAGE_ENABLE_OF_LIBFDT
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fpga.h>
#include <xilinx.h>
#endif
#include <u-boot/md5.h>
#include <u-boot/sha1.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <bzlib.h>
#include <linux/lzo.h>
#include <lzma/LzmaTypes.h>
#include <lzma/LzmaDec.h>
#include <lzma/LzmaTools.h>
#ifdef CONFIG_CMD_BDI
#endif
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#else
#include "mkimage.h"
#include <u-boot/md5.h>
#include <time.h>
#include <image.h>
#ifndef __maybe_unused
# define __maybe_unused		/* unimplemented */
#endif
#endif /* !USE_HOSTCC*/
#include <u-boot/crc.h>
#include <imximage.h>
#ifndef CONFIG_SYS_BARGSIZE
#define CONFIG_SYS_BARGSIZE 512
#endif
#if defined(CONFIG_LYNXKDI) || defined(USE_HOSTCC)
#endif
#if defined(CONFIG_CMD_ELF) || defined(USE_HOSTCC)
#endif
#if defined(CONFIG_INTEGRITY) || defined(USE_HOSTCC)
#endif
#ifdef USE_HOSTCC
#endif
#if defined(CONFIG_BOOTM_OPENRTOS) || defined(USE_HOSTCC)
#endif
#ifdef CONFIG_GZIP
#endif /* CONFIG_GZIP */
#ifdef CONFIG_BZIP2
#endif /* CONFIG_BZIP2 */
#ifdef CONFIG_LZMA
#endif /* CONFIG_LZMA */
#ifdef CONFIG_LZO
#endif /* CONFIG_LZO */
#ifdef CONFIG_LZ4
#endif /* CONFIG_LZ4 */
#ifndef USE_HOSTCC
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#endif /* !USE_HOSTCC */
#ifndef USE_HOSTCC
#if defined(CONFIG_SYS_SDRAM_BASE)
#elif defined(CONFIG_ARM) || defined(CONFIG_MICROBLAZE)
#else
#endif
#if (defined(CONFIG_ARM) || defined(CONFIG_MICROBLAZE)) && \
#else
#endif
#if defined(CONFIG_SYS_BOOTMAPSZ)
#else
#endif
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#else	/* !(CONFIG_HW_WATCHDOG || CONFIG_WATCHDOG) */
#endif	/* CONFIG_HW_WATCHDOG || CONFIG_WATCHDOG */
#else	/* USE_HOSTCC */
#endif /* !USE_HOSTCC */
#ifndef USE_HOSTCC
#else
#endif
#if IMAGE_ENABLE_TIMESTAMP
#ifndef USE_HOSTCC
#else
#endif
#endif
#if defined(USE_HOSTCC) || !defined(CONFIG_NEEDS_MANUAL_RELOC)
#else
#endif
#if defined(USE_HOSTCC) || !defined(CONFIG_NEEDS_MANUAL_RELOC)
#else
#endif
#if defined(USE_HOSTCC) || !defined(CONFIG_NEEDS_MANUAL_RELOC)
#else
#endif
#if defined(USE_HOSTCC) || !defined(CONFIG_NEEDS_MANUAL_RELOC)
#else
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#else
#endif
#ifndef USE_HOSTCC
#if CONFIG_IS_ENABLED(FIT)
#endif
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#if IMAGE_ENABLE_FIT || IMAGE_ENABLE_OF_LIBFDT
#endif
#ifdef CONFIG_ANDROID_BOOT_IMAGE
#endif
#if IMAGE_ENABLE_FIT
#endif
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#ifdef CONFIG_SUPPORT_RAW_INITRD
#endif
#if IMAGE_ENABLE_FIT
#endif
#ifdef CONFIG_ANDROID_BOOT_IMAGE
#endif
#if IMAGE_ENABLE_FIT
#endif
#if IMAGE_ENABLE_FIT
#endif
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#if IMAGE_ENABLE_FIT
#endif
#ifdef CONFIG_ANDROID_BOOT_IMAGE
#endif
#ifdef CONFIG_SUPPORT_RAW_INITRD
#endif
#ifdef CONFIG_SYS_BOOT_RAMDISK_HIGH
#ifdef CONFIG_MP
#endif
#endif /* CONFIG_SYS_BOOT_RAMDISK_HIGH */
#if IMAGE_ENABLE_FIT
#else
#endif
#if IMAGE_ENABLE_FIT
#if defined(CONFIG_FPGA)
#endif
#endif
#ifdef CONFIG_SYS_BOOT_GET_CMDLINE
#endif /* CONFIG_SYS_BOOT_GET_CMDLINE */
#ifdef CONFIG_SYS_BOOT_GET_KBD
#if defined(DEBUG) && defined(CONFIG_CMD_BDI)
#endif
#endif /* CONFIG_SYS_BOOT_GET_KBD */
#ifdef CONFIG_LMB
#endif /* CONFIG_LMB */
#endif /* !USE_HOSTCC */
