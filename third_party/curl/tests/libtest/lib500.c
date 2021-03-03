#include "test.h"
#include "testtrace.h"
#include "memdebug.h"
#ifdef LIB585
#else
#define setupcallbacks(x) Curl_nop_stmt
#endif
