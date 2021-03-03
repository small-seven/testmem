#include <config.h>
#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <errno.h>
#include <hwconfig.h>
#include <mmc.h>
#include <part.h>
#include <malloc.h>
#include <fsl_esdhc.h>
#include <fdt_support.h>
#include <asm/io.h>
#include <dm.h>
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#ifndef CONFIG_SYS_FSL_ESDHC_USE_PIO
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC111
#endif
#ifdef CONFIG_SYS_FSL_ESDHC_USE_PIO
#endif
#if defined(CONFIG_FSL_LAYERSCAPE)
#endif
#ifndef CONFIG_SYS_FSL_ESDHC_USE_PIO
#if defined(CONFIG_FSL_LAYERSCAPE)
#else
#endif
#endif
#ifndef CONFIG_SYS_FSL_ESDHC_USE_PIO
#endif
#ifndef CONFIG_SYS_FSL_ESDHC_USE_PIO
#if defined(CONFIG_FSL_LAYERSCAPE)
#else
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC_A001
#endif
#ifdef ESDHCI_QUIRK_BROKEN_TIMEOUT_VALUE
#endif
#if defined(CONFIG_FSL_LAYERSCAPE)
#else
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC111
#endif
#ifdef CONFIG_SYS_FSL_ESDHC_USE_PIO
#else
#endif
#ifdef CONFIG_FSL_ESDHC_USE_PERIPHERAL_CLK
#endif
#ifdef CONFIG_FSL_ESDHC_USE_PERIPHERAL_CLK
#endif
#ifdef CONFIG_ESDHC_DETECT_QUIRK
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC135
#endif
#ifdef CONFIG_SYS_FSL_MMC_HAS_CAPBLT_VS33
#endif
#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
#endif
#ifdef CONFIG_OF_LIBFDT
#ifdef CONFIG_FSL_ESDHC_PIN_MUX
#endif
#ifdef CONFIG_FSL_ESDHC_USE_PERIPHERAL_CLK
#else
#endif
#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
#endif
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#ifdef CONFIG_ESDHC_DETECT_8_BIT_QUIRK
#endif
#else /* DM_MMC */
#ifdef CONFIG_PPC
#else
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#endif
