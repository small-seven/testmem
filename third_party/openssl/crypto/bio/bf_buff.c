#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#include "internal/cryptlib.h"
#define DEFAULT_BUFFER_SIZE     4096
static int buffer_free(BIO *a)
{
    BIO_F_BUFFER_CTX *b;

    if (a == NULL)
        return 0;
    b = (BIO_F_BUFFER_CTX *)a->ptr;
    OPENSSL_free(b->ibuf);
    OPENSSL_free(b->obuf);
    OPENSSL_free(a->ptr);
    a->ptr = NULL;
    a->init = 0;
    a->flags = 0;
    return 1;
}
