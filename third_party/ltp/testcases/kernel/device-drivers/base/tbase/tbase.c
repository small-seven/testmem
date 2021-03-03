#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/pci.h>
#include <linux/sysdev.h>
#include <asm/uaccess.h>
#include "tbase.h"
#include "str_mod.h"
int test_dev_remove(struct device *dev)
{
	printk("tbase: Entered test_dev_remove\n");
	return 0;
}
