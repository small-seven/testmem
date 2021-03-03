#include <common.h>
#include <dm.h>
#include <power-domain-uclass.h>
#include <asm/io.h>
#include <asm/arch/power-domain.h>
#include <dm/device-internal.h>
#include <dm/device.h>
#include <asm/arch/sci/sci.h>
static int imx8_power_domain_free(struct power_domain *power_domain)
{
	debug("%s(power_domain=%p)\n", __func__, power_domain);

	return 0;
}
