#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <stdio.h>
typedef struct ndef_aux_st {
    /* ASN1 structure this BIO refers to */
    ASN1_VALUE *val;
    const ASN1_ITEM *it;
    /* Top of the BIO chain */
    BIO *ndef_bio;
    /* Output BIO */
    BIO *out;
    /* Boundary where content is inserted */
    unsigned char **boundary;
    /* DER buffer start */
    unsigned char *derbuf;
} NDEF_SUPPORT;
static int ndef_prefix_free(BIO *b, unsigned char **pbuf, int *plen,
                            void *parg)
{
    NDEF_SUPPORT *ndef_aux;

    if (!parg)
        return 0;

    ndef_aux = *(NDEF_SUPPORT **)parg;

    OPENSSL_free(ndef_aux->derbuf);

    ndef_aux->derbuf = NULL;
    *pbuf = NULL;
    *plen = 0;
    return 1;
}
static int ndef_suffix_free(BIO *b, unsigned char **pbuf, int *plen,
                            void *parg)
{
    NDEF_SUPPORT **pndef_aux = (NDEF_SUPPORT **)parg;
    if (!ndef_prefix_free(b, pbuf, plen, parg))
        return 0;
    OPENSSL_free(*pndef_aux);
    *pndef_aux = NULL;
    return 1;
}
