#include "curl_setup.h"
#include <curl/curl.h>
#include "urldata.h"
#include "warnless.h"
#include "non-ascii.h"
#include "escape.h"
#include "strdup.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
void curl_free(void *p)
{
  free(p);
}
