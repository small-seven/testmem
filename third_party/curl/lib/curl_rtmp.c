#include "curl_setup.h"
#ifdef USE_LIBRTMP
#include "curl_rtmp.h"
#include "urldata.h"
#include "nonblock.h" /* for curlx_nonblock */
#include "progress.h" /* for Curl_pgrsSetUploadSize */
#include "transfer.h"
#include "warnless.h"
#include <curl/curl.h>
#include <librtmp/rtmp.h>
#include "curl_memory.h"
#include "memdebug.h"
#if defined(WIN32) && !defined(USE_LWIPSOCK)
#define setsockopt(a,b,c,d,e) (setsockopt)(a,b,c,(const char *)d,(int)e)
#define SET_RCVTIMEO(tv,s)   int tv = s*1000
#elif defined(LWIP_SO_SNDRCVTIMEO_NONSTANDARD)
#define SET_RCVTIMEO(tv,s)   int tv = s*1000
#else
#define SET_RCVTIMEO(tv,s)   struct timeval tv = {s,0}
#endif
#define DEF_BUFTIME    (2*60*60*1000)    /* 2 hours */
#endif  /* USE_LIBRTMP */
