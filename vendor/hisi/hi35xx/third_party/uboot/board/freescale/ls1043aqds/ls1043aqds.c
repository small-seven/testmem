#include <common.h>
#include <i2c.h>
#include <fdt_support.h>
#include <fsl_ddr_sdram.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/ppa.h>
#include <asm/arch/fdt.h>
#include <asm/arch/mmu.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#include <ahci.h>
#include <hwconfig.h>
#include <mmc.h>
#include <scsi.h>
#include <fm_eth.h>
#include <fsl_esdhc.h>
#include <fsl_ifc.h>
#include <spl.h>
#include "../common/qixis.h"
#include "ls1043aqds_qixis.h"
#define CFG_SD_MUX1_SLOT2	0x0 /* SLOT2 TX/RX0 */
#define CFG_SD_MUX1_SLOT1	0x1 /* SLOT1 TX/RX1 */
#define CFG_SD_MUX2_SLOT3	0x0 /* SLOT3 TX/RX0 */
#define CFG_SD_MUX2_SLOT1	0x1 /* SLOT1 TX/RX2 */
#define CFG_SD_MUX3_SLOT4	0x0 /* SLOT4 TX/RX0 */
#define CFG_SD_MUX3_MUX4	0x1 /* MUX4 */
#define CFG_SD_MUX4_SLOT3	0x0 /* SLOT3 TX/RX1 */
#define CFG_SD_MUX4_SLOT1	0x1 /* SLOT1 TX/RX3 */
#define CFG_UART_MUX_MASK	0x6
#define CFG_UART_MUX_SHIFT	1
#define CFG_LPUART_EN		0x1
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_TFABOOT
#endif
#ifndef CONFIG_SD_BOOT
#endif
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_SD_BOOT
#else
#endif
#ifdef CONFIG_TFABOOT
#endif
#if (!defined(CONFIG_SPL) && !defined(CONFIG_TFABOOT)) || \
#endif
#ifdef CONFIG_HAS_FSL_XHCI_USB
#endif
#ifdef CONFIG_LPUART
#endif
#ifdef CONFIG_SYS_I2C_EARLY_INIT
#endif
#ifdef CONFIG_HAS_FSL_XHCI_USB
#endif
#ifdef CONFIG_LPUART
#endif
#ifdef CONFIG_FSL_DEEP_SLEEP
#define DCFG_CCSR_CRSTSR_WDRFR	(1 << 3)
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A010315
#endif
#ifdef CONFIG_SYS_FSL_SERDES
#endif
#ifdef CONFIG_FSL_LS_PPA
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#endif
#if defined(CONFIG_TFABOOT) && defined(CONFIG_ENV_IS_IN_SPI_FLASH)
#endif
