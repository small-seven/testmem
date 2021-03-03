#include "includes.h"
#include "common.h"
#include "base64.h"
#include "uuid.h"
#include "httpread.h"
#include "http_server.h"
#include "wps_i.h"
#include "wps_upnp.h"
#include "wps_upnp_i.h"
#include "upnp_xml.h"
#define WEB_CONNECTION_TIMEOUT_SEC 30   /* Drop web connection after t.o. */
#define WEB_CONNECTION_MAX_READ 8000    /* Max we'll read for TCP request */
#define MAX_WEB_CONNECTIONS 10          /* max simultaneous web connects */
#ifdef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#if 0
#endif
#if 0
#endif
