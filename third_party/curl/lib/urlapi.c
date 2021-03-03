#include "curl_setup.h"
#include "urldata.h"
#include "urlapi-int.h"
#include "strcase.h"
#include "dotdot.h"
#include "url.h"
#include "escape.h"
#include "curl_ctype.h"
#include "inet_pton.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define STARTS_WITH_DRIVE_PREFIX(str) \
#define STARTS_WITH_URL_DRIVE_PREFIX(str) \
#define DEFAULT_SCHEME "https"
#ifdef WIN32
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#define HOSTNAME_END(x) (((x) == '/') || ((x) == '?') || ((x) == '#'))
#if !defined(MSDOS) && !defined(WIN32) && !defined(__CYGWIN__)
#else
#endif
#define DUP(dest, src, name)         \
