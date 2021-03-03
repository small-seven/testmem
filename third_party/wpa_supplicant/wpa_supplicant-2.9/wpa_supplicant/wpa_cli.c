#include "includes.h"
#ifdef CONFIG_CTRL_IFACE
#ifdef CONFIG_CTRL_IFACE_UNIX
#include <dirent.h>
#endif /* CONFIG_CTRL_IFACE_UNIX */
#include "common/cli.h"
#include "common/wpa_ctrl.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/edit.h"
#include "utils/list.h"
#include "common/version.h"
#include "common/ieee802_11_defs.h"
#ifdef ANDROID
#include <cutils/properties.h>
#endif /* ANDROID */
#define VENDOR_ELEM_FRAME_ID \
#ifndef CONFIG_CTRL_IFACE_DIR
#define CONFIG_CTRL_IFACE_DIR "/var/run/wpa_supplicant"
#endif /* CONFIG_CTRL_IFACE_DIR */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#if defined(CONFIG_CTRL_IFACE_UDP) || defined(CONFIG_CTRL_IFACE_NAMED_PIPE)
#else /* CONFIG_CTRL_IFACE_UDP || CONFIG_CTRL_IFACE_NAMED_PIPE */
#ifdef ANDROID
#endif /* ANDROID */
#endif /* CONFIG_CTRL_IFACE_UDP || CONFIG_CTRL_IFACE_NAMED_PIPE */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_MESH
#else /* CONFIG_MESH */
#endif /* CONFIG_MESH */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
static int wpa_cli_cmd_interface_remove(struct wpa_ctrl *ctrl, int argc,
					char *argv[])
{
	return wpa_cli_cmd(ctrl, "INTERFACE_REMOVE", 1, argc, argv);
}
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_MESH
static int wpa_cli_cmd_mesh_group_remove(struct wpa_ctrl *ctrl, int argc,
					 char *argv[])
{
	return wpa_cli_cmd(ctrl, "MESH_GROUP_REMOVE", 1, argc, argv);
}
static int wpa_cli_cmd_mesh_peer_remove(struct wpa_ctrl *ctrl, int argc,
					char *argv[])
{
	return wpa_cli_cmd(ctrl, "MESH_PEER_REMOVE", 1, argc, argv);
}
#endif /* CONFIG_MESH */
#ifdef CONFIG_P2P
static int wpa_cli_cmd_p2p_group_remove(struct wpa_ctrl *ctrl, int argc,
					char *argv[])
{
	return wpa_cli_cmd(ctrl, "P2P_GROUP_REMOVE", 1, argc, argv);
}
static char ** wpa_cli_complete_p2p_group_remove(const char *str, int pos)
{
	int arg = get_cmd_arg_num(str, pos);
	char **res = NULL;

	switch (arg) {
	case 1:
		res = cli_txt_list_array(&p2p_groups);
		break;
	}

	return res;
}
#endif /* CONFIG_P2P */
static int wpa_cli_cmd_vendor_elem_remove(struct wpa_ctrl *ctrl, int argc,
					  char *argv[])
{
	return wpa_cli_cmd(ctrl, "VENDOR_ELEM_REMOVE", 2, argc, argv);
}
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_AUTOSCAN
#endif /* CONFIG_AUTOSCAN */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_DPP
static int wpa_cli_cmd_dpp_bootstrap_remove(struct wpa_ctrl *ctrl, int argc,
					    char *argv[])
{
	return wpa_cli_cmd(ctrl, "DPP_BOOTSTRAP_REMOVE", 1, argc, argv);
}
static int wpa_cli_cmd_dpp_configurator_remove(struct wpa_ctrl *ctrl, int argc,
					       char *argv[])
{
	return wpa_cli_cmd(ctrl, "DPP_CONFIGURATOR_REMOVE", 1, argc, argv);
}
static int wpa_cli_cmd_dpp_pkex_remove(struct wpa_ctrl *ctrl, int argc,
				       char *argv[])
{
	return wpa_cli_cmd(ctrl, "DPP_PKEX_REMOVE", 1, argc, argv);
}
#endif /* CONFIG_DPP */
#ifdef CONFIG_PMKSA_CACHE_EXTERNAL
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#endif /* CONFIG_PMKSA_CACHE_EXTERNAL */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_AUTOSCAN
#endif /* CONFIG_AUTOSCAN */
#ifdef CONFIG_WNM
#endif /* CONFIG_WNM */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifndef CONFIG_ANSI_C_EXTRA
#endif /* CONFIG_ANSI_C_EXTRA */
#ifdef CONFIG_CTRL_IFACE_NAMED_PIPE
#else /* CONFIG_CTRL_IFACE_NAMED_PIPE */
#endif /* CONFIG_CTRL_IFACE_NAMED_PIPE */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_CTRL_IFACE_UDP_REMOTE
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#ifdef CONFIG_WPA_CLI_HISTORY_DIR
#else /* CONFIG_WPA_CLI_HISTORY_DIR */
#endif /* CONFIG_WPA_CLI_HISTORY_DIR */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_ANSI_C_EXTRA
#else /* CONFIG_ANSI_C_EXTRA */
#endif /* CONFIG_ANSI_C_EXTRA */
#ifdef ANDROID
#else /* ANDROID */
#ifdef CONFIG_CTRL_IFACE_UNIX
#ifdef _DIRENT_HAVE_D_TYPE
#endif /* _DIRENT_HAVE_D_TYPE */
#endif /* CONFIG_CTRL_IFACE_UNIX */
#ifdef CONFIG_CTRL_IFACE_NAMED_PIPE
#endif /* CONFIG_CTRL_IFACE_NAMED_PIPE */
#endif /* ANDROID */
#else /* CONFIG_CTRL_IFACE */
#endif /* CONFIG_CTRL_IFACE */
