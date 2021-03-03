#include "curl_setup.h"
#include "http_proxy.h"
#if !defined(CURL_DISABLE_PROXY) && !defined(CURL_DISABLE_HTTP)
#include <curl/curl.h>
#include "sendf.h"
#include "http.h"
#include "url.h"
#include "select.h"
#include "progress.h"
#include "non-ascii.h"
#include "connect.h"
#include "curlx.h"
#include "vtls/vtls.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef USE_SSL
#else
#endif
#ifndef CURL_DISABLE_PROXY
#else
#endif
#define SELECT_OK      0
#define SELECT_ERROR   1
void Curl_connect_free(struct Curl_easy *data)
{
  struct connectdata *conn = data->conn;
  struct http_connect_state *s = conn->connect_state;
  if(s) {
    free(s);
    conn->connect_state = NULL;
  }
}
#else
void Curl_connect_free(struct Curl_easy *data)
{
  (void)data;
}
#endif /* CURL_DISABLE_PROXY */
