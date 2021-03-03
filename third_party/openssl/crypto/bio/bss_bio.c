#include "e_os.h"
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "bio_local.h"
#include <openssl/err.h>
#include <openssl/crypto.h>
static int bio_free(BIO *bio)
{
    struct bio_bio_st *b;

    if (bio == NULL)
        return 0;
    b = bio->ptr;

    assert(b != NULL);

    if (b->peer)
        bio_destroy_pair(bio);

    OPENSSL_free(b->buf);
    OPENSSL_free(b);

    return 1;
}
