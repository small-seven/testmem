#include <common.h>
#include <command.h>
#include <malloc.h>
#include <asm/io.h>
#include <pci.h>
#include <tsi148.h>
#define LPCI_VENDOR PCI_VENDOR_ID_TUNDRA
#define LPCI_DEVICE PCI_DEVICE_ID_TUNDRA_TSI148
typedef struct _TSI148_DEV TSI148_DEV;

struct _TSI148_DEV {
	int           bus;
	pci_dev_t     busdevfn;
	TSI148       *uregs;
	unsigned int  pci_bs;
};
#ifdef DEBUG
#endif
