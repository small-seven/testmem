#include <common.h>
#include <dm.h>
#include <errno.h>
#include <pci.h>
#include <asm/test.h>
#include <linux/ctype.h>
#define PCI_CAP_ID_EA_SIZE		(sizeof(ea_regs) + 4)
#define PCI_CAP_ID_EA_ENTRY_CNT		4
