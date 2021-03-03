#include <errno.h>
#include <gnutls/gnutls.h>
#include <gnutls/x509.h>
#include "avformat.h"
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "url.h"
#include "tls.h"
#include "libavcodec/internal.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#ifndef GNUTLS_VERSION_NUMBER
#define GNUTLS_VERSION_NUMBER LIBGNUTLS_VERSION_NUMBER
#endif
#if HAVE_THREADS && GNUTLS_VERSION_NUMBER <= 0x020b00
#include <gcrypt.h>
#include "libavutil/thread.h"
#endif
typedef struct TLSContext {
    const AVClass *class;
    TLSShared tls_shared;
    gnutls_session_t session;
    gnutls_certificate_credentials_t cred;
    int need_shutdown;
} TLSContext;
#if HAVE_THREADS && GNUTLS_VERSION_NUMBER < 0x020b00
#endif
void ff_gnutls_deinit(void)
{
    ff_lock_avformat();
    gnutls_global_deinit();
    ff_unlock_avformat();
}
#ifdef GNUTLS_E_PREMATURE_TERMINATION
#endif
#if GNUTLS_VERSION_NUMBER >= 0x030020
#endif
