#include "includes.h"
#include <assert.h>
#include "common.h"
#include "eloop.h"
#include "uuid.h"
#include "http_client.h"
#include "wps_defs.h"
#include "wps_upnp.h"
#include "wps_upnp_i.h"
#define MAX_EVENTS_QUEUED 20   /* How far behind queued events */
#define MAX_FAILURES 10 /* Drop subscription after this many failures */
#define EVENT_DELAY_SECONDS 0
#define EVENT_DELAY_MSEC 0
