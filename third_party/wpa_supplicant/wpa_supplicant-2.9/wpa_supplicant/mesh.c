#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/uuid.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "ap/sta_info.h"
#include "ap/hostapd.h"
#include "ap/ieee802_11.h"
#include "config_ssid.h"
#include "config.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "notify.h"
#include "ap.h"
#include "mesh_mpm.h"
#include "mesh_rsn.h"
#include "mesh.h"
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
int wpas_mesh_peer_remove(struct wpa_supplicant *wpa_s, const u8 *addr)
{
	return mesh_mpm_close_peer(wpa_s, addr);
}
