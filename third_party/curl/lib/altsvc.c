#include "curl_setup.h"
#if !defined(CURL_DISABLE_HTTP) && defined(USE_ALTSVC)
#include <curl/curl.h>
#include "urldata.h"
#include "altsvc.h"
#include "curl_get_line.h"
#include "strcase.h"
#include "parsedate.h"
#include "sendf.h"
#include "warnless.h"
#include "rand.h"
#include "rename.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define MAX_ALTSVC_LINE 4095
#define MAX_ALTSVC_DATELENSTR "64"
#define MAX_ALTSVC_DATELEN 64
#define MAX_ALTSVC_HOSTLENSTR "512"
#define MAX_ALTSVC_HOSTLEN 512
#define MAX_ALTSVC_ALPNLENSTR "10"
#define MAX_ALTSVC_ALPNLEN 10
#if (defined(USE_QUICHE) || defined(USE_NGTCP2)) && !defined(UNITTESTS)
#define H3VERSION "h3-27"
#else
#define H3VERSION "h3"
#endif
static void altsvc_free(struct altsvc *as)
{
  free(as->src.host);
  free(as->dst.host);
  free(as);
}
#ifdef USE_NGHTTP2
#endif
#ifdef ENABLE_QUIC
#endif
#ifdef DEBUGBUILD
#define time(x) debugtime(x)
#endif
#endif /* CURL_DISABLE_HTTP || USE_ALTSVC */
