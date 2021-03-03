#include <common.h>
#include <efi_loader.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <phy.h>
#ifdef CONFIG_FSL_LSCH3
#include <asm/arch/fdt.h>
#endif
#ifdef CONFIG_FSL_ESDHC
#include <fsl_esdhc.h>
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#include <fsl_fman.h>
#endif
#ifdef CONFIG_MP
#include <asm/arch/mp.h>
#endif
#include <fsl_sec.h>
#include <asm/arch-fsl-layerscape/soc.h>
#ifdef CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT
#include <asm/armv8/sec_firmware.h>
#endif
#include <asm/arch/speed.h>
#include <fsl_qbman.h>
#ifdef CONFIG_MP
#if defined(CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT) && \
#endif
#if CONFIG_IS_ENABLED(EFI_LOADER)
#endif
#endif
#ifdef CONFIG_HAS_FEATURE_GIC64K_ALIGN
#endif
#ifdef CONFIG_HAS_FEATURE_ENHANCED_MSI
#endif
#ifdef CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT
#endif
#ifdef CONFIG_ARCH_LS1028A
#endif
#if CONFIG_SYS_FSL_SEC_COMPAT >= 4
#ifdef CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT
#endif
#endif
#ifdef CONFIG_MP
#endif
#ifdef CONFIG_SYS_NS16550
#endif
#if defined(CONFIG_PCIE_LAYERSCAPE) || defined(CONFIG_PCIE_LAYERSCAPE_GEN4)
#endif
#ifdef CONFIG_FSL_ESDHC
#endif
#ifdef CONFIG_SYS_DPAA_QBMAN
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifndef CONFIG_ARCH_LS1012A
#endif
#ifdef CONFIG_HAS_FEATURE_GIC64K_ALIGN
#endif
#ifdef CONFIG_HAS_FEATURE_ENHANCED_MSI
#endif
#ifdef CONFIG_ARCH_LS1028A
#endif
