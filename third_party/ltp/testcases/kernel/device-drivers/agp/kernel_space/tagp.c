#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/module.h>
#include <linux/init.h>
#include <asm/uaccess.h>
#include <linux/pci.h>
#include <linux/agp_backend.h>
#include <linux/gfp.h>
#include <linux/page-flags.h>
#include <linux/mm.h>
#include "tagp.h"
#include "str_agp.h"
static void __devexit agp_test_remove(struct pci_dev *pdev)
{
	printk("<1> tagp: Enter agp test remove\n");
	struct agp_bridge_data *bridge = pci_get_drvdata(pdev);

	agp_remove_bridge(bridge);
	agp_put_bridge(bridge);
}
