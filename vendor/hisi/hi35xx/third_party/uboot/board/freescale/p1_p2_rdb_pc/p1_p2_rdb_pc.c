#include <common.h>
#include <command.h>
#include <env.h>
#include <hwconfig.h>
#include <init.h>
#include <pci.h>
#include <i2c.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/io.h>
#include <asm/fsl_law.h>
#include <asm/fsl_lbc.h>
#include <asm/mp.h>
#include <miiphy.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <vsc7385.h>
#include <ioports.h>
#include <asm/fsl_serdes.h>
#include <netdev.h>
#ifdef CONFIG_QE
#define GPIO_GETH_SW_PORT	1
#define GPIO_GETH_SW_PIN	29
#define GPIO_GETH_SW_DATA	(1 << (31 - GPIO_GETH_SW_PIN))
#define GPIO_SLIC_PORT		1
#define GPIO_SLIC_PIN		30
#define GPIO_SLIC_DATA		(1 << (31 - GPIO_SLIC_PIN))
#if defined(CONFIG_TARGET_P1021RDB) && !defined(CONFIG_SYS_RAMBOOT)
#define GPIO_DDR_RST_PORT	1
#define GPIO_DDR_RST_PIN	8
#define GPIO_DDR_RST_DATA	(1 << (31 - GPIO_DDR_RST_PIN))
#define GPIO_2BIT_MASK		(0x3 << (32 - (GPIO_DDR_RST_PIN + 1) * 2))
#endif
#if defined(CONFIG_TARGET_P1025RDB) || defined(CONFIG_TARGET_P1021RDB)
#define PCA_IOPORT_I2C_ADDR		0x23
#define PCA_IOPORT_OUTPUT_CMD		0x2
#define PCA_IOPORT_CFG_CMD		0x6
#define PCA_IOPORT_QE_PIN_ENABLE	0xf8
#define PCA_IOPORT_QE_TDM_ENABLE	0xf6
#endif
#if defined(CONFIG_TARGET_P1021RDB) && !defined(CONFIG_SYS_RAMBOOT)
#endif
#ifdef CONFIG_TARGET_P1025RDB
#endif
#endif
#define CPLD_WD_CFG	0x03
#define CPLD_RST_BSW	0x00
#define CPLD_RST_BWD	0x00
#define CPLD_BYPASS_EN	0x03
#define CPLD_STATUS_LED	0x01
#define CPLD_FXO_LED	0x01
#define CPLD_FXS_LED	0x0F
#define CPLD_SYS_RST	0x00
#ifdef CONFIG_QE
#if defined(CONFIG_TARGET_P1021RDB) && !defined(CONFIG_SYS_RAMBOOT)
#endif
#else
#if !defined(CONFIG_SYS_RAMBOOT) && !defined(CONFIG_SPL)
#endif
#ifdef CONFIG_VSC7385_ENET
#endif
#ifdef CONFIG_SLIC
#endif
#endif
#ifdef __SW_BOOT_SPI
#endif
#ifdef __SW_BOOT_NAND
#endif
#ifdef __SW_BOOT_PCIE
#endif
#if defined(CONFIG_PCI) && !defined(CONFIG_DM_PCI)
#endif
#ifdef CONFIG_VSC7385_ENET
#endif
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_TSEC3
#endif
#ifdef CONFIG_VSC7385_ENET
#endif
#if defined(CONFIG_UEC_ETH)
#endif
#if defined(CONFIG_QE) && \
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#if defined(CONFIG_TARGET_P1020RDB_PD) || defined(CONFIG_TARGET_P1020RDB_PC)
#endif
#if defined(CONFIG_SDCARD) || defined(CONFIG_SPIFLASH)
#endif
#if !defined(CONFIG_DM_PCI)
#endif
#ifdef CONFIG_QE
#if defined(CONFIG_TARGET_P1025RDB) || defined(CONFIG_TARGET_P1021RDB)
#endif
#endif
#if defined(CONFIG_HAS_FSL_DR_USB)
#endif
#if defined(CONFIG_SDCARD) || defined(CONFIG_SPIFLASH)
#endif
#if defined(CONFIG_TARGET_P1020RDB_PD) || defined(CONFIG_TARGET_P1020RDB_PC)
#endif
#endif
