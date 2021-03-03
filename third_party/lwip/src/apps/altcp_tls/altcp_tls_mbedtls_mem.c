#include "lwip/opt.h"
#if LWIP_ALTCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/apps/altcp_tls_mbedtls_opts.h"
#if LWIP_ALTCP_TLS && LWIP_ALTCP_TLS_MBEDTLS
#include "altcp_tls_mbedtls_mem.h"
#include "altcp_tls_mbedtls_structs.h"
#include "lwip/mem.h"
#include "mbedtls/platform.h"
#include <string.h>
#ifndef ALTCP_MBEDTLS_MEM_DEBUG
#define ALTCP_MBEDTLS_MEM_DEBUG   LWIP_DBG_OFF
#endif
#if defined(MBEDTLS_PLATFORM_MEMORY) && \
#define ALTCP_MBEDTLS_PLATFORM_ALLOC 1
#else
#define ALTCP_MBEDTLS_PLATFORM_ALLOC 0
#endif
#if ALTCP_MBEDTLS_PLATFORM_ALLOC
#ifndef ALTCP_MBEDTLS_PLATFORM_ALLOC_STATS
#define ALTCP_MBEDTLS_PLATFORM_ALLOC_STATS 0
#endif
typedef struct altcp_mbedtls_malloc_helper_s {
  size_t c;
  size_t len;
} altcp_mbedtls_malloc_helper_t;
#if ALTCP_MBEDTLS_PLATFORM_ALLOC_STATS
typedef struct altcp_mbedtls_malloc_stats_s {
  size_t allocedBytes;
  size_t allocCnt;
  size_t maxBytes;
  size_t totalBytes;
} altcp_mbedtls_malloc_stats_t;
#endif
tls_malloc(size_t c, size_t len)
{
  altcp_mbedtls_malloc_helper_t *hlpr;
  void *ret;
  size_t alloc_size;
#if ALTCP_MBEDTLS_PLATFORM_ALLOC_STATS
  if (altcp_mbedtls_malloc_clear_stats) {
    altcp_mbedtls_malloc_clear_stats = 0;
    memset(&altcp_mbedtls_malloc_stats, 0, sizeof(altcp_mbedtls_malloc_stats));
  }
#endif
  alloc_size = sizeof(altcp_mbedtls_malloc_helper_t) + (c * len);
  /* check for maximum allocation size, mainly to prevent mem_size_t overflow */
  if (alloc_size > MEM_SIZE) {
    LWIP_DEBUGF(ALTCP_MBEDTLS_MEM_DEBUG, ("mbedtls allocation too big: %c * %d bytes vs MEM_SIZE=%d",
                                          (int)c, (int)len, (int)MEM_SIZE));
    return NULL;
  }
  hlpr = (altcp_mbedtls_malloc_helper_t *)mem_malloc((mem_size_t)alloc_size);
  if (hlpr == NULL) {
    LWIP_DEBUGF(ALTCP_MBEDTLS_MEM_DEBUG, ("mbedtls alloc callback failed for %c * %d bytes", (int)c, (int)len));
    return NULL;
  }
#if ALTCP_MBEDTLS_PLATFORM_ALLOC_STATS
  altcp_mbedtls_malloc_stats.allocCnt++;
  altcp_mbedtls_malloc_stats.allocedBytes += c * len;
  if (altcp_mbedtls_malloc_stats.allocedBytes > altcp_mbedtls_malloc_stats.maxBytes) {
    altcp_mbedtls_malloc_stats.maxBytes = altcp_mbedtls_malloc_stats.allocedBytes;
  }
  altcp_mbedtls_malloc_stats.totalBytes += c * len;
#endif
  hlpr->c = c;
  hlpr->len = len;
  ret = hlpr + 1;
  /* zeroing the allocated chunk is required by mbedTLS! */
  memset(ret, 0, c * len);
  return ret;
}
tls_free(void *ptr)
{
  altcp_mbedtls_malloc_helper_t *hlpr;
  if (ptr == NULL) {
    /* this obviously happened in mbedtls... */
    return;
  }
  hlpr = ((altcp_mbedtls_malloc_helper_t *)ptr) - 1;
#if ALTCP_MBEDTLS_PLATFORM_ALLOC_STATS
  if (!altcp_mbedtls_malloc_clear_stats) {
    altcp_mbedtls_malloc_stats.allocedBytes -= hlpr->c * hlpr->len;
  }
#endif
  mem_free(hlpr);
}
#endif /* ALTCP_MBEDTLS_PLATFORM_ALLOC*/
altcp_mbedtls_mem_init(void)
{
  /* not much to do here when using the heap */

#if ALTCP_MBEDTLS_PLATFORM_ALLOC
  /* set mbedtls allocation methods */
  mbedtls_platform_set_calloc_free(&tls_malloc, &tls_free);
#endif
}
altcp_mbedtls_free(void *conf, altcp_mbedtls_state_t *state)
{
  LWIP_UNUSED_ARG(conf);
  LWIP_ASSERT("state != NULL", state != NULL);
  mem_free(state);
}
#endif /* LWIP_ALTCP_TLS && LWIP_ALTCP_TLS_MBEDTLS */
#endif /* LWIP_ALTCP */
