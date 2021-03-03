#include "includes.h"
#include <sys/ioctl.h>
#include "linux_wext.h"
#include "common.h"
#include "driver.h"
#include "driver_wext.h"
#include "eloop.h"
#include "driver_hostap.h"
#include <net/if_arp.h>
#include <netpacket/packet.h>
#include "priv_netlink.h"
#include "netlink.h"
#include "linux_ioctl.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#define HOSTAPD_MTU 2290
#define WLAN_RATE_1M BIT(0)
#define WLAN_RATE_2M BIT(1)
#define WLAN_RATE_5M5 BIT(2)
#define WLAN_RATE_11M BIT(3)
static int hostap_sta_remove(void *priv, const u8 *addr)
{
	struct hostap_driver_data *drv = priv;
	struct prism2_hostapd_param param;

	hostap_sta_set_flags(drv, addr, 0, 0, ~WPA_STA_AUTHORIZED);

	memset(&param, 0, sizeof(param));
	param.cmd = PRISM2_HOSTAPD_REMOVE_STA;
	memcpy(param.sta_addr, addr, ETH_ALEN);
	if (hostapd_ioctl(drv, &param, sizeof(param))) {
		printf("Could not remove station from kernel driver.\n");
		return -1;
	}
	return 0;
}
