#include <common.h>
#include <env.h>
#include <fsl_immap.h>
#include <fsl_ifc.h>
#include <init.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/soc.h>
#include <asm/io.h>
#include <asm/global_data.h>
#include <asm/arch-fsl-layerscape/config.h>
#include <asm/arch-fsl-layerscape/ns_access.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#ifdef CONFIG_LAYERSCAPE_NS_ACCESS
#include <fsl_csu.h>
#endif
#ifdef CONFIG_SYS_FSL_DDR
#include <fsl_ddr_sdram.h>
#include <fsl_ddr.h>
#endif
#ifdef CONFIG_CHAIN_OF_TRUST
#include <fsl_validate.h>
#endif
#include <fsl_immap.h>
#ifdef CONFIG_TFABOOT
#include <env_internal.h>
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009008
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A) || \
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#endif
#elif defined(CONFIG_ARCH_LS2080A)
#endif
#endif /* CONFIG_SYS_FSL_ERRATUM_A009008 */
#ifdef CONFIG_SYS_FSL_ERRATUM_A009798
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A) || \
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#endif
#elif defined(CONFIG_ARCH_LS2080A)
#endif
#endif /* CONFIG_SYS_FSL_ERRATUM_A009798 */
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A) || \
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A008997
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A) || \
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#endif
#elif defined(CONFIG_ARCH_LS1028A)
#endif
#endif /* CONFIG_SYS_FSL_ERRATUM_A008997 */
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A) || \
#define PROGRAM_USB_PHY_RX_OVRD_IN_HI(phy)	\
#elif defined(CONFIG_ARCH_LS2080A) || defined(CONFIG_ARCH_LS1088A) || \
#define PROGRAM_USB_PHY_RX_OVRD_IN_HI(phy)	\
#endif
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A) || \
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#endif
#elif defined(CONFIG_ARCH_LS2080A) || defined(CONFIG_ARCH_LS1088A) || \
#endif /* CONFIG_SYS_FSL_ERRATUM_A009007 */
#if defined(CONFIG_FSL_LSCH3)
#ifdef CONFIG_SYS_FSL_ERRATUM_A008336
#ifdef CONFIG_SYS_FSL_DCSR_DDR_ADDR
#endif
#ifdef CONFIG_SYS_FSL_DCSR_DDR2_ADDR
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A008514
#ifdef CONFIG_SYS_FSL_DCSR_DDR3_ADDR
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009635
#define PLATFORM_CYCLE_ENV_VAR	"a009635_interval_val"
#endif	/* CONFIG_SYS_FSL_ERRATUM_A009635 */
#if defined(CONFIG_SPL) && defined(CONFIG_NAND_BOOT)
#endif
#define I2C_DEBUG_REG 0x6
#define I2C_GLITCH_EN 0x8
#ifdef CONFIG_SYS_FSL_ERRATUM_A009203
#ifdef CONFIG_SYS_I2C
#ifdef I2C1_BASE_ADDR
#endif
#ifdef I2C2_BASE_ADDR
#endif
#ifdef I2C3_BASE_ADDR
#endif
#ifdef I2C4_BASE_ADDR
#endif
#endif
#endif
#ifdef CONFIG_FSL_IFC
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009203
#endif
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#if defined(CONFIG_ARCH_LS1088A) || defined(CONFIG_ARCH_LS1028A) || \
#endif
#elif defined(CONFIG_FSL_LSCH2)
#ifdef CONFIG_SYS_FSL_ERRATUM_A009929
#endif
#if defined(CONFIG_SYS_FSL_ERRATUM_A009660) \
#error A009660 and A008514 can not be both enabled.
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009660
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A008850
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A008850
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A010315
#endif
#if defined(CONFIG_SYS_FSL_ERRATUM_A010539) && defined(CONFIG_QSPI_BOOT)
#endif
#ifdef CONFIG_SYS_FSL_DDR
#endif
#ifdef CONFIG_SYS_HAS_SERDES
#endif
#ifdef CONFIG_SYS_FSL_DDR
#endif
#ifdef CONFIG_FSL_PFE
#endif
#if defined(CONFIG_FSL_QSPI) && defined(CONFIG_TFABOOT)
#endif
#ifdef CONFIG_LAYERSCAPE_NS_ACCESS
#endif
#ifdef CONFIG_FSL_IFC
#endif
#if defined(CONFIG_FSL_QSPI) && defined(CONFIG_TFABOOT)
#else
#if defined(CONFIG_FSL_QSPI) && !defined(CONFIG_QSPI_BOOT)
#endif
#endif
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#else
#endif
#if defined(CONFIG_ARCH_LS1012A) && defined(CONFIG_USB_EHCI_FSL)
#endif
#if defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#endif
#endif
#ifdef CONFIG_QSPI_AHB_INIT
#endif
#ifdef CONFIG_TFABOOT
#define MAX_BOOTCMD_SIZE	512
#ifdef IFC_NOR_BOOTCOMMAND
#endif
#ifdef QSPI_NOR_BOOTCOMMAND
#endif
#ifdef XSPI_NOR_BOOTCOMMAND
#endif
#ifdef IFC_NAND_BOOTCOMMAND
#endif
#ifdef QSPI_NAND_BOOTCOMMAND
#endif
#ifdef XSPI_NAND_BOOTCOMMAND
#endif
#ifdef SD_BOOTCOMMAND
#endif
#ifdef SD2_BOOTCOMMAND
#endif
#ifdef QSPI_NOR_BOOTCOMMAND
#endif
#ifdef IFC_MC_INIT_CMD
#endif
#ifdef QSPI_MC_INIT_CMD
#endif
#ifdef XSPI_MC_INIT_CMD
#endif
#ifdef SD_MC_INIT_CMD
#endif
#ifdef SD2_MC_INIT_CMD
#endif
#ifdef QSPI_MC_INIT_CMD
#endif
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#ifdef CONFIG_TFABOOT
#ifdef CONFIG_SYS_RELOC_GD_ENV_ADDR
#else
#endif
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#endif
#ifdef CONFIG_QSPI_AHB_INIT
#endif
#endif
