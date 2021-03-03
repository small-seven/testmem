#include <common.h>
#include <init.h>
#include <pci.h>
#include <asm/io.h>
#include "integrator-sc.h"
#include "pci_v3.h"
#define INTEGRATOR_BOOT_ROM_BASE	0x20000000
#define INTEGRATOR_HDR0_SDRAM_BASE	0x80000000
#define PHYS_PCI_MEM_BASE	0x40000000
#define PHYS_PCI_IO_BASE	0x60000000	/* PCI I/O space base */
#define PHYS_PCI_CONFIG_BASE	0x61000000
#define PHYS_PCI_V3_BASE	0x62000000	/* V360EPC registers */
#define SZ_256M			0x10000000
#define PCI_BUS_NONMEM_START	0x00000000
#define PCI_BUS_NONMEM_SIZE	SZ_256M
#define PCI_BUS_PREMEM_START	(PCI_BUS_NONMEM_START + PCI_BUS_NONMEM_SIZE)
#define PCI_BUS_PREMEM_SIZE	SZ_256M
#if PCI_BUS_NONMEM_START & 0x000fffff
#error PCI_BUS_NONMEM_START must be megabyte aligned
#endif
#if PCI_BUS_PREMEM_START & 0x000fffff
#error PCI_BUS_PREMEM_START must be megabyte aligned
#endif
#ifndef CONFIG_PCI_PNP
#define PCI_ENET0_IOADDR	0x60000000 /* First card in PCI I/O space */
#define PCI_ENET0_MEMADDR	0x40000000 /* First card in PCI memory space */
#endif /* CONFIG_PCI_PNP */
#define v3_writeb(o, v) __raw_writeb(v, PHYS_PCI_V3_BASE + (unsigned int)(o))
#define v3_readb(o)    (__raw_readb(PHYS_PCI_V3_BASE + (unsigned int)(o)))
#define v3_writew(o, v) __raw_writew(v, PHYS_PCI_V3_BASE + (unsigned int)(o))
#define v3_readw(o)    (__raw_readw(PHYS_PCI_V3_BASE + (unsigned int)(o)))
#define v3_writel(o, v) __raw_writel(v, PHYS_PCI_V3_BASE + (unsigned int)(o))
#define v3_readl(o)    (__raw_readl(PHYS_PCI_V3_BASE + (unsigned int)(o)))
#ifndef CONFIG_PCI_PNP
#endif
