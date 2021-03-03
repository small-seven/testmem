#include <common.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <spd_sdram.h>
#include <netdev.h>
#include <tsec.h>
#include <miiphy.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#if defined(CONFIG_SYS_LBC_SDRAM_SIZE)
#endif	/* enable SDRAM init */
#if defined(CONFIG_SYS_DRAM_TEST)
#endif
#ifdef CONFIG_PCI1
#endif	/* CONFIG_PCI1 */
#ifdef CONFIG_PCI
#ifdef CONFIG_PCI1
#else
#endif
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_FSL_PCI_INIT
#endif
#endif
