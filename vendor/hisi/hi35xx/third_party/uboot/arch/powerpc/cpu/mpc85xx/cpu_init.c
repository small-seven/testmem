#include <common.h>
#include <env.h>
#include <init.h>
#include <watchdog.h>
#include <asm/processor.h>
#include <ioports.h>
#include <sata.h>
#include <fm_eth.h>
#include <asm/io.h>
#include <asm/cache.h>
#include <asm/mmu.h>
#include <fsl_errata.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_srio.h>
#ifdef CONFIG_FSL_CORENET
#include <asm/fsl_portals.h>
#include <asm/fsl_liodn.h>
#include <fsl_qbman.h>
#endif
#include <fsl_usb.h>
#include <hwconfig.h>
#include <linux/compiler.h>
#include "mp.h"
#ifdef CONFIG_CHAIN_OF_TRUST
#include <fsl_validate.h>
#endif
#ifdef CONFIG_FSL_CAAM
#include <fsl_sec.h>
#endif
#if defined(CONFIG_NXP_ESBC) && defined(CONFIG_FSL_CORENET)
#include <asm/fsl_pamu.h>
#include <fsl_secboot_err.h>
#endif
#ifdef CONFIG_SYS_QE_FMAN_FW_IN_NAND
#include <nand.h>
#include <errno.h>
#endif
#ifndef CONFIG_ARCH_QEMU_E500
#include <fsl_ddr.h>
#endif
#include "../../../../drivers/ata/fsl_sata.h"
#ifdef CONFIG_U_QE
#include <fsl_qe.h>
#endif
#ifdef CONFIG_SYS_FSL_SINGLE_SOURCE_CLK
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A006261
#ifdef CONFIG_SYS_FSL_USB_DUAL_PHY_ENABLE
#else
#endif
#endif
#if defined(CONFIG_QE) && !defined(CONFIG_U_QE)
#endif
#ifdef CONFIG_CPM2
#endif
#ifdef CONFIG_SYS_FSL_CPC
#if defined(CONFIG_RAMBOOT_PBL) || defined(CONFIG_SYS_CPC_REINIT_F)
#endif
#if defined(T1040_TDM_QUIRK_CCSR_BASE)
#ifdef CONFIG_POST
#error POST memory test cannot be enabled with TDM
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_CPC_A002
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_CPC_A003
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A006593
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A006379
#endif
#else
#define enable_cpc()
#define invalidate_cpc()
#define disable_cpc_sram()
#endif /* CONFIG_SYS_FSL_CPC */
#ifdef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A007212
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 2)
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 3)
#endif
#endif
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 2)
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 3)
#endif
#endif
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 2)
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 3)
#endif
#endif
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 2)
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 3)
#endif
#endif
#endif
#ifdef CONFIG_SYS_DCSRBAR_PHYS
#endif
#if defined(CONFIG_NXP_ESBC) && !defined(CONFIG_SYS_RAMBOOT)
#endif
#ifdef CONFIG_ARCH_MPC8548
#endif
#if defined(CONFIG_NXP_ESBC) && !defined(CONFIG_SYS_RAMBOOT)
#if defined(CONFIG_SYS_CPC_REINIT_F)
#endif
#endif
#ifdef CONFIG_CPM2
#endif
#if defined(CONFIG_CPM2)
#endif
#if defined(CONFIG_QE) && !defined(CONFIG_U_QE)
#endif
#if defined(CONFIG_FSL_DMA)
#endif
#ifdef CONFIG_FSL_CORENET
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A007212
#endif
#if defined(CONFIG_SYS_FSL_QORIQ_CHASSIS2) && defined(CONFIG_E6500)
#endif
#ifdef CONFIG_L2_CACHE
#elif defined(CONFIG_SYS_FSL_QORIQ_CHASSIS2) && defined(CONFIG_E6500)
#endif
#if defined(CONFIG_L2_CACHE)
#if defined(CONFIG_SYS_RAMBOOT) && defined(CONFIG_SYS_INIT_L2_ADDR)
#endif
#if defined(CONFIG_SYS_INIT_L2_ADDR) && defined(CONFIG_SYS_FLASH_BASE)
#endif /* CONFIG_SYS_INIT_L2_ADDR */
#elif defined(CONFIG_BACKSIDE_L2_CACHE)
#ifdef CONFIG_SYS_CACHE_STASHING
#endif
#elif defined(CONFIG_SYS_FSL_QORIQ_CHASSIS2) && defined(CONFIG_E6500)
#else
#endif
#ifdef CONFIG_SYS_LBC_LCRR
#endif
#if defined(CONFIG_PPC_SPINTABLE_COMPATIBLE) && defined(CONFIG_MP)
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_SEC_A003571
#endif
#if defined(CONFIG_SYS_P4080_ERRATUM_CPU22) || \
#ifdef CONFIG_SYS_P4080_ERRATUM_CPU22
#else
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A007907
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A005812
#endif
#if defined(CONFIG_PPC_SPINTABLE_COMPATIBLE) && defined(CONFIG_MP)
#endif
#ifdef CONFIG_FSL_CORENET
#ifdef CONFIG_SYS_DPAA_QBMAN
#endif
#endif
#if defined(CONFIG_RAMBOOT_PBL)
#endif
#if defined(T1040_TDM_QUIRK_CCSR_BASE)
#endif
#ifndef CONFIG_SYS_FSL_NO_SERDES
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_SEC_A003571
#define MCFGR_AXIPIPE 0x000000f0
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A005871
#endif
#ifdef CONFIG_SYS_SRIO
#ifdef CONFIG_SRIO_PCIE_BOOT_MASTER
#endif
#endif
#if defined(CONFIG_MP)
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_ESDHC13
#endif
#ifdef CONFIG_SYS_LBC_LCRR
#ifdef CONFIG_SYS_FSL_ERRATUM_NMG_LBC103
#endif
#endif
#ifdef CONFIG_SYS_FSL_USB1_PHY_ENABLE
#ifdef CONFIG_SYS_FSL_ERRATUM_A006261
#endif
#endif
#ifdef CONFIG_SYS_FSL_USB2_PHY_ENABLE
#ifdef CONFIG_SYS_FSL_ERRATUM_A006261
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_USB14
#endif
#if defined(CONFIG_SYS_FSL_USB_DUAL_PHY_ENABLE)
#ifdef CONFIG_SYS_FSL_SINGLE_SOURCE_CLK
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A006261
#endif
#endif /* CONFIG_SYS_FSL_USB_DUAL_PHY_ENABLE */
#ifdef CONFIG_SYS_FSL_ERRATUM_A009942
#endif
#ifdef CONFIG_FMAN_ENET
#endif
#if defined(CONFIG_NXP_ESBC) && defined(CONFIG_FSL_CORENET)
#endif
#ifdef CONFIG_FSL_CAAM
#if defined(CONFIG_ARCH_C29X)
#endif
#endif
#if defined(CONFIG_FSL_SATA_V2) && defined(CONFIG_SYS_FSL_ERRATUM_SATA_A001)
#endif
#ifdef CONFIG_U_QE
#elif defined CONFIG_QE
#endif
#ifdef CONFIG_QE
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#endif
