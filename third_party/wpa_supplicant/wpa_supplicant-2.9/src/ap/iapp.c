#include "utils/includes.h"
#include <net/if.h>
#include <sys/ioctl.h>
#include <netpacket/packet.h>
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "hostapd.h"
#include "ap_config.h"
#include "ieee802_11.h"
#include "sta_info.h"
#include "iapp.h"
#define IAPP_MULTICAST "224.0.1.178"
#define IAPP_UDP_PORT 3517
#define IAPP_TCP_PORT 3517
#define IAPP_VERSION 0
void iapp_deinit(struct iapp_data *iapp)
{
	struct ip_mreqn mreq;

	if (iapp == NULL)
		return;

	if (iapp->udp_sock >= 0) {
		os_memset(&mreq, 0, sizeof(mreq));
		mreq.imr_multiaddr = iapp->multicast;
		mreq.imr_address.s_addr = INADDR_ANY;
		mreq.imr_ifindex = 0;
		if (setsockopt(iapp->udp_sock, SOL_IP, IP_DROP_MEMBERSHIP,
			       &mreq, sizeof(mreq)) < 0) {
			wpa_printf(MSG_INFO, "iapp_deinit - setsockopt[UDP,IP_DEL_MEMBERSHIP]: %s",
				   strerror(errno));
		}

		eloop_unregister_read_sock(iapp->udp_sock);
		close(iapp->udp_sock);
	}
	if (iapp->packet_sock >= 0) {
		eloop_unregister_read_sock(iapp->packet_sock);
		close(iapp->packet_sock);
	}
	os_free(iapp);
}
