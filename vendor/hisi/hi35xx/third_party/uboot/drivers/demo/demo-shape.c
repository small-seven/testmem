#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <dm-demo.h>
#include <asm/io.h>
#include <asm/gpio.h>
#define WIDTH	8
#define HEIGHT	6
static int dm_shape_remove(struct udevice *dev)
{
	struct shape_data *priv = dev_get_priv(dev);

	return gpio_free_list(dev, priv->gpio_desc, priv->gpio_count);
}
