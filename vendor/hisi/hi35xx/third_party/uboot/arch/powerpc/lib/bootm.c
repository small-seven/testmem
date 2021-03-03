#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <watchdog.h>
#include <command.h>
#include <image.h>
#include <malloc.h>
#include <u-boot/zlib.h>
#include <bzlib.h>
#include <asm/byteorder.h>
#include <asm/mp.h>
#include <bootm.h>
#include <vxworks.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#include <fdt_support.h>
#endif
#ifdef CONFIG_SYS_INIT_RAM_LOCK
#include <asm/cache.h>
#endif
#ifndef CONFIG_SYS_LINUX_LOWMEM_MAX_SIZE
#define CONFIG_SYS_LINUX_LOWMEM_MAX_SIZE	(768*1024*1024)
#endif
#ifdef CONFIG_OF_LIBFDT
#endif
#ifdef CONFIG_BOOTSTAGE_FDT
#endif
#ifdef CONFIG_BOOTSTAGE_REPORT
#endif
#if defined(CONFIG_SYS_INIT_RAM_LOCK) && !defined(CONFIG_E500)
#endif
#if defined(CONFIG_OF_LIBFDT)
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_MP
#endif
#ifdef CONFIG_MP
#endif
#if defined(CONFIG_CPM2)
#endif
#if defined(CONFIG_BOOTM_VXWORKS)
#if defined(CONFIG_OF_LIBFDT)
#if defined(CONFIG_MP)
#if defined(CONFIG_MPC85xx)
#elif defined(CONFIG_MPC86xx)
#endif
#endif
#endif
#endif
