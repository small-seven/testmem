#include "curlcheck.h"
#include "urldata.h"
#include "connect.h"
#include "memdebug.h" /* LAST include file */
#define BASE 1000000
#define NOW(x,y) now.tv_sec = x; now.tv_usec = y
#define TIMEOUTS(x,y) data->set.timeout = x; data->set.connecttimeout = y
