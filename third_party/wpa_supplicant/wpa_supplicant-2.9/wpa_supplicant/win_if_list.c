#include "includes.h"
#include <stdio.h>
#ifdef CONFIG_USE_NDISUIO
#include <winsock2.h>
#include <ntddndis.h>
#else /* CONFIG_USE_NDISUIO */
#include "pcap.h"
#include <winsock.h>
#endif /* CONFIG_USE_NDISUIO */
#ifdef CONFIG_USE_NDISUIO
#define FSCTL_NDISUIO_BASE      FILE_DEVICE_NETWORK
#define _NDISUIO_CTL_CODE(_Function, _Method, _Access) \
#define IOCTL_NDISUIO_QUERY_BINDING \
#define IOCTL_NDISUIO_BIND_WAIT \
typedef struct _NDISUIO_QUERY_BINDING
{
	ULONG BindingIndex;
	ULONG DeviceNameOffset;
	ULONG DeviceNameLength;
	ULONG DeviceDescrOffset;
	ULONG DeviceDescrLength;
} NDISUIO_QUERY_BINDING, *PNDISUIO_QUERY_BINDING;
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#else /* CONFIG_USE_NDISUIO */
#endif /* CONFIG_USE_NDISUIO */
#ifdef CONFIG_USE_NDISUIO
#else /* CONFIG_USE_NDISUIO */
#endif /* CONFIG_USE_NDISUIO */
