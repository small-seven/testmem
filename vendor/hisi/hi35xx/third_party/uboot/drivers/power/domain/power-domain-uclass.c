#include <common.h>
#include <dm.h>
#include <power-domain.h>
#include <power-domain-uclass.h>
#include <dm/device-internal.h>
int power_domain_free(struct power_domain *power_domain)
{
	struct power_domain_ops *ops = power_domain_dev_ops(power_domain->dev);

	debug("%s(power_domain=%p)\n", __func__, power_domain);

	return ops->free(power_domain);
}
#if (CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA))
#endif
