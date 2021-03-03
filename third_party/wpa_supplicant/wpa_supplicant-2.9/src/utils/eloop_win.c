#include "includes.h"
#include <winsock2.h>
#include "common.h"
#include "list.h"
#include "eloop.h"
static void eloop_remove_timeout(struct eloop_timeout *timeout)
{
	dl_list_del(&timeout->list);
	os_free(timeout);
}
#if 0
#endif
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#else /* _WIN32_WCE */
#endif /* _WIN32_WCE */
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
void eloop_destroy(void)
{
	struct eloop_timeout *timeout, *prev;

	dl_list_for_each_safe(timeout, prev, &eloop.timeout,
			      struct eloop_timeout, list) {
		eloop_remove_timeout(timeout);
	}
	os_free(eloop.readers);
	os_free(eloop.signals);
	if (eloop.term_event)
		CloseHandle(eloop.term_event);
	os_free(eloop.handles);
	eloop.handles = NULL;
	os_free(eloop.events);
	eloop.events = NULL;
}
