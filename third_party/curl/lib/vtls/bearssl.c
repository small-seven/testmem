#include "curl_setup.h"
#ifdef USE_BEARSSL
#include <bearssl.h>
#include "bearssl.h"
#include "urldata.h"
#include "sendf.h"
#include "inet_pton.h"
#include "vtls.h"
#include "connect.h"
#include "select.h"
#include "multiif.h"
#include "curl_printf.h"
#include "curl_memory.h"
#define BACKEND connssl->backend
#ifdef ENABLE_IPV6
#else
#endif
#ifdef USE_NGHTTP2
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef USE_NGHTTP2
#endif
static void Curl_bearssl_session_free(void *ptr)
{
  free(ptr);
}
#endif /* USE_BEARSSL */
