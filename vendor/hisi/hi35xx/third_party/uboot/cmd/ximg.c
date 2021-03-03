#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <env.h>
#include <gzip.h>
#include <image.h>
#include <mapmem.h>
#include <watchdog.h>
#if defined(CONFIG_BZIP2)
#include <bzlib.h>
#endif
#include <asm/byteorder.h>
#include <asm/io.h>
#ifndef CONFIG_SYS_XIMG_LEN
#define CONFIG_SYS_XIMG_LEN	0x800000
#endif
#if defined(CONFIG_LEGACY_IMAGE_FORMAT)
#endif
#if defined(CONFIG_FIT)
#endif
#ifdef CONFIG_GZIP
#endif
#if defined(CONFIG_FIT)
#endif
#if defined(CONFIG_LEGACY_IMAGE_FORMAT)
#ifdef DEBUG
#endif
#endif
#if defined(CONFIG_FIT)
#endif
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#else	/* !(CONFIG_HW_WATCHDOG || CONFIG_WATCHDOG) */
#endif	/* CONFIG_HW_WATCHDOG || CONFIG_WATCHDOG */
#ifdef CONFIG_GZIP
#endif
#if defined(CONFIG_BZIP2) && defined(CONFIG_LEGACY_IMAGE_FORMAT)
#endif /* CONFIG_BZIP2 */
#ifdef CONFIG_SYS_LONGHELP
#if defined(CONFIG_FIT)
#endif
#endif
