#include "includes.h"
#include <sys/types.h>
#include <fcntl.h>
#include <net/if.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/ctrl.h>
#ifdef CONFIG_LIBNL3_ROUTE
#include <netlink/route/neighbour.h>
#endif /* CONFIG_LIBNL3_ROUTE */
#include <linux/rtnetlink.h>
#include <netpacket/packet.h>
#include <linux/errqueue.h>
#include "common.h"
#include "eloop.h"
#include "common/qca-vendor.h"
#include "common/qca-vendor-attr.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/wpa_common.h"
#include "l2_packet/l2_packet.h"
#include "netlink.h"
#include "linux_defines.h"
#include "linux_ioctl.h"
#include "radiotap.h"
#include "radiotap_iter.h"
#include "rfkill.h"
#include "driver_nl80211.h"
#ifndef NETLINK_CAP_ACK
#define NETLINK_CAP_ACK 10
#endif /* NETLINK_CAP_ACK */
#ifndef NETLINK_EXT_ACK
#define NETLINK_EXT_ACK 11
#endif
#ifndef NLM_F_CAPPED
#define NLM_F_CAPPED 0x100
#endif
#ifndef NLM_F_ACK_TLVS
#define NLM_F_ACK_TLVS 0x200
#endif
#ifndef SOL_NETLINK
#define SOL_NETLINK 270
#endif
#ifndef CONFIG_LIBNL20
static void nl80211_handle_destroy(struct nl_handle *handle)
{
	uint32_t port = nl_socket_get_local_port(handle);

	port >>= 22;
	port_bitmap[port / 32] &= ~(1 << (port % 32));

	nl_handle_destroy(handle);
}
#endif /* CONFIG_LIBNL20 */
#ifdef ANDROID
#undef nl_socket_set_nonblocking
#define nl_socket_set_nonblocking(h) android_nl_socket_set_nonblocking(h)
#endif /* ANDROID */
#if __WORDSIZE == 64
#define ELOOP_SOCKET_INVALID	(intptr_t) 0x8888888888888889ULL
#else
#define ELOOP_SOCKET_INVALID	(intptr_t) 0x88888889ULL
#endif
#ifdef CONFIG_LIBNL20
#endif /* CONFIG_LIBNL20 */
#define IFIDX_ANY -1
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#if defined(CONFIG_P2P) || defined(CONFIG_INTERWORKING) || defined(CONFIG_DPP)
#endif /* CONFIG_P2P || CONFIG_INTERWORKING || CONFIG_DPP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_IEEE80211W
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DRIVER_NL80211_QCA
#endif /* CONFIG_DRIVER_NL80211_QCA */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_DRIVER_NL80211_QCA
#endif /* CONFIG_DRIVER_NL80211_QCA */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_LIBNL3_ROUTE
#endif /* CONFIG_LIBNL3_ROUTE */
static int wpa_driver_nl80211_sta_remove(struct i802_bss *bss, const u8 *addr,
					 int deauth, u16 reason_code)
{
	struct wpa_driver_nl80211_data *drv = bss->drv;
	struct nl_msg *msg;
	int ret;

	if (!(msg = nl80211_bss_msg(bss, 0, NL80211_CMD_DEL_STATION)) ||
	    nla_put(msg, NL80211_ATTR_MAC, ETH_ALEN, addr) ||
	    (deauth == 0 &&
	     nla_put_u8(msg, NL80211_ATTR_MGMT_SUBTYPE,
			WLAN_FC_STYPE_DISASSOC)) ||
	    (deauth == 1 &&
	     nla_put_u8(msg, NL80211_ATTR_MGMT_SUBTYPE,
			WLAN_FC_STYPE_DEAUTH)) ||
	    (reason_code &&
	     nla_put_u16(msg, NL80211_ATTR_REASON_CODE, reason_code))) {
		nlmsg_free(msg);
		return -ENOBUFS;
	}

	ret = send_and_recv_msgs(drv, msg, NULL, NULL);
	wpa_printf(MSG_DEBUG, "nl80211: sta_remove -> DEL_STATION %s " MACSTR
		   " --> %d (%s)",
		   bss->ifname, MAC2STR(addr), ret, strerror(-ret));

	if (drv->rtnl_sk)
		rtnl_neigh_delete_fdb_entry(bss, addr);

	if (ret == -ENOENT)
		return 0;
	return ret;
}
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_DRIVER_NL80211_QCA
#endif /* CONFIG_DRIVER_NL80211_QCA */
#if 0
#endif
#ifdef CONFIG_LIBNL3_ROUTE
#endif /* CONFIG_LIBNL3_ROUTE */
static int wpa_driver_nl80211_if_remove(struct i802_bss *bss,
					enum wpa_driver_if_type type,
					const char *ifname)
{
	struct wpa_driver_nl80211_data *drv = bss->drv;
	int ifindex = if_nametoindex(ifname);

	wpa_printf(MSG_DEBUG, "nl80211: %s(type=%d ifname=%s) ifindex=%d added_if=%d",
		   __func__, type, ifname, ifindex, bss->added_if);
	if (ifindex > 0 && (bss->added_if || bss->ifindex != ifindex))
		nl80211_remove_iface(drv, ifindex);
	else if (ifindex > 0 && !bss->added_if) {
		struct wpa_driver_nl80211_data *drv2;
		dl_list_for_each(drv2, &drv->global->interfaces,
				 struct wpa_driver_nl80211_data, list) {
			del_ifidx(drv2, ifindex, IFIDX_ANY);
			del_ifidx(drv2, IFIDX_ANY, ifindex);
		}
	}

	if (type != WPA_IF_AP_BSS)
		return 0;

	if (bss->added_if_into_bridge) {
		if (linux_br_del_if(drv->global->ioctl_sock, bss->brname,
				    bss->ifname) < 0)
			wpa_printf(MSG_INFO, "nl80211: Failed to remove "
				   "interface %s from bridge %s: %s",
				   bss->ifname, bss->brname, strerror(errno));
	}
	if (bss->added_bridge) {
		if (linux_br_del(drv->global->ioctl_sock, bss->brname) < 0)
			wpa_printf(MSG_INFO, "nl80211: Failed to remove "
				   "bridge %s: %s",
				   bss->brname, strerror(errno));
	}

	if (bss != drv->first_bss) {
		struct i802_bss *tbss;

		wpa_printf(MSG_DEBUG, "nl80211: Not the first BSS - remove it");
		for (tbss = drv->first_bss; tbss; tbss = tbss->next) {
			if (tbss->next == bss) {
				tbss->next = bss->next;
				/* Unsubscribe management frames */
				nl80211_teardown_ap(bss);
				nl80211_destroy_bss(bss);
				if (!bss->added_if)
					i802_set_iface_flags(bss, 0);
				os_free(bss);
				bss = NULL;
				break;
			}
		}
		if (bss)
			wpa_printf(MSG_INFO, "nl80211: %s - could not find "
				   "BSS %p in the list", __func__, bss);
	} else {
		wpa_printf(MSG_DEBUG, "nl80211: First BSS - reassign context");
		nl80211_teardown_ap(bss);
		if (!bss->added_if && !drv->first_bss->next)
			wpa_driver_nl80211_del_beacon(bss);
		nl80211_destroy_bss(bss);
		if (!bss->added_if)
			i802_set_iface_flags(bss, 0);
		if (drv->first_bss->next) {
			drv->first_bss = drv->first_bss->next;
			drv->ctx = drv->first_bss->ctx;
			os_free(bss);
		} else {
			wpa_printf(MSG_DEBUG, "nl80211: No second BSS to reassign context to");
		}
	}

	return 0;
}
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef ANDROID_P2P
#else /* ANDROID_P2P */
#endif /* ANDROID_P2P */
#ifdef CONFIG_TDLS
#endif /* CONFIG TDLS */
#ifdef CONFIG_DRIVER_NL80211_QCA
#endif /* CONFIG_DRIVER_NL80211_QCA */
static int driver_nl80211_if_remove(void *priv, enum wpa_driver_if_type type,
				    const char *ifname)
{
	struct i802_bss *bss = priv;
	return wpa_driver_nl80211_if_remove(bss, type, ifname);
}
static int driver_nl80211_sta_remove(void *priv, const u8 *addr)
{
	struct i802_bss *bss = priv;
	return wpa_driver_nl80211_sta_remove(bss, addr, -1, 0);
}
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DRIVER_NL80211_QCA
#define WPA_SUPPLICANT_CLIENT_ID 1
#endif /* CONFIG_DRIVER_NL80211_QCA */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_LIBNL3_ROUTE
#else /* CONFIG_LIBNL3_ROUTE */
#endif /* CONFIG_LIBNL3_ROUTE */
#ifdef CONFIG_LIBNL3_ROUTE
#else /* CONFIG_LIBNL3_ROUTE */
#endif /* CONFIG_LIBNL3_ROUTE */
#ifdef CONFIG_DRIVER_NL80211_QCA
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#endif /* CONFIG_DRIVER_NL80211_QCA */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef ANDROID_P2P
#endif /* ANDROID_P2P */
#ifdef ANDROID
#ifndef ANDROID_LIB_STUB
#endif /* !ANDROID_LIB_STUB */
#endif /* ANDROID */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_DRIVER_NL80211_QCA
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#endif /* CONFIG_DRIVER_NL80211_QCA */
