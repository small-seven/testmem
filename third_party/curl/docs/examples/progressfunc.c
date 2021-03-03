#include <stdio.h>
#include <curl/curl.h>
#if LIBCURL_VERSION_NUM >= 0x073d00
#define TIME_IN_US 1 /* microseconds */
#define TIMETYPE curl_off_t
#define TIMEOPT CURLINFO_TOTAL_TIME_T
#define MINIMAL_PROGRESS_FUNCTIONALITY_INTERVAL     3000000
#else
#define TIMETYPE double
#define TIMEOPT CURLINFO_TOTAL_TIME
#define MINIMAL_PROGRESS_FUNCTIONALITY_INTERVAL     3
#endif
#define STOP_DOWNLOAD_AFTER_THIS_MANY_BYTES         6000
#ifdef TIME_IN_US
#else
#endif
#if LIBCURL_VERSION_NUM < 0x072000
#endif
#if LIBCURL_VERSION_NUM >= 0x072000
#else
#endif
