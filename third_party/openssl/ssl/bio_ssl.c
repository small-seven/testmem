#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <openssl/crypto.h>
#include "internal/bio.h"
#include <openssl/err.h>
#include "ssl_local.h"
typedef struct bio_ssl_st {
    SSL *ssl;                   /* The ssl handle :-) */
    /* re-negotiate every time the total number of bytes is this size */
    int num_renegotiates;
    unsigned long renegotiate_count;
    size_t byte_count;
    unsigned long renegotiate_timeout;
    unsigned long last_time;
} BIO_SSL;
static int ssl_free(BIO *a)
{
    BIO_SSL *bs;

    if (a == NULL)
        return 0;
    bs = BIO_get_data(a);
    if (bs->ssl != NULL)
        SSL_shutdown(bs->ssl);
    if (BIO_get_shutdown(a)) {
        if (BIO_get_init(a))
            SSL_free(bs->ssl);
        /* Clear all flags */
        BIO_clear_flags(a, ~0);
        BIO_set_init(a, 0);
    }
    OPENSSL_free(bs);
    return 1;
}
#ifndef OPENSSL_NO_SOCK
#endif
#ifndef OPENSSL_NO_SOCK
#endif
