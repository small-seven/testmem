#include "includes.h"
#include <winsock2.h>
#include <ntddndis.h>
#ifdef _WIN32_WCE
#include <winioctl.h>
#include <nuiouser.h>
#endif /* _WIN32_WCE */
#include "common.h"
#include "eloop.h"
#include "l2_packet.h"
#ifndef _WIN32_WCE
#define FSCTL_NDISUIO_BASE      FILE_DEVICE_NETWORK
#define _NDISUIO_CTL_CODE(_Function, _Method, _Access) \
#define IOCTL_NDISUIO_SET_ETHER_TYPE \
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#else /* _WIN32_WCE */
#endif /* _WIN32_WCE */
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#else /* _WIN32_WCE */
#endif /* _WIN32_WCE */
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#else /* _WIN32_WCE */
#endif /* _WIN32_WCE */
void l2_packet_deinit(struct l2_packet_data *l2)
{
	if (l2 == NULL)
		return;

	if (l2_ndisuio_global) {
		l2_ndisuio_global->refcount--;
		l2_ndisuio_global->l2[l2_ndisuio_global->refcount] = NULL;
		if (l2_ndisuio_global->refcount) {
			wpa_printf(MSG_DEBUG, "L2(NDISUIO): restore filtering "
				   "ethertype to %04x",
				   l2_ndisuio_global->first_proto);
			l2_ndisuio_set_ether_type(
				l2_ndisuio_global->first_proto);
			return;
		}

#ifdef _WIN32_WCE
		wpa_printf(MSG_DEBUG, "L2(NDISUIO): Waiting for RX thread to "
			   "stop");
		SetEvent(l2_ndisuio_global->stop_request);
		/*
		 * Cancel pending ReadFile() in the RX thread (if we were still
		 * connected at this point).
		 */
		if (!DeviceIoControl(driver_ndis_get_ndisuio_handle(),
				     IOCTL_CANCEL_READ, NULL, 0, NULL, 0, NULL,
				     NULL)) {
			wpa_printf(MSG_DEBUG, "L2(NDISUIO): IOCTL_CANCEL_READ "
				   "failed: %d", (int) GetLastError());
			/* RX thread will exit blocking ReadFile once NDISUIO
			 * notices that the adapter is disconnected. */
		}
		WaitForSingleObject(l2_ndisuio_global->rx_thread, INFINITE);
		wpa_printf(MSG_DEBUG, "L2(NDISUIO): RX thread exited");
		CloseHandle(l2_ndisuio_global->rx_thread);
		CloseHandle(l2_ndisuio_global->stop_request);
		CloseHandle(l2_ndisuio_global->ready_for_read);
		CloseHandle(l2_ndisuio_global->rx_processed);
#endif /* _WIN32_WCE */

		os_free(l2_ndisuio_global);
		l2_ndisuio_global = NULL;
	}

#ifndef _WIN32_WCE
	CancelIo(driver_ndis_get_ndisuio_handle());
#endif /* _WIN32_WCE */

	eloop_unregister_event(l2->rx_avail, sizeof(l2->rx_avail));
	CloseHandle(l2->rx_avail);
	os_free(l2);
}
