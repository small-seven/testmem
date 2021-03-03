#include "utils/includes.h"
#include "utils/common.h"
#include "hostapd.h"
#include "ap_config.h"
#include "ap_drv_ops.h"
#include "wpa_auth.h"
#include "vlan_init.h"
#include "vlan_util.h"
int vlan_if_remove(struct hostapd_data *hapd, struct hostapd_vlan *vlan)
{
	int ret;

	ret = wpa_auth_release_group(hapd->wpa_auth, vlan->vlan_id);
	if (ret)
		wpa_printf(MSG_ERROR,
			   "WPA deinitialization for VLAN %d failed (%d)",
			   vlan->vlan_id, ret);

	return hostapd_vlan_if_remove(hapd, vlan->ifname);
}
#ifdef CONFIG_FULL_DYNAMIC_VLAN
#endif /* CONFIG_FULL_DYNAMIC_VLAN */
static void vlan_dynamic_remove(struct hostapd_data *hapd,
				struct hostapd_vlan *vlan)
{
	struct hostapd_vlan *next;

	while (vlan) {
		next = vlan->next;

#ifdef CONFIG_FULL_DYNAMIC_VLAN
		/* vlan_dellink() takes care of cleanup and interface removal */
		if (vlan->vlan_id != VLAN_ID_WILDCARD)
			vlan_dellink(vlan->ifname, hapd);
#else /* CONFIG_FULL_DYNAMIC_VLAN */
		if (vlan->vlan_id != VLAN_ID_WILDCARD &&
		    vlan_if_remove(hapd, vlan)) {
			wpa_printf(MSG_ERROR, "VLAN: Could not remove VLAN "
				   "iface: %s: %s",
				   vlan->ifname, strerror(errno));
		}
#endif /* CONFIG_FULL_DYNAMIC_VLAN */

		vlan = next;
	}
}
#ifdef CONFIG_FULL_DYNAMIC_VLAN
#endif /* CONFIG_FULL_DYNAMIC_VLAN */
#ifdef CONFIG_FULL_DYNAMIC_VLAN
#endif /* CONFIG_FULL_DYNAMIC_VLAN */
#ifdef CONFIG_FULL_DYNAMIC_VLAN
#endif /* CONFIG_FULL_DYNAMIC_VLAN */
