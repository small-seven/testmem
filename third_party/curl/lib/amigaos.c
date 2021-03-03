#include "curl_setup.h"
#ifdef __AMIGA__
#  include "amigaos.h"
#  if defined(HAVE_PROTO_BSDSOCKET_H) && !defined(USE_AMISSL)
#    include <amitcp/socketbasetags.h>
#  endif
#  ifdef __libnix__
#    include <stabs.h>
#  endif
#endif
#include "curl_memory.h"
#include "memdebug.h"
#ifdef __AMIGA__
#if defined(HAVE_PROTO_BSDSOCKET_H) && !defined(USE_AMISSL)
#ifdef __libnix__
#else
# define __request(msg)       Printf(msg "\n\a")
#endif
#ifndef __libnix__
#endif
#ifdef __libnix__
#endif
#endif /* HAVE_PROTO_BSDSOCKET_H */
#ifdef USE_AMISSL
void Curl_amiga_X509_free(X509 *a)
{
  X509_free(a);
}
#endif /* USE_AMISSL */
#endif /* __AMIGA__ */
