#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_SOCK
# include <openssl/bio.h>
# ifdef WATT32
#  undef sock_write
#  undef sock_read
#  undef sock_puts
#  define sock_write SockWrite
#  define sock_read  SockRead
#  define sock_puts  SockPuts
# endif
static int sock_free(BIO *a)
{
    if (a == NULL)
        return 0;
    if (a->shutdown) {
        if (a->init) {
            BIO_closesocket(a->num);
        }
        a->init = 0;
        a->flags = 0;
    }
    return 1;
}
# if defined(OPENSSL_SYS_WINDOWS)
#  if defined(WSAEWOULDBLOCK)
#  endif
# endif
# ifdef EWOULDBLOCK
#  ifdef WSAEWOULDBLOCK
#   if WSAEWOULDBLOCK != EWOULDBLOCK
#   endif
#  else
#  endif
# endif
# if defined(ENOTCONN)
# endif
# ifdef EINTR
# endif
# ifdef EAGAIN
#  if EWOULDBLOCK != EAGAIN
#  endif
# endif
# ifdef EPROTO
# endif
# ifdef EINPROGRESS
# endif
# ifdef EALREADY
# endif
#endif                          /* #ifndef OPENSSL_NO_SOCK */
