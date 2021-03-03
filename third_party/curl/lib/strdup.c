#include "curl_setup.h"
#include <curl/curl.h>
#include "strdup.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifndef HAVE_STRDUP
#endif
void *Curl_saferealloc(void *ptr, size_t size)
{
  void *datap = realloc(ptr, size);
  if(size && !datap)
    /* only free 'ptr' if size was non-zero */
    free(ptr);
  return datap;
}
