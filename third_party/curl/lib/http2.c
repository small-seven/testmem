#include "curl_setup.h"
#ifdef USE_NGHTTP2
#include <nghttp2/nghttp2.h>
#include "urldata.h"
#include "http2.h"
#include "http.h"
#include "sendf.h"
#include "select.h"
#include "curl_base64.h"
#include "strcase.h"
#include "multiif.h"
#include "url.h"
#include "connect.h"
#include "strtoofft.h"
#include "strdup.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define H2_BUFSIZE 32768
#if (NGHTTP2_VERSION_NUM < 0x010c00)
#error too old nghttp2 version, upgrade!
#endif
#ifdef CURL_DISABLE_VERBOSE_STRINGS
#define nghttp2_session_callbacks_set_error_callback(x,y)
#endif
#if (NGHTTP2_VERSION_NUM >= 0x010c00)
#define NGHTTP2_HAS_SET_LOCAL_WINDOW_SIZE 1
#endif
#define HTTP2_HUGE_WINDOW_SIZE (32 * 1024 * 1024) /* 32 MB */
#ifdef DEBUG_HTTP2
#define H2BUGF(x) x
#else
#define H2BUGF(x) do { } while(0)
#endif
static void http2_stream_free(struct HTTP *http)
{
  if(http) {
    Curl_add_buffer_free(&http->header_recvbuf);
    Curl_add_buffer_free(&http->trailer_recvbuf);
    for(; http->push_headers_used > 0; --http->push_headers_used) {
      free(http->push_headers[http->push_headers_used - 1]);
    }
    free(http->push_headers);
    http->push_headers = NULL;
  }
}
#if !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#define AUTHORITY_DST_IDX 3
#define HEADER_OVERFLOW(x) \
typedef enum {
  /* Send header to server */
  HEADERINST_FORWARD,
  /* Don't send header to server */
  HEADERINST_IGNORE,
  /* Discard header, and replace it with "te: trailers" */
  HEADERINST_TE_TRAILERS
} header_instruction;
#define MAX_ACC 60000  /* <64KB to account for some overhead */
#ifdef NGHTTP2_HAS_SET_LOCAL_WINDOW_SIZE
#ifdef DEBUGBUILD
#endif
#endif
#else /* !USE_NGHTTP2 */
#include <curl/curl.h>
#endif /* USE_NGHTTP2 */
