#include "includes.h"
#include <dirent.h>
#include "common/wpa_ctrl.h"
#include "common/ieee802_11_defs.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/edit.h"
#include "common/version.h"
#include "common/cli.h"
#ifndef CONFIG_NO_CTRL_IFACE
#ifndef CONFIG_CTRL_IFACE_DIR
#define CONFIG_CTRL_IFACE_DIR "/var/run/hostapd"
#endif /* CONFIG_CTRL_IFACE_DIR */
#ifndef CONFIG_CTRL_IFACE_UDP
#endif /* !CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UDP
#else /* CONFIG_CTRL_IFACE_UDP */
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_TAXONOMY
#endif /* CONFIG_TAXONOMY */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS_TESTING
#endif /* CONFIG_WPS_TESTING */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
static int hostapd_cli_cmd_remove_neighbor(struct wpa_ctrl *ctrl, int argc,
					   char *argv[])
{
	char cmd[400];
	int res;

	if (argc != 2) {
		printf("Invalid remove_neighbor command: needs 2 arguments\n");
		return -1;
	}

	res = os_snprintf(cmd, sizeof(cmd), "REMOVE_NEIGHBOR %s %s",
			  argv[0], argv[1]);
	if (os_snprintf_error(sizeof(cmd), res)) {
		printf("Too long REMOVE_NEIGHBOR command.\n");
		return -1;
	}
	return wpa_ctrl_command(ctrl, cmd);
}
#ifdef CONFIG_DPP
static int hostapd_cli_cmd_dpp_bootstrap_remove(struct wpa_ctrl *ctrl, int argc,
						char *argv[])
{
	return hostapd_cli_cmd(ctrl, "DPP_BOOTSTRAP_REMOVE", 1, argc, argv);
}
static int hostapd_cli_cmd_dpp_configurator_remove(struct wpa_ctrl *ctrl,
						   int argc, char *argv[])
{
	return hostapd_cli_cmd(ctrl, "DPP_CONFIGURATOR_REMOVE", 1, argc, argv);
}
static int hostapd_cli_cmd_dpp_pkex_remove(struct wpa_ctrl *ctrl, int argc,
					   char *argv[])
{
	return hostapd_cli_cmd(ctrl, "DPP_PKEX_REMOVE", 1, argc, argv);
}
#endif /* CONFIG_DPP */
#ifdef CONFIG_TAXONOMY
#endif /* CONFIG_TAXONOMY */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_HOSTAPD_CLI_HISTORY_DIR
#else /* CONFIG_HOSTAPD_CLI_HISTORY_DIR */
#endif /* CONFIG_HOSTAPD_CLI_HISTORY_DIR */
static void hostapd_cli_cleanup(void)
{
	hostapd_cli_close_connection();
	if (pid_file)
		os_daemonize_terminate(pid_file);

	os_program_deinit();
}
#else /* CONFIG_NO_CTRL_IFACE */
#endif /* CONFIG_NO_CTRL_IFACE */
