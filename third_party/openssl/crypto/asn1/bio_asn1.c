#include <string.h>
#include "internal/bio.h"
#include <openssl/asn1.h>
#include "internal/cryptlib.h"
#define DEFAULT_ASN1_BUF_SIZE 20
typedef enum {
    ASN1_STATE_START,
    ASN1_STATE_PRE_COPY,
    ASN1_STATE_HEADER,
    ASN1_STATE_HEADER_COPY,
    ASN1_STATE_DATA_COPY,
    ASN1_STATE_POST_COPY,
    ASN1_STATE_DONE
} asn1_bio_state_t;
typedef struct BIO_ASN1_EX_FUNCS_st {
    asn1_ps_func *ex_func;
    asn1_ps_func *ex_free_func;
} BIO_ASN1_EX_FUNCS;
typedef struct BIO_ASN1_BUF_CTX_t {
    /* Internal state */
    asn1_bio_state_t state;
    /* Internal buffer */
    unsigned char *buf;
    /* Size of buffer */
    int bufsize;
    /* Current position in buffer */
    int bufpos;
    /* Current buffer length */
    int buflen;
    /* Amount of data to copy */
    int copylen;
    /* Class and tag to use */
    int asn1_class, asn1_tag;
    asn1_ps_func *prefix, *prefix_free, *suffix, *suffix_free;
    /* Extra buffer for prefix and suffix data */
    unsigned char *ex_buf;
    int ex_len;
    int ex_pos;
    void *ex_arg;
} BIO_ASN1_BUF_CTX;
static int asn1_bio_free(BIO *b)
{
    BIO_ASN1_BUF_CTX *ctx;

    if (b == NULL)
        return 0;

    ctx = BIO_get_data(b);
    if (ctx == NULL)
        return 0;

    OPENSSL_free(ctx->buf);
    OPENSSL_free(ctx);
    BIO_set_data(b, NULL);
    BIO_set_init(b, 0);

    return 1;
}
