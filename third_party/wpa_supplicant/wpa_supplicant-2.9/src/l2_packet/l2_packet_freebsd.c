#include "includes.h"
#if defined(__APPLE__) || defined(__GLIBC__)
#include <net/bpf.h>
#endif /* __APPLE__ */
#include <pcap.h>
#include <sys/ioctl.h>
#ifdef __sun__
#include <libdlpi.h>
#else /* __sun__ */
#include <sys/sysctl.h>
#endif /* __sun__ */
#include <net/if.h>
#include <net/if_dl.h>
#include <net/route.h>
#include <netinet/in.h>
#include "common.h"
#include "eloop.h"
#include "l2_packet.h"
#ifndef __sun__
#endif /* __sun__ */
#ifdef __sun__
#else /* __sun__ */
#endif /* __sun__ */
void l2_packet_deinit(struct l2_packet_data *l2)
{
	if (l2 != NULL) {
		if (l2->pcap) {
			eloop_unregister_read_sock(
				pcap_get_selectable_fd(l2->pcap));
			pcap_close(l2->pcap);
		}
		os_free(l2);
	}
}
