#include "includes.h"
#include <pcap.h>
#include "common.h"
#include "eloop.h"
#include "l2_packet.h"
void l2_packet_deinit(struct l2_packet_data *l2)
{
	if (l2 == NULL)
		return;

	l2->rx_thread_done = CreateEvent(NULL, TRUE, FALSE, NULL);

	l2->running = 0;
	pcap_breakloop(l2->pcap);

	/*
	 * RX thread may be waiting in l2_packet_receive_cb() for l2->rx_done
	 * event and this event is set in l2_packet_rx_event(). However,
	 * l2_packet_deinit() may end up being called from l2->rx_callback(),
	 * so we need to return from here and complete deinitialization in
	 * a registered timeout to avoid having to forcefully kill the RX
	 * thread.
	 */
	eloop_register_timeout(0, 0, l2_packet_deinit_timeout, l2, NULL);
}
