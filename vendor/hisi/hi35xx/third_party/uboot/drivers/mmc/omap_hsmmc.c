#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <memalign.h>
#include <mmc.h>
#include <part.h>
#include <i2c.h>
#if defined(CONFIG_OMAP54XX) || defined(CONFIG_OMAP44XX)
#include <palmas.h>
#endif
#include <asm/io.h>
#include <asm/arch/mmc_host_def.h>
#ifdef CONFIG_OMAP54XX
#include <asm/arch/mux_dra7xx.h>
#include <asm/arch/dra7xx_iodelay.h>
#endif
#if !defined(CONFIG_SOC_KEYSTONE)
#include <asm/gpio.h>
#include <asm/arch/sys_proto.h>
#endif
#ifdef CONFIG_MMC_OMAP36XX_PINS
#include <asm/arch/mux.h>
#endif
#include <dm.h>
#include <power/regulator.h>
#include <thermal.h>
#if (defined(CONFIG_OMAP_GPIO) && !defined(CONFIG_SPL_BUILD)) || \
#define OMAP_HSMMC_USE_GPIO
#else
#undef OMAP_HSMMC_USE_GPIO
#endif
#define SYSCTL_SRC	(1 << 25)
#define SYSCTL_SRD	(1 << 26)
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#ifdef OMAP_HSMMC_USE_GPIO
#if CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#endif
#ifdef CONFIG_MMC_OMAP_HS_ADMA
#endif
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#ifdef CONFIG_MMC_OMAP_HS_ADMA
#define ADMA_MAX_LEN	63488
#define ADMA_DESC_ATTR_VALID		BIT(0)
#define ADMA_DESC_ATTR_END		BIT(1)
#define ADMA_DESC_ATTR_INT		BIT(2)
#define ADMA_DESC_ATTR_ACT1		BIT(4)
#define ADMA_DESC_ATTR_ACT2		BIT(5)
#define ADMA_DESC_TRANSFER_DATA		ADMA_DESC_ATTR_ACT2
#define ADMA_DESC_LINK_DESC	(ADMA_DESC_ATTR_ACT1 | ADMA_DESC_ATTR_ACT2)
#endif
#define MAX_RETRY_MS	1000
#define MMC_TIMEOUT_MS	20
#define DMA_TIMEOUT_PER_MB	333
#define OMAP_HSMMC_SUPPORTS_DUAL_VOLT		BIT(0)
#define OMAP_HSMMC_NO_1_8_V			BIT(1)
#define OMAP_HSMMC_USE_ADMA			BIT(2)
#define OMAP_HSMMC_REQUIRE_IODELAY		BIT(3)
#if CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if defined(OMAP_HSMMC_USE_GPIO) && !CONFIG_IS_ENABLED(DM_MMC)
#ifndef CONFIG_DM_GPIO
#endif
#endif
#if defined(CONFIG_OMAP34XX)
#ifdef CONFIG_MMC_OMAP36XX_PINS
#endif
#ifdef CONFIG_TARGET_OMAP3_CAIRO
#endif
#ifdef CONFIG_TARGET_OMAP3_LOGIC
#endif
#ifdef CONFIG_MMC_OMAP36XX_PINS
#endif
#ifdef CONFIG_MMC_OMAP36XX_PINS
#endif
#endif
#if (defined(CONFIG_OMAP54XX) || defined(CONFIG_OMAP44XX)) &&\
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#if CONFIG_IS_ENABLED(MMC_IO_VOLTAGE)
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#elif (defined(CONFIG_OMAP54XX) || defined(CONFIG_OMAP44XX)) && \
#else
#endif
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#endif
#ifdef CONFIG_MMC_OMAP_HS_ADMA
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#if defined(CONFIG_OMAP44XX) || defined(CONFIG_OMAP54XX) || \
#endif
#ifdef CONFIG_MMC_OMAP_HS_ADMA
#else
#define omap_hsmmc_adma_desc
#define omap_hsmmc_prepare_adma_table
#define omap_hsmmc_prepare_data
#define omap_hsmmc_dma_cleanup
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#ifdef CONFIG_MMC_OMAP_HS_ADMA
#endif
#ifdef CONFIG_MMC_OMAP_HS_ADMA
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#if CONFIG_IS_ENABLED(MMC_IO_VOLTAGE)
#endif
#endif
#ifdef OMAP_HSMMC_USE_GPIO
#if CONFIG_IS_ENABLED(DM_MMC)
#if CONFIG_IS_ENABLED(DM_GPIO)
#endif
#if CONFIG_IS_ENABLED(DM_GPIO)
#endif
#else
#endif
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#ifdef OMAP_HSMMC_USE_GPIO
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#else
#ifdef OMAP_HSMMC_USE_GPIO
#endif
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#ifdef OMAP_HSMMC2_BASE
#if (defined(CONFIG_OMAP44XX) || defined(CONFIG_OMAP54XX) || \
#endif
#endif
#ifdef OMAP_HSMMC3_BASE
#if defined(CONFIG_DRA7XX) && defined(CONFIG_HSMMC3_8BIT)
#endif
#endif
#ifdef OMAP_HSMMC_USE_GPIO
#endif
#if defined(CONFIG_OMAP34XX)
#endif
#else
#ifdef CONFIG_IODELAY_RECALIBRATION
#define OMAP_HSMMC_SETUP_PINCTRL(capmask, mode, optional)		\
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#ifdef CONFIG_OMAP54XX
#endif
#ifdef CONFIG_OMAP54XX
#endif
#ifdef CONFIG_OMAP54XX
#endif
#endif
#ifdef CONFIG_BLK
#endif
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#ifdef CONFIG_BLK
#else
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if defined(OMAP_HSMMC_USE_GPIO)
#if CONFIG_IS_ENABLED(OF_CONTROL) && CONFIG_IS_ENABLED(DM_GPIO)
#endif
#endif
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_BLK
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif
