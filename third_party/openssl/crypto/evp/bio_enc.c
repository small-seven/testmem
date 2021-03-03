#include <stdio.h>
#include <errno.h>
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include "internal/bio.h"
#define ENC_BLOCK_SIZE  (1024*4)
#define ENC_MIN_CHUNK   (256)
#define BUF_OFFSET      (ENC_MIN_CHUNK + EVP_MAX_BLOCK_LENGTH)
typedef struct enc_struct {
    int buf_len;
    int buf_off;
    int cont;                   /* <= 0 when finished */
    int finished;
    int ok;                     /* bad decrypt */
    EVP_CIPHER_CTX *cipher;
    unsigned char *read_start, *read_end;
    /*
     * buf is larger than ENC_BLOCK_SIZE because EVP_DecryptUpdate can return
     * up to a block more data than is presented to it
     */
    unsigned char buf[BUF_OFFSET + ENC_BLOCK_SIZE];
} BIO_ENC_CTX;
static int enc_free(BIO *a)
{
    BIO_ENC_CTX *b;

    if (a == NULL)
        return 0;

    b = BIO_get_data(a);
    if (b == NULL)
        return 0;

    EVP_CIPHER_CTX_free(b->cipher);
    OPENSSL_clear_free(b, sizeof(BIO_ENC_CTX));
    BIO_set_data(a, NULL);
    BIO_set_init(a, 0);

    return 1;
}
