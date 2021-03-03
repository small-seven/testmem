#include <common.h>
#include <init.h>
#include <pci.h>
#include <vsprintf.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/immap_85xx.h>
#include <fsl_ddr_sdram.h>
#include <ioports.h>
#include <spd_sdram.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include "../common/cadmus.h"
#include "../common/eeprom.h"
#include "../common/via.h"
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#if defined(CONFIG_SYS_OR2_PRELIM) && defined(CONFIG_SYS_BR2_PRELIM)
#endif	/* enable SDRAM init */
#if defined(CONFIG_PCI)
#ifdef CONFIG_MPC85XX_PCI2
#endif
#endif	/* CONFIG_PCI */
#ifdef CONFIG_PCI
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI1
#endif
#ifdef CONFIG_MPC85XX_PCI2
#endif
#endif
