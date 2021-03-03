#include <common.h>
#include <command.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/immap_86xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <i2c.h>
#include <asm/io.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <spd_sdram.h>
#include <netdev.h>
#if defined(CONFIG_SPD_EEPROM)
#else
#endif
#if !defined(CONFIG_SPD_EEPROM)
#if !defined(CONFIG_SYS_RAMBOOT)
#if defined(CONFIG_DDR_ECC)
#endif
#if defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#endif
#endif
#if defined(CONFIG_PCI)
#ifndef CONFIG_PCI_PNP
#endif
#endif /* CONFIG_PCI */
#ifdef CONFIG_PCI1
#ifndef CONFIG_PCI_PNP
#endif
#else
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
