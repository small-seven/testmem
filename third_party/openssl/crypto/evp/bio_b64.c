#include <stdio.h>
#include <errno.h>
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include "internal/bio.h"
#define B64_BLOCK_SIZE  1024
#define B64_BLOCK_SIZE2 768
#define B64_NONE        0
#define B64_ENCODE      1
#define B64_DECODE      2
typedef struct b64_struct {
    /*
     * BIO *bio; moved to the BIO structure
     */
    int buf_len;
    int buf_off;
    int tmp_len;                /* used to find the start when decoding */
    int tmp_nl;                 /* If true, scan until '\n' */
    int encode;
    int start;                  /* have we started decoding yet? */
    int cont;                   /* <= 0 when finished */
    EVP_ENCODE_CTX *base64;
    char buf[EVP_ENCODE_LENGTH(B64_BLOCK_SIZE) + 10];
    char tmp[B64_BLOCK_SIZE];
} BIO_B64_CTX;
static int b64_free(BIO *a)
{
    BIO_B64_CTX *ctx;
    if (a == NULL)
        return 0;

    ctx = BIO_get_data(a);
    if (ctx == NULL)
        return 0;

    EVP_ENCODE_CTX_free(ctx->base64);
    OPENSSL_free(ctx);
    BIO_set_data(a, NULL);
    BIO_set_init(a, 0);

    return 1;
}
