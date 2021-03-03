#include <common.h>
#include <command.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <asm/io.h>
#include <miiphy.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <netdev.h>
#include "../common/sgmii_riser.h"
#ifdef CONFIG_PCI1
#endif
#ifdef CONFIG_PCIE3
#endif
#ifdef CONFIG_PCIE3
#else
#endif
#ifdef CONFIG_PCIE1
#else
#endif
#ifdef CONFIG_PCIE2
#else
#endif
#ifdef CONFIG_PCI1
#else
#endif
#define MIIM_CIS8204_SLED_CON		0x1b
#define MIIM_CIS8204_SLEDCON_INIT	0x1115
#ifdef CONFIG_TSEC_ENET
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC3
#endif
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_FSL_SGMII_RISER
#endif
#endif
