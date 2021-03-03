#include <common.h>
#include <command.h>
#include <env.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/io.h>
#include <asm/fsl_serdes.h>
#include <miiphy.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <tsec.h>
#include <fsl_mdio.h>
#include <netdev.h>
#include "../common/sgmii_riser.h"
#if !defined(CONFIG_SPD_EEPROM)
#if defined (CONFIG_DDR_ECC)
#endif
#if defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_TSEC_ENET
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_TSEC3
#endif
#ifdef CONFIG_TSEC4
#endif
#ifdef CONFIG_FSL_SGMII_RISER
#endif
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_FSL_SGMII_RISER
#endif
#endif
