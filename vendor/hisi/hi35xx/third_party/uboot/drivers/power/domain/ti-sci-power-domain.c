#include <common.h>
#include <dm.h>
#include <errno.h>
#include <power-domain-uclass.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include <dt-bindings/soc/ti,sci_pm_domain.h>
static int ti_sci_power_domain_free(struct power_domain *pd)
{
	debug("%s(pd=%p)\n", __func__, pd);
	return 0;
}
