#include <common.h>
#include <dm.h>
#include <power-domain-uclass.h>
#include <asm/io.h>
#include <asm/arch/power-domain.h>
#include <asm/mach-imx/sys_proto.h>
#include <dm/device-internal.h>
#include <dm/device.h>
#include <imx_sip.h>
static int imx8m_power_domain_free(struct power_domain *power_domain)
{
	return 0;
}
