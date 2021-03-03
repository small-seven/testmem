#include "curl_setup.h"
#ifndef CURL_DISABLE_RTSP
#include "urldata.h"
#include <curl/curl.h>
#include "transfer.h"
#include "sendf.h"
#include "multiif.h"
#include "http.h"
#include "url.h"
#include "progress.h"
#include "rtsp.h"
#include "strcase.h"
#include "select.h"
#include "connect.h"
#include "strdup.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define RTP_PKT_CHANNEL(p)   ((int)((unsigned char)((p)[1])))
#define RTP_PKT_LENGTH(p)  ((((int)((unsigned char)((p)[2]))) << 8) | \
#endif /* CURL_DISABLE_RTSP */
