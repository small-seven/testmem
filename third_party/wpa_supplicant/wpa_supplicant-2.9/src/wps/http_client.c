#include "includes.h"
#include <fcntl.h>
#include "common.h"
#include "eloop.h"
#include "httpread.h"
#include "http_client.h"
#define HTTP_CLIENT_TIMEOUT_SEC 30
void http_client_free(struct http_client *c)
{
	if (c == NULL)
		return;
	httpread_destroy(c->hread);
	wpabuf_free(c->req);
	if (c->sd >= 0) {
		eloop_unregister_sock(c->sd, EVENT_TYPE_WRITE);
		close(c->sd);
	}
	eloop_cancel_timeout(http_client_timeout, c, NULL);
	os_free(c);
}
