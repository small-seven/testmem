#include <common.h>
#include <dm.h>
#include <power-domain-uclass.h>
#include <asm/io.h>
#include <asm/power-domain.h>
#define SANDBOX_POWER_DOMAINS 3
static int sandbox_power_domain_free(struct power_domain *power_domain)
{
	debug("%s(power_domain=%p)\n", __func__, power_domain);

	return 0;
}
