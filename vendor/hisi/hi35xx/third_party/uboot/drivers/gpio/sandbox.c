#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <asm/gpio.h>
#include <dm/of.h>
#include <dt-bindings/gpio/gpio.h>
#define GPIOF_OUTPUT	(1 << 0)	/* Currently set as an output */
#define GPIOF_HIGH	(1 << 1)	/* Currently set high */
#define GPIOF_ODR	(1 << 2)	/* Currently set to open drain mode */
static int gpio_sandbox_remove(struct udevice *dev)
{
	free(dev->priv);

	return 0;
}
