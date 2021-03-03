#include <common.h>
#include <gt64120.h>
#include <pci.h>
#include <pci_gt64120.h>
#include <asm/io.h>
#define PCI_ACCESS_READ  0
#define PCI_ACCESS_WRITE 1
#define GT_INTRCAUSE_ABORT_BITS	\
