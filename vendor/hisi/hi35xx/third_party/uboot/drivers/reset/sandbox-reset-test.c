#include <common.h>
#include <dm.h>
#include <reset.h>
#include <asm/io.h>
#include <asm/reset.h>
int sandbox_reset_test_free(struct udevice *dev)
{
	struct sandbox_reset_test *sbrt = dev_get_priv(dev);

	return reset_free(&sbrt->ctl);
}
