#include <common.h>
#include <dm.h>
#include <misc.h>
#include <power-domain-uclass.h>
#include <asm/arch-tegra/bpmp_abi.h>
#define UPDATE	BIT(0)
#define ON	BIT(1)
static int tegra186_power_domain_free(struct power_domain *power_domain)
{
	debug("%s(power_domain=%p) (dev=%p, id=%lu)\n", __func__,
	      power_domain, power_domain->dev, power_domain->id);

	return 0;
}
