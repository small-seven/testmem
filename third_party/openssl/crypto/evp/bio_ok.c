#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include "internal/bio.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include "crypto/evp.h"
#define OK_BLOCK_SIZE   (1024*4)
#define OK_BLOCK_BLOCK  4
#define IOBS            (OK_BLOCK_SIZE+ OK_BLOCK_BLOCK+ 3*EVP_MAX_MD_SIZE)
#define WELLKNOWN "The quick brown fox jumped over the lazy dog's back."
typedef struct ok_struct {
    size_t buf_len;
    size_t buf_off;
    size_t buf_len_save;
    size_t buf_off_save;
    int cont;                   /* <= 0 when finished */
    int finished;
    EVP_MD_CTX *md;
    int blockout;               /* output block is ready */
    int sigio;                  /* must process signature */
    unsigned char buf[IOBS];
} BIO_OK_CTX;
static int ok_free(BIO *a)
{
    BIO_OK_CTX *ctx;

    if (a == NULL)
        return 0;

    ctx = BIO_get_data(a);

    EVP_MD_CTX_free(ctx->md);
    OPENSSL_clear_free(ctx, sizeof(BIO_OK_CTX));
    BIO_set_data(a, NULL);
    BIO_set_init(a, 0);

    return 1;
}
