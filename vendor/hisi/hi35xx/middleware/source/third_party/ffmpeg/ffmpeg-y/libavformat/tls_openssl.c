#include "avformat.h"
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "url.h"
#include "tls.h"
#include "libavcodec/internal.h"
#include "libavutil/avstring.h"
#include "libavutil/avutil.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/thread.h"
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
typedef struct TLSContext {
    const AVClass *class;
    TLSShared tls_shared;
    SSL_CTX *ctx;
    SSL *ssl;
#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
    BIO_METHOD* url_bio_method;
#endif
} TLSContext;
#if HAVE_THREADS
#include <openssl/crypto.h>
#if !defined(WIN32) && OPENSSL_VERSION_NUMBER < 0x10000000
#endif
#endif
#if HAVE_THREADS
#if !defined(WIN32) && OPENSSL_VERSION_NUMBER < 0x10000000
#endif
#endif
#if HAVE_THREADS
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
#else
#endif
static int url_bio_destroy(BIO *b)
{
    return 1;
}
#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
#define GET_BIO_DATA(x) BIO_get_data(x)
#else
#define GET_BIO_DATA(x) (x)->ptr
#endif
#if OPENSSL_VERSION_NUMBER < 0x1010000fL
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
#else
#endif
