#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "l2_packet.h"
void l2_packet_deinit(struct l2_packet_data *l2)
{
	if (l2 == NULL)
		return;

	if (l2->fd >= 0) {
		eloop_unregister_read_sock(l2->fd);
		/* TODO: close connection */
	}
		
	os_free(l2);
}
