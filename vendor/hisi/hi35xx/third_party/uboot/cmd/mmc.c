#include <common.h>
#include <command.h>
#include <console.h>
#include <memalign.h>
#include <mmc.h>
#include <sparse_format.h>
#include <image-sparse.h>
#ifdef CONFIG_EXT4_SPARSE
#endif
#if CONFIG_IS_ENABLED(MMC_VERBOSE)
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_HW_PARTITIONING)
#endif
#ifdef CONFIG_BLOCK_CACHE
#endif
#if CONFIG_IS_ENABLED(CMD_MMC_RPMB)
#ifndef CONFIG_BLK
#else
#endif
#endif
#if CONFIG_IS_ENABLED(CMD_MMC_SWRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#ifdef CONFIG_EXT4_SPARSE
#endif
#endif
#if CONFIG_IS_ENABLED(MMC_HW_PARTITIONING)
#endif
#ifdef CONFIG_SUPPORT_EMMC_BOOT
#endif
#ifdef CONFIG_CMD_BKOPS_ENABLE
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(CMD_MMC_SWRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_HW_PARTITIONING)
#endif
#ifdef CONFIG_SUPPORT_EMMC_BOOT
#endif
#if CONFIG_IS_ENABLED(CMD_MMC_RPMB)
#endif
#ifdef CONFIG_CMD_BKOPS_ENABLE
#endif
#if CONFIG_IS_ENABLED(CMD_MMC_SWRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_HW_PARTITIONING)
#endif
#ifdef CONFIG_SUPPORT_EMMC_BOOT
#endif
#if CONFIG_IS_ENABLED(CMD_MMC_RPMB)
#endif
#ifdef CONFIG_CMD_BKOPS_ENABLE
#endif
