#include <curl/curl.h>
#include "config-os400.h"  /* Not curl_setup.h: we only need some defines. */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <pthread.h>
#include <netdb.h>
#include <qadrt.h>
#include <errno.h>
#ifdef HAVE_ZLIB_H
#include <zlib.h>
#endif
#ifdef USE_GSKIT
#include <gskssl.h>
#include <qsoasync.h>
#endif
#ifdef HAVE_GSSAPI
#include <gssapi.h>
#endif
#ifndef CURL_DISABLE_LDAP
#include <ldap.h>
#endif
#include <netinet/in.h>
#include <arpa/inet.h>
#include "os400sys.h"
#pragma convert(0)                              /* Restore EBCDIC. */
#define MIN_BYTE_GAIN   1024    /* Minimum gain when shortening a buffer. */
typedef struct {
        unsigned long   size;                   /* Buffer size. */
        char *          buf;                    /* Buffer address. */
}               buffer_t;
thdbufdestroy(void * private)

{
  if(private) {
    buffer_t * p = (buffer_t *) private;
    localkey_t i;

    for(i = (localkey_t) 0; i < LK_LAST; i++) {
      free(p->buf);
      p++;
      }

    free(private);
    }
}
#ifdef USE_GSKIT
#endif /* USE_GSKIT */
#ifdef HAVE_GSSAPI
#endif /* HAVE_GSSAPI */
#ifndef CURL_DISABLE_LDAP
#endif /* CURL_DISABLE_LDAP */
#ifdef HAVE_LIBZ
#endif
