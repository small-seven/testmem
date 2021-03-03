#include <common.h>
#include <dm.h>
#include <power-domain.h>
#include <asm/io.h>
#include <asm/power-domain.h>
int sandbox_power_domain_test_free(struct udevice *dev)
{
	struct sandbox_power_domain_test *sbrt = dev_get_priv(dev);

	return power_domain_free(&sbrt->pd);
}
