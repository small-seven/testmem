#include "utils/includes.h"
#ifndef CONFIG_NATIVE_WINDOWS
#include <syslog.h>
#include <grp.h>
#endif /* CONFIG_NATIVE_WINDOWS */
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/uuid.h"
#include "crypto/random.h"
#include "crypto/tls.h"
#include "common/version.h"
#include "common/dpp.h"
#include "drivers/driver.h"
#include "eap_server/eap.h"
#include "eap_server/tncs.h"
#include "ap/hostapd.h"
#include "ap/ap_config.h"
#include "ap/ap_drv_ops.h"
#include "ap/dpp_hostapd.h"
#include "fst/fst.h"
#include "config_file.h"
#include "eap_register.h"
#include "ctrl_iface.h"
#ifndef CONFIG_NO_HOSTAPD_LOGGER
#ifdef CONFIG_DEBUG_SYSLOG
#endif /* CONFIG_DEBUG_SYSLOG */
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NO_HOSTAPD_LOGGER */
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
static void hostapd_global_deinit(const char *pid_file, int eloop_initialized)
{
	int i;

	for (i = 0; wpa_drivers[i] && global.drv_priv; i++) {
		if (!global.drv_priv[i])
			continue;
		wpa_drivers[i]->global_deinit(global.drv_priv[i]);
	}
	os_free(global.drv_priv);
	global.drv_priv = NULL;

#ifdef EAP_SERVER_TNC
	tncs_global_deinit();
#endif /* EAP_SERVER_TNC */

	random_deinit();

	if (eloop_initialized)
		eloop_destroy();

#ifndef CONFIG_NATIVE_WINDOWS
	closelog();
#endif /* CONFIG_NATIVE_WINDOWS */

	eap_server_unregister_methods();

	os_daemonize_terminate(pid_file);
}
#ifdef EAP_SERVER_TNC
#endif /* EAP_SERVER_TNC */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#ifdef CONFIG_DEBUG_SYSLOG
#endif /* CONFIG_DEBUG_SYSLOG */
#ifndef CONFIG_CTRL_IFACE_UDP
#endif /* !CONFIG_CTRL_IFACE_UDP */
#ifndef CONFIG_CTRL_IFACE_UDP
#endif /* !CONFIG_CTRL_IFACE_UDP */
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifndef HOSTAPD_CLEANUP_INTERVAL
#define HOSTAPD_CLEANUP_INTERVAL 10
#endif /* HOSTAPD_CLEANUP_INTERVAL */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_ETH_P_OUI
#endif /* CONFIG_ETH_P_OUI */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#ifdef CONFIG_DEBUG_SYSLOG
#endif /* CONFIG_DEBUG_SYSLOG */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_DEBUG_SYSLOG
#endif /* CONFIG_DEBUG_SYSLOG */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#if defined(CONFIG_FST) && defined(CONFIG_CTRL_IFACE)
#endif /* CONFIG_FST && CONFIG_CTRL_IFACE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
