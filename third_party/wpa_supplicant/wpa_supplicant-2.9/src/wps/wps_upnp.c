#include "includes.h"
#include <time.h>
#include <net/if.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include "common.h"
#include "uuid.h"
#include "base64.h"
#include "wps.h"
#include "wps_i.h"
#include "wps_upnp.h"
#include "wps_upnp_i.h"
#define NO_DOMAIN_NAME_RESOLUTION 1  /* 1 to allow only dotted ip addresses */
#define MAX_SUBSCRIPTIONS 4    /* how many subscribing clients we handle */
#define MAX_ADDR_PER_SUBSCRIPTION 8
#define MAX_EVENTS_PER_SEC 5
#if NO_DOMAIN_NAME_RESOLUTION
#else
#endif
void subscription_destroy(struct subscription *s)
{
	struct upnp_wps_device_interface *iface;
	wpa_printf(MSG_DEBUG, "WPS UPnP: Destroy subscription %p", s);
	subscr_addr_free_all(s);
	event_delete_all(s);
	dl_list_for_each(iface, &s->sm->interfaces,
			 struct upnp_wps_device_interface, list)
		upnp_er_remove_notification(iface->wps->registrar, s);
	os_free(s);
}
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#include <sys/sysctl.h>
#include <net/route.h>
#include <net/if_dl.h>
#endif /* __FreeBSD__ */
#ifdef __linux__
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#else
#error MAC address fetch not implemented
#endif
