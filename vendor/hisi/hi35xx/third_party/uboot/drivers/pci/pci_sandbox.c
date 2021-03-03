#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <pci.h>
#define FDT_DEV_INFO_CELLS	4
#define FDT_DEV_INFO_SIZE	(FDT_DEV_INFO_CELLS * sizeof(u32))
#define SANDBOX_PCI_DEVFN(d, f)	((d << 3) | f)
