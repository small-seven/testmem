#include "tool_setup.h"
#ifndef CURL_DISABLE_LIBCURL_OPTION
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_easysrc.h"
#include "tool_setopt.h"
#include "tool_convert.h"
#include "memdebug.h" /* keep this as LAST include */
#define NV(e) {#e, e}
#define NV1(e, v) {#e, (v)}
#define NVEND {NULL, 0}         /* sentinel to mark end of list */
#define ADD(args) do { \
#define ADDF(args) do { \
#define NULL_CHECK(p) do { \
#define DECL0(s) ADD((&easysrc_decl, s))
#define DECL1(f,a) ADDF((&easysrc_decl, f,a))
#define DATA0(s) ADD((&easysrc_data, s))
#define DATA1(f,a) ADDF((&easysrc_data, f,a))
#define DATA2(f,a,b) ADDF((&easysrc_data, f,a,b))
#define DATA3(f,a,b,c) ADDF((&easysrc_data, f,a,b,c))
#define CODE0(s) ADD((&easysrc_code, s))
#define CODE1(f,a) ADDF((&easysrc_code, f,a))
#define CODE2(f,a,b) ADDF((&easysrc_code, f,a,b))
#define CODE3(f,a,b,c) ADDF((&easysrc_code, f,a,b,c))
#define CLEAN0(s) ADD((&easysrc_clean, s))
#define CLEAN1(f,a) ADDF((&easysrc_clean, f,a))
#define REM0(s) ADD((&easysrc_toohard, s))
#define REM1(f,a) ADDF((&easysrc_toohard, f,a))
#define REM2(f,a,b) ADDF((&easysrc_toohard, f,a,b))
#ifdef CURL_DOES_CONVERSIONS
#else
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
#else /* CURL_DISABLE_LIBCURL_OPTION */
#include "tool_cfgable.h"
#include "tool_setopt.h"
#endif /* CURL_DISABLE_LIBCURL_OPTION */
#ifdef CURL_DISABLE_PROXY
#define USED_TAG
#endif
#ifdef CURL_DISABLE_FTP
#define USED_TAG
#endif
#ifdef CURL_DISABLE_RTSP
#define USED_TAG
#endif
#if defined(CURL_DISABLE_HTTP) || defined(CURL_DISABLE_COOKIES)
#define USED_TAG
#endif
#if defined(CURL_DISABLE_TELNET)
#define USED_TAG
#endif
#ifdef CURL_DISABLE_TFTP
#define USED_TAG
#endif
#ifdef CURL_DISABLE_NETRC
#define USED_TAG
#endif
#ifndef USED_TAG
#endif
