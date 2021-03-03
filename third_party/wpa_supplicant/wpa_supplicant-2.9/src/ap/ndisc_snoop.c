#include "utils/includes.h"
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#include "utils/common.h"
#include "l2_packet/l2_packet.h"
#include "hostapd.h"
#include "sta_info.h"
#include "ap_drv_ops.h"
#include "list.h"
#include "x_snoop.h"
#include "ndisc_snoop.h"
#define ROUTER_ADVERTISEMENT	134
#define NEIGHBOR_SOLICITATION	135
#define NEIGHBOR_ADVERTISEMENT	136
#define SOURCE_LL_ADDR		1
void ndisc_snoop_deinit(struct hostapd_data *hapd)
{
	l2_packet_deinit(hapd->sock_ndisc);
	hapd->sock_ndisc = NULL;
}
