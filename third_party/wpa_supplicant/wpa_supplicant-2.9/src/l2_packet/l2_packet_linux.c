#include "includes.h"
#include <sys/ioctl.h>
#include <netpacket/packet.h>
#include <net/if.h>
#include <linux/filter.h>
#include "common.h"
#include "eloop.h"
#include "crypto/sha1.h"
#include "crypto/crypto.h"
#include "l2_packet.h"
#include "securec.h"
#ifndef CONFIG_NO_LINUX_PACKET_SOCKET_WAR
#endif /* CONFIG_NO_LINUX_PACKET_SOCKET_WAR */
#ifndef CONFIG_NO_LINUX_PACKET_SOCKET_WAR
#endif /* CONFIG_NO_LINUX_PACKET_SOCKET_WAR */
#ifndef CONFIG_NO_LINUX_PACKET_SOCKET_WAR
#endif /* CONFIG_NO_LINUX_PACKET_SOCKET_WAR */
#ifndef CONFIG_NO_LINUX_PACKET_SOCKET_WAR
#endif /* CONFIG_NO_LINUX_PACKET_SOCKET_WAR */
#ifndef CONFIG_NO_LINUX_PACKET_SOCKET_WAR
#endif /* CONFIG_NO_LINUX_PACKET_SOCKET_WAR */
#ifndef CONFIG_NO_LINUX_PACKET_SOCKET_WAR
#endif /* CONFIG_NO_LINUX_PACKET_SOCKET_WAR */
void l2_packet_deinit(struct l2_packet_data *l2)
{
	if (l2 == NULL)
		return;

	if (l2->fd >= 0) {
		eloop_unregister_read_sock(l2->fd);
		close(l2->fd);
	}

#ifndef CONFIG_NO_LINUX_PACKET_SOCKET_WAR
	if (l2->fd_br_rx >= 0) {
		eloop_unregister_read_sock(l2->fd_br_rx);
		close(l2->fd_br_rx);
	}
#endif /* CONFIG_NO_LINUX_PACKET_SOCKET_WAR */

	os_free(l2);
}
