#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "config.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "wpa_supplicant_i.h"
#include "ctrl_iface.h"
#include "common/wpa_ctrl.h"
#define COOKIE_LEN 8
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
static void wpas_ctrl_iface_free_dst(struct wpa_ctrl_dst *dst)
{
	struct wpa_ctrl_dst *prev;

	while (dst) {
		prev = dst;
		dst = dst->next;
		os_free(prev);
	}
}
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#endif /* CONFIG_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
static int wpa_supplicant_ctrl_iface_detach(struct wpa_ctrl_dst **head,
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
					    struct sockaddr_in6 *from,
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
					    struct sockaddr_in *from,
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
					    socklen_t fromlen)
{
	struct wpa_ctrl_dst *dst, *prev = NULL;
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
	char addr[INET6_ADDRSTRLEN];
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */

	dst = *head;
	while (dst) {
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
		if (from->sin6_port == dst->addr.sin6_port &&
		    !os_memcmp(&from->sin6_addr, &dst->addr.sin6_addr,
			       sizeof(from->sin6_addr))) {
			wpa_printf(MSG_DEBUG, "CTRL_IFACE monitor detached %s:%d",
				   inet_ntop(AF_INET6, &from->sin6_addr, addr,
					     sizeof(*from)),
				   ntohs(from->sin6_port));
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
		if (from->sin_addr.s_addr == dst->addr.sin_addr.s_addr &&
		    from->sin_port == dst->addr.sin_port) {
			wpa_printf(MSG_DEBUG, "CTRL_IFACE monitor detached "
				   "%s:%d", inet_ntoa(from->sin_addr),
				   ntohs(from->sin_port));
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
			if (prev == NULL)
				*head = dst->next;
			else
				prev->next = dst->next;
			os_free(dst);
			return 0;
		}
		prev = dst;
		dst = dst->next;
	}
	return -1;
}
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#if CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#ifndef CONFIG_CTRL_IFACE_UDP_REMOTE
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifndef CONFIG_CTRL_IFACE_UDP_REMOTE
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#ifdef CONFIG_CTRL_IFACE_UDP_REMOTE
#else /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_REMOTE
#else /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_REMOTE
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
void wpa_supplicant_ctrl_iface_deinit(struct ctrl_iface_priv *priv)
{
	if (priv->sock > -1) {
		eloop_unregister_read_sock(priv->sock);
		if (priv->ctrl_dst) {
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
	}

	wpas_ctrl_iface_free_dst(priv->ctrl_dst);
	os_free(priv);
}
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifdef CONFIG_CTRL_IFACE_UDP_IPV6
#else /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#ifndef CONFIG_CTRL_IFACE_UDP_REMOTE
#ifndef CONFIG_CTRL_IFACE_UDP_IPV6
#endif /* CONFIG_CTRL_IFACE_UDP_IPV6 */
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#ifdef CONFIG_CTRL_IFACE_UDP_REMOTE
#else /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
#ifdef CONFIG_CTRL_IFACE_UDP_REMOTE
#endif /* CONFIG_CTRL_IFACE_UDP_REMOTE */
wpa_supplicant_global_ctrl_iface_deinit(struct ctrl_iface_global_priv *priv)
{
	if (priv->sock >= 0) {
		eloop_unregister_read_sock(priv->sock);
		close(priv->sock);
	}

	wpas_ctrl_iface_free_dst(priv->ctrl_dst);
	os_free(priv);
}
