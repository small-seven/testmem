#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#if defined(OPENSSL_NO_POSIX_IO)
#else
static int fd_free(BIO *a)
{
    if (a == NULL)
        return 0;
    if (a->shutdown) {
        if (a->init) {
            UP_close(a->num);
        }
        a->init = 0;
        a->flags = BIO_FLAGS_UPLINK;
    }
    return 1;
}
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
#endif
