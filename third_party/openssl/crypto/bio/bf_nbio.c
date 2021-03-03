#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#include "internal/cryptlib.h"
#include <openssl/rand.h>
typedef struct nbio_test_st {
    /* only set if we sent a 'should retry' error */
    int lrn;
    int lwn;
} NBIO_TEST;
static int nbiof_free(BIO *a)
{
    if (a == NULL)
        return 0;
    OPENSSL_free(a->ptr);
    a->ptr = NULL;
    a->init = 0;
    a->flags = 0;
    return 1;
}
