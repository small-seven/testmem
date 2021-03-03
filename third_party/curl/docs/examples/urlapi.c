#include <stdio.h>
#include <curl/curl.h>
#if !CURL_AT_LEAST_VERSION(7, 62, 0)
#error "this example requires curl 7.62.0 or later"
#endif
