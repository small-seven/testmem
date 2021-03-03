#include "includes.h"
#include <sys/un.h>
#include <sys/stat.h>
#include <grp.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#ifdef __linux__
#include <sys/ioctl.h>
#endif /* __linux__ */
#ifdef ANDROID
#include <cutils/sockets.h>
#endif /* ANDROID */
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/list.h"
#include "common/ctrl_iface_common.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "config.h"
#include "wpa_supplicant_i.h"
#include "ctrl_iface.h"
#ifdef __linux__
#endif /* __linux__ */
static int wpa_supplicant_ctrl_iface_detach(struct dl_list *ctrl_dst,
					    struct sockaddr_storage *from,
					    socklen_t fromlen)
{
	return ctrl_iface_detach(ctrl_dst, from, fromlen);
}
#ifdef __CYGWIN__
#endif /* __CYGWIN__ */
#ifdef __linux__
#else /* __linux__ */
#endif /* __linux__ */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef ANDROID
#endif /* ANDROID */
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#endif /* __FreeBSD__ */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef ANDROID
#endif /* ANDROID */
void wpa_supplicant_ctrl_iface_deinit(struct ctrl_iface_priv *priv)
{
	struct wpa_ctrl_dst *dst, *prev;
	struct ctrl_iface_msg *msg, *prev_msg;
	struct ctrl_iface_global_priv *gpriv;

	if (priv->sock > -1) {
		char *fname;
		char *buf, *dir = NULL;
		eloop_unregister_read_sock(priv->sock);
		if (!dl_list_empty(&priv->ctrl_dst)) {
			/*
			 * Wait before closing the control socket if
			 * there are any attached monitors in order to allow
			 * them to receive any pending messages.
			 */
			wpa_printf(MSG_DEBUG, "CTRL_IFACE wait for attached "
				   "monitors to receive messages");
			os_sleep(0, 100000);
		}
		close(priv->sock);
		priv->sock = -1;
		fname = wpa_supplicant_ctrl_iface_path(priv->wpa_s);
		if (fname) {
			unlink(fname);
			os_free(fname);
		}

		if (priv->wpa_s->conf->ctrl_interface == NULL)
			goto free_dst;
		buf = os_strdup(priv->wpa_s->conf->ctrl_interface);
		if (buf == NULL)
			goto free_dst;
		if (os_strncmp(buf, "DIR=", 4) == 0) {
			char *gid_str;
			dir = buf + 4;
			gid_str = os_strstr(dir, " GROUP=");
			if (gid_str)
				*gid_str = '\0';
		} else
			dir = buf;

		if (rmdir(dir) < 0) {
			if (errno == ENOTEMPTY) {
				wpa_printf(MSG_DEBUG, "Control interface "
					   "directory not empty - leaving it "
					   "behind");
			} else {
				wpa_printf(MSG_ERROR,
					   "rmdir[ctrl_interface=%s]: %s",
					   dir, strerror(errno));
			}
		}
		os_free(buf);
	}

free_dst:
	dl_list_for_each_safe(dst, prev, &priv->ctrl_dst, struct wpa_ctrl_dst,
			      list) {
		dl_list_del(&dst->list);
		os_free(dst);
	}
	dl_list_for_each_safe(msg, prev_msg, &priv->msg_queue,
			      struct ctrl_iface_msg, list) {
		dl_list_del(&msg->list);
		os_free(msg);
	}
	gpriv = priv->wpa_s->global->ctrl_iface;
	if (gpriv) {
		dl_list_for_each_safe(msg, prev_msg, &gpriv->msg_queue,
				      struct ctrl_iface_msg, list) {
			if (msg->wpa_s == priv->wpa_s) {
				dl_list_del(&msg->list);
				os_free(msg);
			}
		}
	}
	eloop_cancel_timeout(wpas_ctrl_msg_queue_timeout, priv->wpa_s, NULL);
	os_free(priv);
}
#ifdef ANDROID
#endif /* ANDROID */
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#endif /* __FreeBSD__ */
wpa_supplicant_global_ctrl_iface_deinit(struct ctrl_iface_global_priv *priv)
{
	struct wpa_ctrl_dst *dst, *prev;
	struct ctrl_iface_msg *msg, *prev_msg;

	if (priv->sock >= 0) {
		eloop_unregister_read_sock(priv->sock);
		close(priv->sock);
	}
	if (priv->global->params.ctrl_interface)
		unlink(priv->global->params.ctrl_interface);
	dl_list_for_each_safe(dst, prev, &priv->ctrl_dst, struct wpa_ctrl_dst,
			      list) {
		dl_list_del(&dst->list);
		os_free(dst);
	}
	dl_list_for_each_safe(msg, prev_msg, &priv->msg_queue,
			      struct ctrl_iface_msg, list) {
		dl_list_del(&msg->list);
		os_free(msg);
	}
	os_free(priv);
}
