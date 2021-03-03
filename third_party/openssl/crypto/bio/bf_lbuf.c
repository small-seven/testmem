#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#define DEFAULT_LINEBUFFER_SIZE 1024*10
typedef struct bio_linebuffer_ctx_struct {
    char *obuf;                 /* the output char array */
    int obuf_size;              /* how big is the output buffer */
    int obuf_len;               /* how many bytes are in it */
} BIO_LINEBUFFER_CTX;
static int linebuffer_free(BIO *a)
{
    BIO_LINEBUFFER_CTX *b;

    if (a == NULL)
        return 0;
    b = (BIO_LINEBUFFER_CTX *)a->ptr;
    OPENSSL_free(b->obuf);
    OPENSSL_free(a->ptr);
    a->ptr = NULL;
    a->init = 0;
    a->flags = 0;
    return 1;
}
