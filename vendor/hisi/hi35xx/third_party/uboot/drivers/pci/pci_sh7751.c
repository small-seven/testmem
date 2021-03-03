#include <common.h>
#include <dm.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <asm/pci.h>
#define SH7751_BCR1	(vu_long *)0xFF800000
#define SH7751_BCR2	(vu_short *)0xFF800004
#define SH7751_WCR1	(vu_long *)0xFF800008
#define SH7751_WCR2	(vu_long *)0xFF80000C
#define SH7751_WCR3	(vu_long *)0xFF800010
#define SH7751_MCR	(vu_long *)0xFF800014
#define SH7751_BCR3	(vu_short *)0xFF800050
#define SH7751_PCICONF0	(vu_long *)0xFE200000
#define SH7751_PCICONF1	(vu_long *)0xFE200004
#define SH7751_PCICONF2	(vu_long *)0xFE200008
#define SH7751_PCICONF3	(vu_long *)0xFE20000C
#define SH7751_PCICONF4	(vu_long *)0xFE200010
#define SH7751_PCICONF5	(vu_long *)0xFE200014
#define SH7751_PCICONF6	(vu_long *)0xFE200018
#define SH7751_PCICR	(vu_long *)0xFE200100
#define SH7751_PCILSR0	(vu_long *)0xFE200104
#define SH7751_PCILSR1	(vu_long *)0xFE200108
#define SH7751_PCILAR0	(vu_long *)0xFE20010C
#define SH7751_PCILAR1	(vu_long *)0xFE200110
#define SH7751_PCIMBR	(vu_long *)0xFE2001C4
#define SH7751_PCIIOBR	(vu_long *)0xFE2001C8
#define SH7751_PCIPINT	(vu_long *)0xFE2001CC
#define SH7751_PCIPINTM	(vu_long *)0xFE2001D0
#define SH7751_PCICLKR	(vu_long *)0xFE2001D4
#define SH7751_PCIBCR1	(vu_long *)0xFE2001E0
#define SH7751_PCIBCR2	(vu_long *)0xFE2001E4
#define SH7751_PCIWCR1	(vu_long *)0xFE2001E8
#define SH7751_PCIWCR2	(vu_long *)0xFE2001EC
#define SH7751_PCIWCR3	(vu_long *)0xFE2001F0
#define SH7751_PCIMCR	(vu_long *)0xFE2001F4
#define SH7751_PCIBCR3	(vu_long *)0xFE2001F8
#define BCR1_BREQEN		0x00080000
#define PCI_SH7751_ID		0x35051054
#define PCI_SH7751R_ID		0x350E1054
#define SH7751_PCICONF1_WCC	0x00000080
#define SH7751_PCICONF1_PER	0x00000040
#define SH7751_PCICONF1_BUM	0x00000004
#define SH7751_PCICONF1_MES	0x00000002
#define SH7751_PCICONF1_CMDS	0x000000C6
#define SH7751_PCI_HOST_BRIDGE	0x6
#define SH7751_PCICR_PREFIX	0xa5000000
#define SH7751_PCICR_PRST	0x00000002
#define SH7751_PCICR_CFIN	0x00000001
#define SH7751_PCIPINT_D3	0x00000002
#define SH7751_PCIPINT_D0	0x00000001
#define SH7751_PCICLKR_PREFIX	0xa5000000
#define SH7751_PCI_MEM_BASE	0xFD000000
#define SH7751_PCI_MEM_SIZE	0x01000000
#define SH7751_PCI_IO_BASE	0xFE240000
#define SH7751_PCI_IO_SIZE	0x00040000
#define SH7751_PCIPAR	(vu_long *)0xFE2001C0
#define SH7751_PCIPDR	(vu_long *)0xFE200220
#define p4_in(addr)	(*addr)
#define p4_out(data, addr) (*addr) = (data)
