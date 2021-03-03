#include <common.h>
#include <dm.h>
#include <errno.h>
#include <i2c.h>
#include <malloc.h>
#include <asm/test.h>
#ifdef DEBUG
#define debug_buffer print_buffer
#else
#define debug_buffer(x, ...)
#endif
static int sandbox_i2c_eeprom_remove(struct udevice *dev)
{
	struct sandbox_i2c_flash *priv = dev_get_priv(dev);

	free(priv->data);

	return 0;
}
