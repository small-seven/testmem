#include "utils/includes.h"
#include "utils/common.h"
#include "common/dhcp.h"
#include "l2_packet/l2_packet.h"
#include "hostapd.h"
#include "sta_info.h"
#include "ap_drv_ops.h"
#include "x_snoop.h"
#include "dhcp_snoop.h"
void dhcp_snoop_deinit(struct hostapd_data *hapd)
{
	l2_packet_deinit(hapd->sock_dhcp);
	hapd->sock_dhcp = NULL;
}
