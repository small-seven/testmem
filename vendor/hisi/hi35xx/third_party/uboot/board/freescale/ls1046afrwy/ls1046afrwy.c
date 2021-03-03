#include <common.h>
#include <i2c.h>
#include <fdt_support.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/soc.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#include <hwconfig.h>
#include <ahci.h>
#include <mmc.h>
#include <scsi.h>
#include <fm_eth.h>
#include <fsl_csu.h>
#include <fsl_esdhc.h>
#include <fsl_sec.h>
#include <fsl_dspi.h>
#define LS1046A_PORSR1_REG 0x1EE0000
#define BOOT_SRC_SD        0x20000000
#define BOOT_SRC_MASK	   0xFF800000
#define BOARD_REV_GPIO		13
#define USB2_SEL_MASK	   0x00000100
#define BYTE_SWAP_32(word)  ((((word) & 0xff000000) >> 24) |  \
#define SPI_MCR_REG	0x2100000
#ifdef CONFIG_NXP_ESBC
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_HAS_FSL_XHCI_USB
#ifdef CONFIG_HAS_FSL_IIC3
#endif
#ifndef CONFIG_HAS_FSL_IIC3
#endif
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
