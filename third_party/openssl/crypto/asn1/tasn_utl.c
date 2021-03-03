#include <stddef.h>
#include <string.h>
#include "internal/cryptlib.h"
#include "internal/refcount.h"
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/objects.h>
#include <openssl/err.h>
#include "asn1_local.h"
#define offset2ptr(addr, offset) (void *)(((char *) addr) + offset)
#ifdef REF_PRINT
#endif
void asn1_enc_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    ASN1_ENCODING *enc;
    enc = asn1_get_enc_ptr(pval, it);
    if (enc) {
        OPENSSL_free(enc->enc);
        enc->enc = NULL;
        enc->len = 0;
        enc->modified = 1;
    }
}
