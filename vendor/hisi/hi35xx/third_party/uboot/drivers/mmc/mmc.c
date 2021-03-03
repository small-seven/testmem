#include <config.h>
#include <common.h>
#include <command.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <errno.h>
#include <mmc.h>
#include <part.h>
#include <power/regulator.h>
#include <malloc.h>
#include <memalign.h>
#include <linux/list.h>
#include <div64.h>
#include "mmc_private.h"
#define DEFAULT_CMD6_TIMEOUT_MS  500
#if !CONFIG_IS_ENABLED(MMC_TINY)
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#ifdef CONFIG_MMC_TRACE
#endif
#if CONFIG_IS_ENABLED(MMC_VERBOSE) || defined(DEBUG)
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#ifdef CONFIG_MMC_QUIRKS
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#if CONFIG_IS_ENABLED(BLK)
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT)
#endif
#if !CONFIG_IS_ENABLED(MMC_TINY)
#if CONFIG_IS_ENABLED(MMC_HS200_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_ES_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_HS200_SUPPORT) || \
#endif
#if CONFIG_IS_ENABLED(MMC_HS200_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_SUPPORT) || \
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_ES_SUPPORT)
#endif
#endif
#if CONFIG_IS_ENABLED(MMC_HW_PARTITIONING)
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#if !CONFIG_IS_ENABLED(MMC_TINY)
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT)
#endif
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#ifdef MMC_SUPPORTS_TUNING
#endif
#endif
#if CONFIG_IS_ENABLED(MMC_VERBOSE) || defined(DEBUG)
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#if CONFIG_IS_ENABLED(MMC_IO_VOLTAGE)
#else
#endif
#if !CONFIG_IS_ENABLED(MMC_TINY)
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT)
#ifdef MMC_SUPPORTS_TUNING
#endif
#endif
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT)
#endif
#define for_each_sd_mode_by_pref(caps, mwt) \
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT)
#else
#endif
#ifdef DEBUG
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_IO_VOLTAGE)
#else
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_ES_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(MMC_HS200_SUPPORT)
#endif
#define for_each_mmc_mode_by_pref(caps, mwt) \
#if CONFIG_IS_ENABLED(MMC_HS400_SUPPORT)
#else
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_ES_SUPPORT)
#else
#endif
#define for_each_supported_width(caps, ddr, ecbv) \
#ifdef DEBUG
#endif
#if CONFIG_IS_ENABLED(MMC_HS200_SUPPORT) || \
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#endif
#if CONFIG_IS_ENABLED(MMC_TINY)
#endif
#if CONFIG_IS_ENABLED(MMC_TINY)
#else
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_HW_PARTITIONING)
#endif
#if !CONFIG_IS_ENABLED(MMC_TINY)
#endif
#ifdef CONFIG_MMC_SPI_CRC_ON
#endif
#ifdef CONFIG_MMC_QUIRKS
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_TINY)
#else
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if !defined(CONFIG_SPL_BUILD) || \
#else
#endif
#if !defined(CONFIG_DM_MMC) && (!defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBDISK_SUPPORT))
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#else /* !CONFIG_DM_MMC */
#endif
#if CONFIG_IS_ENABLED(DM_MMC) && CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(DM_MMC) && CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
#endif
#ifdef CONFIG_MMC_QUIRKS
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#if !defined(CONFIG_MMC_BROKEN_CD)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#endif
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT) || \
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(BLK)
#if !CONFIG_IS_ENABLED(MMC_TINY)
#endif
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
#endif
#endif
#ifdef CONFIG_CMD_BKOPS_ENABLE
#endif
