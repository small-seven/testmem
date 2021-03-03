#include "curl_setup.h"
#include <curl/curl.h>
#ifdef USE_LIBPSL
#include "psl.h"
#include "share.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
void Curl_psl_destroy(struct PslCache *pslcache)
{
  if(pslcache->psl) {
    if(pslcache->dynamic)
      psl_free((psl_ctx_t *) pslcache->psl);
    pslcache->psl = NULL;
    pslcache->dynamic = FALSE;
  }
}
#if defined(PSL_VERSION_NUMBER) && PSL_VERSION_NUMBER >= 0x001000
#endif
#endif /* USE_LIBPSL */
