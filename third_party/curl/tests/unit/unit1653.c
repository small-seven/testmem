#include "curlcheck.h"
#include "urldata.h"
#include "curl/urlapi.h"
#include "urlapi-int.h"
#define free_and_clear(x) free(x); x = NULL
