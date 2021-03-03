#include "includes.h"
#ifndef CONFIG_NATIVE_WINDOWS
#include <sys/ioctl.h>
#endif /* CONFIG_NATIVE_WINDOWS */
#include <pcap.h>
#ifndef CONFIG_WINPCAP
#include <dnet.h>
#endif /* CONFIG_WINPCAP */
#include "common.h"
#include "eloop.h"
#include "l2_packet.h"
#ifdef CONFIG_WINPCAP
#else /* CONFIG_WINPCAP */
#endif /* CONFIG_WINPCAP */
#ifndef CONFIG_WINPCAP
#endif /* CONFIG_WINPCAP */
#ifdef CONFIG_WINPCAP
#else /* CONFIG_WINPCAP */
#endif /* CONFIG_WINPCAP */
#ifdef CONFIG_WINPCAP
#else /* CONFIG_WINPCAP */
#endif /* CONFIG_WINPCAP */
#ifndef CONFIG_WINPCAP
#endif /* CONFIG_WINPCAP */
#ifdef CONFIG_WINPCAP
#endif /* CONFIG_WINPCAP */
#ifdef CONFIG_WINPCAP
#else /* CONFIG_WINPCAP */
#endif /* CONFIG_WINPCAP */
#ifdef BIOCIMMEDIATE
#endif /* BIOCIMMEDIATE */
#ifdef CONFIG_WINPCAP
#else /* CONFIG_WINPCAP */
#endif /* CONFIG_WINPCAP */
#ifdef CONFIG_WINPCAP
#else /* CONFIG_WINPCAP */
#endif /* CONFIG_WINPCAP */
#ifndef CONFIG_WINPCAP
#endif /* CONFIG_WINPCAP */
void l2_packet_deinit(struct l2_packet_data *l2)
{
	if (l2 == NULL)
		return;

#ifdef CONFIG_WINPCAP
	eloop_cancel_timeout(l2_packet_receive_timeout, l2, l2->pcap);
#else /* CONFIG_WINPCAP */
	if (l2->eth)
		eth_close(l2->eth);
	eloop_unregister_read_sock(pcap_get_selectable_fd(l2->pcap));
#endif /* CONFIG_WINPCAP */
	if (l2->pcap)
		pcap_close(l2->pcap);
	os_free(l2);
}
#ifdef CONFIG_WINPCAP
#endif /* CONFIG_WINPCAP */
