#include "curl_setup.h"
#include <curl/curl.h>
#include "curl_memory.h"
#include "memdebug.h"
#if defined(_WIN32_WCE) || defined(CURL_WINDOWS_APP)
#elif defined(WIN32)
#else
#endif
