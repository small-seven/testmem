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
#include <ioports.h>
#include <asm/fsl_serdes.h>
#include <netdev.h>
#define SYSCLK_64	64000000
#define SYSCLK_66	66666666
#ifdef CONFIG_QE
#define PCA_IOPORT_I2C_ADDR		0x23
#define PCA_IOPORT_OUTPUT_CMD		0x2
#define PCA_IOPORT_CFG_CMD		0x6
#ifdef CONFIG_TWR_P1025
#endif
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_TSEC3
#endif
#if defined(CONFIG_UEC_ETH)
#endif
#if defined(CONFIG_QE)
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_QE
#endif
#if defined(CONFIG_TWR_P1025)
#endif
#endif
