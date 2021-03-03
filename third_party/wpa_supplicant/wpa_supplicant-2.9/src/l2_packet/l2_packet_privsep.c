#include "includes.h"
#include <sys/un.h>
#include "common.h"
#include "eloop.h"
#include "l2_packet.h"
#include "common/privsep_commands.h"
void l2_packet_deinit(struct l2_packet_data *l2)
{
	if (l2 == NULL)
		return;

	if (l2->fd >= 0) {
		wpa_priv_cmd(l2, PRIVSEP_CMD_L2_UNREGISTER, NULL, 0);
		eloop_unregister_read_sock(l2->fd);
		close(l2->fd);
	}

	if (l2->own_socket_path) {
		unlink(l2->own_socket_path);
		os_free(l2->own_socket_path);
	}

	os_free(l2);
}
