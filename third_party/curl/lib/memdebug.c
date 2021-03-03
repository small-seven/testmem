#include "curl_setup.h"
#ifdef CURLDEBUG
#include <curl/curl.h>
#include "urldata.h"
#define MEMDEBUG_NODEFINES /* don't redefine the standard functions */
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef CURL_MT_MALLOC_FILL
# if (CURL_MT_MALLOC_FILL < 0) || (CURL_MT_MALLOC_FILL > 0xff)
#   error "invalid CURL_MT_MALLOC_FILL or out of range"
# endif
#endif
#ifdef CURL_MT_FREE_FILL
# if (CURL_MT_FREE_FILL < 0) || (CURL_MT_FREE_FILL > 0xff)
#   error "invalid CURL_MT_FREE_FILL or out of range"
# endif
#endif
#if defined(CURL_MT_MALLOC_FILL) && defined(CURL_MT_FREE_FILL)
# if (CURL_MT_MALLOC_FILL == CURL_MT_FREE_FILL)
#   error "CURL_MT_MALLOC_FILL same as CURL_MT_FREE_FILL"
# endif
#endif
#ifdef CURL_MT_MALLOC_FILL
#  define mt_malloc_fill(buf,len) memset((buf), CURL_MT_MALLOC_FILL, (len))
#else
#  define mt_malloc_fill(buf,len) Curl_nop_stmt
#endif
#ifdef CURL_MT_FREE_FILL
#  define mt_free_fill(buf,len) memset((buf), CURL_MT_FREE_FILL, (len))
#else
#  define mt_free_fill(buf,len) Curl_nop_stmt
#endif
#ifdef MEMDEBUG_LOG_SYNC
#endif
void *curl_dbg_malloc(size_t wantedsize, int line, const char *source)
{
  struct memdebug *mem;
  size_t size;

  DEBUGASSERT(wantedsize != 0);

  if(countcheck("malloc", line, source))
    return NULL;

  /* alloc at least 64 bytes */
  size = sizeof(struct memdebug) + wantedsize;

  mem = (Curl_cmalloc)(size);
  if(mem) {
    /* fill memory with junk */
    mt_malloc_fill(mem->mem, wantedsize);
    mem->size = wantedsize;
  }

  if(source)
    curl_dbg_log("MEM %s:%d malloc(%zu) = %p\n",
                 source, line, wantedsize,
                 mem ? (void *)mem->mem : (void *)0);

  return (mem ? mem->mem : NULL);
}
void *curl_dbg_calloc(size_t wanted_elements, size_t wanted_size,
                      int line, const char *source)
{
  struct memdebug *mem;
  size_t size, user_size;

  DEBUGASSERT(wanted_elements != 0);
  DEBUGASSERT(wanted_size != 0);

  if(countcheck("calloc", line, source))
    return NULL;

  /* alloc at least 64 bytes */
  user_size = wanted_size * wanted_elements;
  size = sizeof(struct memdebug) + user_size;

  mem = (Curl_ccalloc)(1, size);
  if(mem)
    mem->size = user_size;

  if(source)
    curl_dbg_log("MEM %s:%d calloc(%zu,%zu) = %p\n",
                 source, line, wanted_elements, wanted_size,
                 mem ? (void *)mem->mem : (void *)0);

  return (mem ? mem->mem : NULL);
}
#if defined(WIN32) && defined(UNICODE)
#endif
void *curl_dbg_realloc(void *ptr, size_t wantedsize,
                      int line, const char *source)
{
  struct memdebug *mem = NULL;

  size_t size = sizeof(struct memdebug) + wantedsize;

  DEBUGASSERT(wantedsize != 0);

  if(countcheck("realloc", line, source))
    return NULL;

#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:1684)
   /* 1684: conversion from pointer to same-sized integral type */
#endif

  if(ptr)
    mem = (void *)((char *)ptr - offsetof(struct memdebug, mem));

#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif

  mem = (Curl_crealloc)(mem, size);
  if(source)
    curl_dbg_log("MEM %s:%d realloc(%p, %zu) = %p\n",
                source, line, (void *)ptr, wantedsize,
                mem ? (void *)mem->mem : (void *)0);

  if(mem) {
    mem->size = wantedsize;
    return mem->mem;
  }

  return NULL;
}
void curl_dbg_free(void *ptr, int line, const char *source)
{
  if(ptr) {
    struct memdebug *mem;

#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:1684)
   /* 1684: conversion from pointer to same-sized integral type */
#endif

    mem = (void *)((char *)ptr - offsetof(struct memdebug, mem));

#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif

    /* destroy */
    mt_free_fill(mem->mem, mem->size);

    /* free for real */
    (Curl_cfree)(mem);
  }

  if(source)
    curl_dbg_log("MEM %s:%d free(%p)\n", source, line, (void *)ptr);
}
#ifdef HAVE_SOCKETPAIR
#endif
#define LOGLINE_BUFSIZE  1024
#endif /* CURLDEBUG */
