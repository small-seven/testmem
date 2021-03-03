#include "utils/includes.h"
#include "utils/common.h"
#include "hostapd.h"
#include "sta_info.h"
#include "ap_drv_ops.h"
#include "x_snoop.h"
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
void x_snoop_deinit(struct hostapd_data *hapd)
{
	hostapd_drv_br_set_net_param(hapd, DRV_BR_NET_PARAM_GARP_ACCEPT, 0);
	hostapd_drv_br_port_set_attr(hapd, DRV_BR_PORT_ATTR_PROXYARP, 0);
	hostapd_drv_br_port_set_attr(hapd, DRV_BR_PORT_ATTR_HAIRPIN_MODE, 0);
}
