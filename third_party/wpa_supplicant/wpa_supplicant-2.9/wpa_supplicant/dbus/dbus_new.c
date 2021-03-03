#include "includes.h"
#include "common.h"
#include "common/ieee802_11_defs.h"
#include "wps/wps.h"
#include "ap/sta_info.h"
#include "../config.h"
#include "../wpa_supplicant_i.h"
#include "../bss.h"
#include "../wpas_glue.h"
#include "dbus_new_helpers.h"
#include "dbus_dict_helpers.h"
#include "dbus_new.h"
#include "dbus_new_handlers.h"
#include "dbus_common_i.h"
#include "dbus_new_handlers_p2p.h"
#include "p2p/p2p.h"
#include "../p2p_supplicant.h"
#ifdef CONFIG_AP /* until needed by something else */
#endif /* CONFIG_AP */
void wpas_dbus_signal_blob_removed(struct wpa_supplicant *wpa_s,
				   const char *name)
{
	wpas_dbus_signal_blob(wpa_s, name, "BlobRemoved");
}
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_MESH
void wpas_dbus_signal_mesh_group_removed(struct wpa_supplicant *wpa_s,
					 const u8 *meshid, u8 meshid_len,
					 int reason)
{
	struct wpas_dbus_priv *iface;
	DBusMessage *msg;
	DBusMessageIter iter, dict_iter;

	iface = wpa_s->global->dbus;

	/* Do nothing if the control interface is not turned on */
	if (!iface || !wpa_s->dbus_new_path)
		return;

	msg = dbus_message_new_signal(wpa_s->dbus_new_path,
				      WPAS_DBUS_NEW_IFACE_MESH,
				      "MeshGroupRemoved");
	if (!msg)
		return;

	dbus_message_iter_init_append(msg, &iter);
	if (!wpa_dbus_dict_open_write(&iter, &dict_iter) ||
	    !wpa_dbus_dict_append_byte_array(&dict_iter, "SSID",
					     (const char *) meshid,
					     meshid_len) ||
	    !wpa_dbus_dict_append_int32(&dict_iter, "DisconnectReason",
					reason) ||
	    !wpa_dbus_dict_close_write(&iter, &dict_iter))
		wpa_printf(MSG_ERROR, "dbus: Failed to construct signal");
	else
		dbus_connection_send(iface->con, msg, NULL);
	dbus_message_unref(msg);
}
#endif /* CONFIG_MESH */
#ifdef CONFIG_P2P
void wpas_dbus_signal_p2p_group_removed(struct wpa_supplicant *wpa_s,
					const char *role)
{
	DBusMessage *msg;
	DBusMessageIter iter, dict_iter;
	struct wpas_dbus_priv *iface = wpa_s->global->dbus;
	struct wpa_supplicant *parent;

	/* Do nothing if the control interface is not turned on */
	if (iface == NULL)
		return;

	parent = wpa_s->parent;
	if (parent->p2p_mgmt)
		parent = parent->parent;

	if (!wpa_s->dbus_groupobj_path || !wpa_s->dbus_new_path ||
	    !parent->dbus_new_path)
		return;

	msg = dbus_message_new_signal(parent->dbus_new_path,
				      WPAS_DBUS_NEW_IFACE_P2PDEVICE,
				      "GroupFinished");
	if (msg == NULL)
		return;

	dbus_message_iter_init_append(msg, &iter);
	if (!wpa_dbus_dict_open_write(&iter, &dict_iter) ||
	    !wpa_dbus_dict_append_object_path(&dict_iter,
					      "interface_object",
					      wpa_s->dbus_new_path) ||
	    !wpa_dbus_dict_append_string(&dict_iter, "role", role) ||
	    !wpa_dbus_dict_append_object_path(&dict_iter, "group_object",
					      wpa_s->dbus_groupobj_path) ||
	    !wpa_dbus_dict_close_write(&iter, &dict_iter))
		wpa_printf(MSG_ERROR, "dbus: Failed to construct signal");
	else
		dbus_connection_send(iface->con, msg, NULL);
	dbus_message_unref(msg);
}
#endif /* CONFIG_P2P */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
static void wpa_dbus_free(void *ptr)
{
	os_free(ptr);
}
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AUTOSCAN
#endif /* CONFIG_AUTOSCAN */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
