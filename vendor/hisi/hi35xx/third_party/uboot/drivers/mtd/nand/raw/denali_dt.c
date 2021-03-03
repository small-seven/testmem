#include <clk.h>
#include <dm.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/printk.h>
#include "denali.h"
static int denali_dt_remove(struct udevice *dev)
{
	struct denali_nand_info *denali = dev_get_priv(dev);

	return reset_release_bulk(&denali->resets);
}
