#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "httpread.h"
#define HTTPREAD_READBUF_SIZE 1024      /* read in chunks of this size */
#define HTTPREAD_HEADER_MAX_SIZE 4096   /* max allowed for headers */
#define HTTPREAD_BODYBUF_DELTA 4096     /* increase allocation by this */
void httpread_destroy(struct httpread *h)
{
	wpa_printf(MSG_DEBUG, "httpread_destroy(%p)", h);
	if (!h)
		return;

	eloop_cancel_timeout(httpread_timeout_handler, NULL, h);
	eloop_unregister_sock(h->sd, EVENT_TYPE_READ);
	os_free(h->body);
	os_free(h->uri);
	os_memset(h, 0, sizeof(*h));  /* aid debugging */
	h->sd = -1;     /* aid debugging */
	os_free(h);
}
