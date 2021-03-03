#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/dhcp.h"
#include "hostapd.h"
#include "sta_info.h"
#include "ieee802_11.h"
#include "fils_hlp.h"
void fils_hlp_deinit(struct hostapd_data *hapd)
{
	if (hapd->dhcp_sock >= 0) {
		eloop_unregister_read_sock(hapd->dhcp_sock);
		close(hapd->dhcp_sock);
		hapd->dhcp_sock = -1;
	}
}
