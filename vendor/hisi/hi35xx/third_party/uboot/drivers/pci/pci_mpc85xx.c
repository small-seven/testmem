#include <common.h>
#include <asm/cpm_85xx.h>
#include <pci.h>
#include <dm.h>
#include <asm/fsl_law.h>
static int mpc85xx_pci_dm_remove(struct udevice *dev)
{
	return 0;
}
