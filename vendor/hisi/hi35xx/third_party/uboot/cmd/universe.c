#include <common.h>
#include <command.h>
#include <malloc.h>
#include <asm/io.h>
#include <pci.h>
#include <universe.h>
#define PCI_VENDOR PCI_VENDOR_ID_TUNDRA
#define PCI_DEVICE PCI_DEVICE_ID_TUNDRA_CA91C042
typedef struct _UNI_DEV UNI_DEV;

struct _UNI_DEV {
	int            bus;
	pci_dev_t      busdevfn;
	UNIVERSE       *uregs;
	unsigned int   pci_bs;
};
