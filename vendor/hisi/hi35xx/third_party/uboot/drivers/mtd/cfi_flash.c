#include <common.h>
#include <console.h>
#include <dm.h>
#include <env.h>
#include <errno.h>
#include <fdt_support.h>
#include <irq_func.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>
#include <env_internal.h>
#include <mtd/cfi_flash.h>
#include <watchdog.h>
#ifdef CONFIG_FLASH_CFI_MTD
#else
#define flash_verbose 1
#endif
#ifndef CONFIG_SYS_FLASH_CFI_WIDTH
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_8BIT
#endif
#ifdef CONFIG_CFI_FLASH_USE_WEAK_ACCESSORS
#define __maybe_weak __weak
#else
#define __maybe_weak static
#endif
#ifdef CONFIG_SYS_CFI_FLASH_CONFIG_REGS
#else
#endif
#if defined(CONFIG_SYS_MAX_FLASH_BANKS_DETECT)
#else
#endif
#ifdef CONFIG_CFI_FLASH /* for driver model */
#else
#endif
#ifdef CONFIG_SYS_FLASH_BANKS_SIZES
#else
#endif
#if defined(CONFIG_ENV_IS_IN_FLASH) || defined(CONFIG_ENV_ADDR_REDUND) || \
#endif
#if defined(__LITTLE_ENDIAN) || defined(CONFIG_SYS_WRITE_SWAPPED_DATA)
#endif
#if defined(__LITTLE_ENDIAN) || defined(CONFIG_SYS_WRITE_SWAPPED_DATA)
#else
#endif
#ifdef DEBUG
#endif
#if defined(__LITTLE_ENDIAN) || defined(CONFIG_SYS_WRITE_SWAPPED_DATA)
#else
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#if defined(__LITTLE_ENDIAN) || defined(CONFIG_SYS_WRITE_SWAPPED_DATA)
#else
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_FLASH_CFI_LEGACY
#endif
#if CONFIG_SYS_HZ != 1000
#endif
#ifdef CONFIG_SYS_LOW_RES_TIMER
#endif
#ifdef CONFIG_SYS_CFI_FLASH_STATUS_POLL
#endif
#ifdef CONFIG_SYS_CFI_FLASH_STATUS_POLL
#if CONFIG_SYS_HZ != 1000
#endif
#ifdef CONFIG_SYS_LOW_RES_TIMER
#endif
#endif /* CONFIG_SYS_CFI_FLASH_STATUS_POLL */
#if defined(__LITTLE_ENDIAN) && !defined(CONFIG_SYS_WRITE_SWAPPED_DATA)
#endif
#if defined(__LITTLE_ENDIAN) && !defined(CONFIG_SYS_WRITE_SWAPPED_DATA)
#else
#endif
#if defined(__LITTLE_ENDIAN) && !defined(CONFIG_SYS_WRITE_SWAPPED_DATA)
#else
#endif
#if defined(__LITTLE_ENDIAN) && !defined(CONFIG_SYS_WRITE_SWAPPED_DATA)
#else
#endif
#ifdef CONFIG_FLASH_CFI_LEGACY
#endif
#ifdef CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#ifdef CONFIG_FLASH_SPANSION_S29WS_N
#endif
#endif /* CONFIG_SYS_FLASH_USE_BUFFER_WRITE */
#ifdef CONFIG_SYS_FLASH_CHECK_BLANK_BEFORE_ERASE
#endif
#ifdef CONFIG_FLASH_CFI_LEGACY
#endif
#ifdef CONFIG_SYS_FLASH_EMPTY_INFO
#endif /* CONFIG_SYS_FLASH_EMPTY_INFO */
#ifdef CONFIG_FLASH_CFI_LEGACY
#endif
#ifdef CONFIG_SYS_FLASH_EMPTY_INFO
#else	/* ! CONFIG_SYS_FLASH_EMPTY_INFO */
#endif
#ifdef CONFIG_FLASH_SHOW_PROGRESS
#define FLASH_SHOW_PROGRESS(scale, dots, digit, dots_sub) \
#else
#define FLASH_SHOW_PROGRESS(scale, dots, digit, dots_sub)
#endif
#ifdef CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#endif
#ifdef CONFIG_FLASH_SHOW_PROGRESS
#endif
#ifdef CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#else
#endif /* CONFIG_SYS_FLASH_USE_BUFFER_WRITE */
#ifdef CONFIG_SYS_FLASH_PROTECTION
#ifdef CONFIG_FLASH_CFI_LEGACY
#endif
#endif /* CONFIG_SYS_FLASH_PROTECTION */
#ifdef CONFIG_SYS_FLASH_PROTECTION
#endif
#ifdef CONFIG_SYS_FLASH_PROTECTION
#endif
#ifdef CONFIG_FLASH_CFI_LEGACY
#else
#endif
#ifdef CONFIG_SYS_FLASH_PROTECTION
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_FLASH_CFI_MTD
#endif
#ifdef CONFIG_SYS_CFI_FLASH_CONFIG_REGS
#endif
#if defined(CONFIG_SYS_FLASH_AUTOPROTECT_LIST)
#endif
#if defined(CONFIG_SYS_MONITOR_BASE) && \
#endif
#ifdef CONFIG_ENV_IS_IN_FLASH
#endif
#ifdef CONFIG_ENV_ADDR_REDUND
#endif
#if defined(CONFIG_SYS_FLASH_AUTOPROTECT_LIST)
#endif
#ifdef CONFIG_SYS_FLASH_PROTECTION
#endif
#ifdef CONFIG_CFI_FLASH /* for driver model */
#endif
#ifndef CONFIG_SYS_FLASH_QUIET_TEST
#endif /* CONFIG_SYS_FLASH_QUIET_TEST */
#ifdef CONFIG_SYS_FLASH_PROTECTION
#endif /* CONFIG_SYS_FLASH_PROTECTION */
#ifdef CONFIG_FLASH_CFI_MTD
#endif
#ifdef CONFIG_CFI_FLASH /* for driver model */
#endif /* CONFIG_CFI_FLASH */
