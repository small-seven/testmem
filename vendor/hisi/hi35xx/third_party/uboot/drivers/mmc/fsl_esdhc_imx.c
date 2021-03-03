#include <config.h>
#include <common.h>
#include <command.h>
#include <clk.h>
#include <cpu_func.h>
#include <errno.h>
#include <hwconfig.h>
#include <mmc.h>
#include <part.h>
#include <power/regulator.h>
#include <malloc.h>
#include <fsl_esdhc_imx.h>
#include <fdt_support.h>
#include <asm/io.h>
#include <dm.h>
#include <asm-generic/gpio.h>
#include <dm/pinctrl.h>
#if !CONFIG_IS_ENABLED(BLK)
#include "mmc_private.h"
#endif
#define SDHCI_IRQ_EN_BITS		(IRQSTATEN_CC | IRQSTATEN_TC | \
#define MAX_TUNING_LOOP 40
#define ESDHC_DRIVER_STAGE_VALUE 0xffffffff
#if !CONFIG_IS_ENABLED(BLK)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifndef CONFIG_SYS_FSL_ESDHC_USE_PIO
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC111
#endif
#ifdef CONFIG_SYS_FSL_ESDHC_USE_PIO
#endif
#if defined(CONFIG_S32V234) || defined(CONFIG_IMX8) || defined(CONFIG_IMX8M)
#endif
#ifndef CONFIG_SYS_FSL_ESDHC_USE_PIO
#if defined(CONFIG_S32V234) || defined(CONFIG_IMX8) || defined(CONFIG_IMX8M)
#else
#endif
#endif
#ifndef CONFIG_SYS_FSL_ESDHC_USE_PIO
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifndef CONFIG_SYS_FSL_ESDHC_USE_PIO
#if defined(CONFIG_S32V234) || defined(CONFIG_IMX8) || defined(CONFIG_IMX8M)
#else
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC_A001
#endif
#ifdef ESDHCI_QUIRK_BROKEN_TIMEOUT_VALUE
#endif
#if defined(CONFIG_S32V234) || defined(CONFIG_IMX8) || defined(CONFIG_IMX8M)
#else
#endif
#ifdef CONFIG_MCF5441x
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC111
#endif
#if defined(CONFIG_FSL_USDHC)
#else
#endif
#ifdef CONFIG_SYS_FSL_ESDHC_USE_PIO
#else
#ifdef CONFIG_MCF5441x
#endif
#endif
#ifdef ARCH_MXC
#ifdef CONFIG_MX53
#else
#endif
#else
#endif
#ifdef CONFIG_FSL_USDHC
#else
#endif
#ifdef CONFIG_FSL_USDHC
#else
#endif
#ifdef CONFIG_FSL_ESDHC_USE_PERIPHERAL_CLK
#endif
#ifdef MMC_SUPPORTS_TUNING
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#endif
#ifdef CONFIG_FSL_ESDHC_USE_PERIPHERAL_CLK
#endif
#ifdef MMC_SUPPORTS_TUNING
#ifdef CONFIG_FSL_USDHC
#else
#endif
#ifdef CONFIG_FSL_USDHC
#else
#endif
#endif
#if defined(CONFIG_FSL_USDHC)
#endif
#ifndef ARCH_MXC
#endif
#ifndef CONFIG_FSL_USDHC
#else
#endif
#ifdef CONFIG_MCF5441x
#else
#endif
#ifdef CONFIG_ESDHC_DETECT_QUIRK
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#ifdef CONFIG_DM_GPIO
#endif
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#ifdef CONFIG_MCF5441x
#endif
#ifndef CONFIG_FSL_USDHC
#else
#endif
#ifndef CONFIG_DM_MMC
#endif
#ifdef CONFIG_MCF5441x
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC135
#endif
#ifdef CONFIG_SYS_FSL_MMC_HAS_CAPBLT_VS33
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#ifdef CONFIG_SYS_SD_VOLTAGE
#else
#endif
#ifdef CONFIG_SYS_FSL_ESDHC_HAS_DDR_MODE
#endif
#ifdef CONFIG_ESDHC_DETECT_8_BIT_QUIRK
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#ifdef CONFIG_OF_LIBFDT
#ifdef CONFIG_FSL_ESDHC_PIN_MUX
#endif
#ifdef CONFIG_FSL_ESDHC_USE_PERIPHERAL_CLK
#else
#endif
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#include <asm/arch/clock.h>
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if !CONFIG_IS_ENABLED(BLK)
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_DM_GPIO
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if !CONFIG_IS_ENABLED(BLK)
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#if CONFIG_IS_ENABLED(MMC_HS400_ES_SUPPORT)
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_ES_SUPPORT)
#endif
#endif
#if CONFIG_IS_ENABLED(BLK)
#endif
#if CONFIG_IS_ENABLED(BLK)
#endif
#endif
