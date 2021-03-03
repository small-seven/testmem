#include <common.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/processor.h>
#include <asm/io.h>
#ifdef CONFIG_PPC
#include <asm/fsl_portals.h>
#include <asm/fsl_liodn.h>
#else
#include <asm/arch-fsl-layerscape/fsl_portals.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#endif
#include <fsl_qbman.h>
#define MAX_BPORTALS (CONFIG_SYS_BMAN_CINH_SIZE / CONFIG_SYS_BMAN_SP_CINH_SIZE)
#define MAX_QPORTALS (CONFIG_SYS_QMAN_CINH_SIZE / CONFIG_SYS_QMAN_SP_CINH_SIZE)
#ifdef CONFIG_PHYS_64BIT
#endif
#ifdef CONFIG_FSL_CORENET
#else
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#endif
#endif
#ifdef CONFIG_PPC
#ifdef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_FSL_CORENET
#endif
#endif /* CONFIG_PPC */
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#endif
#if defined(CONFIG_PPC) || defined(CONFIG_ARCH_LS1043A) || \
#ifdef CONFIG_FSL_CORENET
#endif
#if defined(CONFIG_SYS_DPAA_FMAN) && defined(CONFIG_PPC)
#endif
#endif /* CONFIG_PPC || CONFIG_ARCH_LS1043A || CONFIG_ARCH_LS1046A */
#ifdef CONFIG_PPC
#ifdef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_FSL_CORENET
#ifdef CONFIG_SYS_DPAA_PME
#else
#endif
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifdef CONFIG_SYS_DPAA_RMAN
#endif
#else
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#endif
#endif /* CONFIG_PPC */
