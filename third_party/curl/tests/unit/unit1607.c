#include "curlcheck.h"
#include "urldata.h"
#include "connect.h"
#include "share.h"
#include "memdebug.h" /* LAST include file */
#ifdef ENABLE_IPV6
#define IPV6ONLY(x) x
#else
#define IPV6ONLY(x) &skip
#endif
