#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <fsl_ddr_sdram.h>
#include <vsprintf.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/system.h>
#include <fm_eth.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/soc.h>
#include <asm/arch/cpu.h>
#include <asm/arch/speed.h>
#include <fsl_immap.h>
#include <asm/arch/mp.h>
#include <efi_loader.h>
#include <fsl-mc/fsl_mc.h>
#ifdef CONFIG_FSL_ESDHC
#include <fsl_esdhc.h>
#endif
#include <asm/armv8/sec_firmware.h>
#ifdef CONFIG_SYS_FSL_DDR
#include <fsl_ddr.h>
#endif
#include <asm/arch/clock.h>
#include <hwconfig.h>
#include <fsl_qbman.h>
#ifdef CONFIG_TFABOOT
#include <env_internal.h>
#ifdef CONFIG_CHAIN_OF_TRUST
#include <fsl_validate.h>
#endif
#endif
#include <linux/mii.h>
#define EARLY_PGTABLE_SIZE 0x5000
#ifdef CONFIG_FSL_LSCH3
#ifdef CONFIG_FSL_IFC
#endif
#if defined(CONFIG_TFABOOT) || \
#else	/* Start with nGnRnE and PXN and UXN to prevent speculative access */
#endif
#ifdef CONFIG_FSL_IFC
#endif
#ifdef CONFIG_SYS_FSL_DRAM_BASE3
#endif
#elif defined(CONFIG_FSL_LSCH2)
#ifdef CONFIG_FSL_IFC
#endif
#if defined(CONFIG_TFABOOT) || \
#else	/* Start with nGnRnE and PXN and UXN to prevent speculative access */
#endif
#endif
#ifdef CONFIG_FSL_LSCH3
#ifdef CONFIG_FSL_IFC
#endif
#ifdef CONFIG_SYS_PCIE3_PHYS_ADDR
#endif
#ifdef CONFIG_SYS_PCIE4_PHYS_ADDR
#endif
#ifdef SYS_PCIE5_PHYS_ADDR
#endif
#ifdef SYS_PCIE6_PHYS_ADDR
#endif
#ifdef CONFIG_SYS_FSL_DRAM_BASE3
#endif
#elif defined(CONFIG_FSL_LSCH2)
#ifdef CONFIG_FSL_IFC
#endif
#ifdef CONFIG_SYS_PCIE3_PHYS_ADDR
#endif
#endif
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
#endif
#ifdef CONFIG_ARCH_LX2160A
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#ifdef CONFIG_ARCH_LS2080A
#ifdef CONFIG_SYS_PCIE3_PHYS_ADDR
#endif
#ifdef CONFIG_SYS_PCIE4_PHYS_ADDR
#endif
#endif
#ifdef CONFIG_SYS_FSL_DRAM_BASE2
#if (CONFIG_NR_DRAM_BANKS >= 2)
#else
#endif
#endif
#ifdef CONFIG_SYS_FSL_DRAM_BASE3
#if (CONFIG_NR_DRAM_BANKS >= 3)
#else
#endif
#endif
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
#endif
#endif	/* !CONFIG_IS_ENABLED(SYS_DCACHE_OFF) */
#ifdef CONFIG_TFABOOT
#if !defined(CONFIG_NXP_LSCH3_2)
#endif
#if defined(CONFIG_FSL_LSCH3)
#if defined(CONFIG_NXP_LSCH3_2)
#else
#endif
#elif defined(CONFIG_FSL_LSCH2)
#endif
#if defined(CONFIG_FSL_LSCH3)
#elif defined(CONFIG_FSL_LSCH2)
#endif
#ifdef CONFIG_FSL_LSCH3
#elif defined(CONFIG_FSL_LSCH2)
#endif
#ifdef CONFIG_ENV_IS_IN_MMC
#endif
#ifdef	CONFIG_ENV_IS_NOWHERE
#endif
#endif	/* CONFIG_TFABOOT */
#ifndef CONFIG_FSL_LSCH3
#endif
#ifdef CONFIG_DISPLAY_CPUINFO
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
#endif
#ifdef CONFIG_FSL_ESDHC
#endif
#if defined(CONFIG_FSL_MC_ENET) && !defined(CONFIG_SPL_BUILD)
#endif
#ifdef CONFIG_FMAN_ENET
#endif
#define SIP_PREFETCH_DISABLE_64 0xC200FF13
#ifdef CONFIG_SYS_FSL_ERRATUM_A009635
#endif
#if defined(CONFIG_SYS_FSL_ERRATUM_A009942) && defined(CONFIG_SYS_FSL_DDR)
#endif
#ifdef CONFIG_SYS_HAS_SERDES
#endif
#ifdef CONFIG_SYS_FSL_HAS_RGMII
#endif
#ifdef CONFIG_FMAN_ENET
#endif
#ifdef CONFIG_SYS_DPAA_QBMAN
#endif
#ifdef CONFIG_FSL_LSCH3
#endif
#if defined(CONFIG_ARCH_LS2080A) || defined(CONFIG_ARCH_LS1088A) || \
#endif
#ifdef COUNTER_FREQUENCY_REAL
#endif
#ifdef CONFIG_FSL_LSCH3
#endif
#if defined(CONFIG_ARCH_LS2080A) || defined(CONFIG_ARCH_LS1088A) || \
#endif
#ifdef CONFIG_ARCH_LX2160A
#else
#endif
#if defined(CONFIG_EFI_LOADER) && !defined(CONFIG_PSCI_RESET)
#endif
#if defined(CONFIG_FSL_MC_ENET) && !defined(CONFIG_SPL_BUILD)
#endif
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
#endif
#ifdef CONFIG_TFABOOT
#if defined(CONFIG_FSL_MC_ENET) && !defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_SYS_DDR_BLOCK3_BASE
#endif
#endif	/* CONFIG_FSL_MC_ENET */
#endif
#ifdef CONFIG_SYS_DP_DDR_BASE_PHY
#endif
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
#endif
#ifdef CONFIG_SYS_DDR_BLOCK3_BASE
#endif
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
#endif	/* CONFIG_SYS_MEM_RESERVE_SECURE */
#if defined(CONFIG_FSL_MC_ENET) && !defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_SYS_DDR_BLOCK3_BASE
#endif
#endif	/* CONFIG_FSL_MC_ENET */
#ifdef CONFIG_SYS_DP_DDR_BASE_PHY
#ifdef CONFIG_SYS_DDR_BLOCK3_BASE
#error "This SoC shouldn't have DP DDR"
#endif
#endif
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
#endif
#if CONFIG_IS_ENABLED(EFI_LOADER)
#ifdef CONFIG_SYS_DP_DDR_BASE_PHY
#ifdef CONFIG_SYS_DDR_BLOCK3_BASE
#error "This SoC shouldn't have DP DDR"
#endif
#endif
#ifdef CONFIG_RESV_RAM
#endif
#endif
#ifdef CONFIG_SYS_DDR_BLOCK3_BASE
#ifndef CONFIG_SYS_DDR_BLOCK2_SIZE
#error "Missing CONFIG_SYS_DDR_BLOCK2_SIZE"
#endif
#endif
#if (!defined(CONFIG_SPL) && !defined(CONFIG_TFABOOT)) || \
#endif
