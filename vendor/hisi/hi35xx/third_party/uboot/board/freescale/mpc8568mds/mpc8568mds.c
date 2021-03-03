#include <common.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <spd_sdram.h>
#include <i2c.h>
#include <ioports.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include "bcsr.h"
#if defined(CONFIG_UEC_ETH1) || defined(CONFIG_UEC_ETH2)
#endif
#if defined(CONFIG_QE) && !defined(CONFIG_eTSEC_MDIO_BUS)
#endif
#ifdef CONFIG_SYS_I2C2_OFFSET
#endif
#if defined(CONFIG_SYS_OR2_PRELIM) && defined(CONFIG_SYS_BR2_PRELIM)
#endif	/* enable SDRAM init */
#if defined(CONFIG_PCI)
#ifndef CONFIG_PCI_PNP
#endif
#endif	/* CONFIG_PCI */
#ifdef CONFIG_PCI
#ifdef CONFIG_PCI1
#ifndef CONFIG_PCI_PNP
#endif
#else
#endif
#endif /* CONFIG_PCI */
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
