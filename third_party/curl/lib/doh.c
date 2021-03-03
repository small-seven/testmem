#include "curl_setup.h"
#ifndef CURL_DISABLE_DOH
#include "urldata.h"
#include "curl_addrinfo.h"
#include "doh.h"
#include "sendf.h"
#include "multiif.h"
#include "url.h"
#include "share.h"
#include "curl_base64.h"
#include "connect.h"
#include "strdup.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define DNS_CLASS_IN 0x01
#define DOH_MAX_RESPONSE_SIZE 3000 /* bytes */
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#ifdef DEBUGBUILD
#define UNITTEST
#else
#define UNITTEST static
#endif
#define ERROR_CHECK_SETOPT(x,y) \
#ifdef USE_NGHTTP2
#endif
#ifndef CURLDEBUG
#else
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#else
#define showdoh(x,y)
#endif
#ifdef ENABLE_IPV6
#endif
#ifndef ENABLE_IPV6
#else
#endif
#ifdef ENABLE_IPV6
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#endif /* CURL_DISABLE_DOH */
