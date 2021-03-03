#include <config.h>
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <mmc.h>
#include <command.h>
#include <part.h>
#include <malloc.h>
#include <asm/io.h>
#include <asm/arch/sdmmc_defs.h>
#include <asm-generic/gpio.h>
#define DAVINCI_MAX_BLOCKS	(32)
#define WATCHDOG_COUNT		(100000)
#define get_val(addr)		REG(addr)
#define set_val(addr, val)	REG(addr) = (val)
#define set_bit(addr, val)	set_val((addr), (get_val(addr) | (val)))
#define clear_bit(addr, val)	set_val((addr), (get_val(addr) & ~(val)))
#ifdef CONFIG_DM_MMC
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#if CONFIG_IS_ENABLED(DM_GPIO)
#endif
#if CONFIG_IS_ENABLED(DM_GPIO)
#endif
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#ifdef CONFIG_SPL_BUILD
#endif
#if CONFIG_IS_ENABLED(DM_GPIO)
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#if CONFIG_BLK
#endif
#endif
