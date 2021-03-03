#include <fcntl.h>
#include "network.h"
#include "tls.h"
#include "url.h"
#include "libavcodec/internal.h"
#include "libavutil/avutil.h"
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "libavutil/time.h"
#if CONFIG_TLS_PROTOCOL
#if CONFIG_OPENSSL
#endif
#if CONFIG_GNUTLS
#endif
#endif
void ff_tls_deinit(void)
{
#if CONFIG_TLS_PROTOCOL
#if CONFIG_OPENSSL
    ff_openssl_deinit();
#endif
#if CONFIG_GNUTLS
    ff_gnutls_deinit();
#endif
#endif
}
#if HAVE_WINSOCK2_H
#endif
#if HAVE_WINSOCK2_H
#endif
#if HAVE_WINSOCK2_H
#endif
#if HAVE_STRUCT_SOCKADDR_IN6
#endif
#ifdef SOCK_CLOEXEC
#endif
#if HAVE_FCNTL
#endif
#ifdef SO_NOSIGPIPE
#endif
#define NEXT_ATTEMPT_DELAY_MS 200
