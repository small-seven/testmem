#include <common.h>
#include <dm.h>
#include <power-domain-uclass.h>
#include <asm/io.h>
#define MAX_DOMAINS	32
static int bcm6328_power_domain_free(struct power_domain *power_domain)
{
	return 0;
}
