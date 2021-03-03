#include "includes.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <netpacket/packet.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <netlink/netlink.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/ctrl.h>
#include <netlink/route/link.h>
#include <netlink/route/link/macsec.h>
#include <linux/if_macsec.h>
#include <inttypes.h>
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/eapol_common.h"
#include "pae/ieee802_1x_kay.h"
#include "driver.h"
#include "driver_wired_common.h"
#define DRV_PREFIX "macsec_linux: "
#define UNUSED_SCI 0xffffffffffffffff
static void macsec_drv_wpa_deinit(void *priv)
{
	struct macsec_drv_data *drv = priv;

	driver_wired_deinit_common(&drv->common);
	os_free(drv);
}
#define SCISTR MACSTR "::%hx"
#define SCI2STR(addr, port) MAC2STR(addr), htons(port)
#ifdef __linux__
#ifdef HOSTAPD
#endif /* HOSTAPD */
#endif /* __linux__ */
#ifdef __linux__
#else /* __linux__ */
#endif /* __linux__ */
