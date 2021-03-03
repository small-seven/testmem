#include <common.h>
#include <malloc.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/root.h>
#include <errno.h>
#include <reset.h>
#define GPIO_SWPORT_DR(p)	(0x00 + (p) * 0xc)
#define GPIO_SWPORT_DDR(p)	(0x04 + (p) * 0xc)
#define GPIO_INTEN		0x30
#define GPIO_INTMASK		0x34
#define GPIO_INTTYPE_LEVEL	0x38
#define GPIO_INT_POLARITY	0x3c
#define GPIO_INTSTATUS		0x40
#define GPIO_PORTA_DEBOUNCE	0x48
#define GPIO_PORTA_EOI		0x4c
#define GPIO_EXT_PORT(p)	(0x50 + (p) * 4)
static int gpio_dwapb_remove(struct udevice *dev)
{
	struct gpio_dwapb_platdata *plat = dev_get_platdata(dev);
	struct gpio_dwapb_priv *priv = dev_get_priv(dev);

	if (!plat && priv)
		return reset_release_bulk(&priv->resets);

	return 0;
}
