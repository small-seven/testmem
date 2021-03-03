#include <common.h>
#include <init.h>
#include <pci.h>
#include <vsprintf.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <miiphy.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <tsec.h>
#include <fsl_mdio.h>
#include <netdev.h>
#include "../common/cadmus.h"
#include "../common/eeprom.h"
#include "../common/via.h"
#if defined(CONFIG_SYS_OR2_PRELIM) && defined(CONFIG_SYS_BR2_PRELIM)
#endif	/* enable SDRAM init */
#if (defined(CONFIG_PCI) || defined(CONFIG_PCI1)) && !defined(CONFIG_DM_PCI)
#endif	/* CONFIG_PCI */
#if !defined(CONFIG_DM_PCI)
#ifdef CONFIG_PCI1
#ifdef CONFIG_PCIX_CHECK
#endif
#else
#endif
#ifdef CONFIG_PCI2
#else
#endif /* CONFIG_PCI2 */
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
#endif
#if defined(CONFIG_OF_BOARD_SETUP) && !defined(CONFIG_DM_PCI)
#endif
