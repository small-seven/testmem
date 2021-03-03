#include <common.h>
#include <init.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/io.h>
#include <env.h>
#include <miiphy.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <mmc.h>
#include <netdev.h>
#include <pci.h>
#include <asm/fsl_serdes.h>
#include <fsl_ifc.h>
#include <asm/fsl_pci.h>
#include <hwconfig.h>
#include <i2c.h>
#define GPIO4_PCIE_RESET_SET		0x08000000
#define MUX_CPLD_CAN_UART		0x00
#define MUX_CPLD_TDM			0x01
#define MUX_CPLD_SPICS0_FLASH		0x00
#define MUX_CPLD_SPICS0_SLIC		0x02
#define PMUXCR1_IFC_MASK       0x00ffff00
#define PMUXCR1_SDHC_MASK      0x00fff000
#define PMUXCR1_SDHC_ENABLE    0x00555000
#if defined(CONFIG_TARGET_P1010RDB_PA)
#elif defined(CONFIG_TARGET_P1010RDB_PB)
#endif
#ifdef CONFIG_PCI
#endif /* ifdef CONFIG_PCI */
#if defined(CONFIG_TARGET_P1010RDB_PA)
#elif defined(CONFIG_TARGET_P1010RDB_PB)
#endif
#ifdef CONFIG_TARGET_P1010RDB_PB
#endif
#if defined(CONFIG_TARGET_P1010RDB_PA)
#elif defined(CONFIG_TARGET_P1010RDB_PB)
#endif
#ifdef CONFIG_SDCARD
#endif
#if defined(CONFIG_TARGET_P1010RDB_PA)
#elif defined(CONFIG_TARGET_P1010RDB_PB)
#endif
#ifdef CONFIG_TSEC_ENET
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_TSEC3
#endif
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#if defined(CONFIG_PCI)
#endif
#if defined(CONFIG_HAS_FSL_DR_USB)
#endif
#endif
#ifdef CONFIG_SDCARD
#else
#endif
#ifdef CONFIG_TARGET_P1010RDB_PB
#endif
#ifndef CONFIG_SPL_BUILD
#endif
