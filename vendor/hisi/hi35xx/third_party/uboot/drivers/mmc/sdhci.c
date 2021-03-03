#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <mmc.h>
#include <sdhci.h>
#include <dm.h>
#if defined(CONFIG_FIXED_SDHCI_ALIGNED_BUFFER)
#else
#endif
#if CONFIG_IS_ENABLED(MMC_SDHCI_ADMA)
#ifdef CONFIG_DMA_ADDR_T_64BIT
#endif
#elif defined(CONFIG_MMC_SDHCI_SDMA)
#endif
#if (defined(CONFIG_MMC_SDHCI_SDMA) || CONFIG_IS_ENABLED(MMC_SDHCI_ADMA))
#if defined(CONFIG_FIXED_SDHCI_ALIGNED_BUFFER)
#endif
#else
#endif
#define SDHCI_CMD_MAX_TIMEOUT			3200
#define SDHCI_CMD_DEFAULT_TIMEOUT		100
#define SDHCI_READ_STATUS_TIMEOUT		1000
#ifdef CONFIG_DM_MMC
#else
#endif
#if defined(CONFIG_TARGET_HI3516DV200) || defined(CONFIG_TARGET_HI3516EV300)
#endif
#if defined(MMC_SUPPORTS_TUNING)
#if defined(CONFIG_DM_MMC)
#else
#endif
#endif
#ifdef CONFIG_DM_MMC
#else
#endif
#if CONFIG_IS_ENABLED(DM_MMC) && CONFIG_IS_ENABLED(DM_GPIO)
#endif
#ifdef CONFIG_DM_MMC
#if CONFIG_IS_ENABLED(DM_GPIO)
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#else
#ifdef MMC_SUPPORTS_TUNING
#endif
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#ifdef CONFIG_MMC_SDHCI_SDMA
#endif
#if CONFIG_IS_ENABLED(MMC_SDHCI_ADMA)
#ifdef CONFIG_DMA_ADDR_T_64BIT
#else
#endif
#endif
#ifndef CONFIG_DM_MMC
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#ifdef CONFIG_BLK
#else
#endif
