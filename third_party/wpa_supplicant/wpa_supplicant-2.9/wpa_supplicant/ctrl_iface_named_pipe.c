#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "config.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "wpa_supplicant_i.h"
#include "ctrl_iface.h"
#include "common/wpa_ctrl.h"
#ifdef __MINGW32_VERSION
#define SDDL_REVISION_1 1
#ifdef UNICODE
#define ConvertStringSecurityDescriptorToSecurityDescriptor \
#else
#define ConvertStringSecurityDescriptorToSecurityDescriptor \
#endif
#else /* __MINGW32_VERSION */
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#include <sddl.h>
#endif /* __MINGW32_VERSION */
#ifndef WPA_SUPPLICANT_NAMED_PIPE
#define WPA_SUPPLICANT_NAMED_PIPE "WpaSupplicant"
#endif
#define NAMED_PIPE_PREFIX TEXT("\\\\.\\pipe\\") TEXT(WPA_SUPPLICANT_NAMED_PIPE)
#define REQUEST_BUFSIZE 256
#define REPLY_BUFSIZE 4096
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
void wpa_supplicant_ctrl_iface_deinit(struct ctrl_iface_priv *priv)
{
	while (priv->ctrl_dst)
		ctrl_close_pipe(priv->ctrl_dst);
	if (priv->sec_attr_set)
		LocalFree(priv->attr.lpSecurityDescriptor);
	os_free(priv);
}
wpa_supplicant_global_ctrl_iface_deinit(struct ctrl_iface_global_priv *priv)
{
	while (priv->ctrl_dst)
		global_close_pipe(priv->ctrl_dst);
	os_free(priv);
}
