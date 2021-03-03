#include "utils/includes.h"
#include <netdb.h>
#include <sys/un.h>
#include "utils/common.h"
#include "ctrl_iface_common.h"
#ifdef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UNIX
#endif /* CONFIG_CTRL_IFACE_UNIX */
#ifdef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UNIX
#endif /* CONFIG_CTRL_IFACE_UNIX */
int ctrl_iface_detach(struct dl_list *ctrl_dst, struct sockaddr_storage *from,
		      socklen_t fromlen)
{
	struct wpa_ctrl_dst *dst;

	dl_list_for_each(dst, ctrl_dst, struct wpa_ctrl_dst, list) {
		if (!sockaddr_compare(from, fromlen,
				      &dst->addr, dst->addrlen)) {
			sockaddr_print(MSG_DEBUG, "CTRL_IFACE monitor detached",
				       from, fromlen);
			dl_list_del(&dst->list);
			os_free(dst);
			return 0;
		}
	}

	return -1;
}
