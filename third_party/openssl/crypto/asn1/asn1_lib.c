#include <stdio.h>
#include <limits.h>
#include "internal/cryptlib.h"
#include <openssl/asn1.h>
#include "asn1_local.h"
void asn1_string_embed_free(ASN1_STRING *a, int embed)
{
    if (a == NULL)
        return;
    if (!(a->flags & ASN1_STRING_FLAG_NDEF))
        OPENSSL_free(a->data);
    if (embed == 0)
        OPENSSL_free(a);
}
void ASN1_STRING_free(ASN1_STRING *a)
{
    if (a == NULL)
        return;
    asn1_string_embed_free(a, a->flags & ASN1_STRING_FLAG_EMBED);
}
void ASN1_STRING_clear_free(ASN1_STRING *a)
{
    if (a == NULL)
        return;
    if (a->data && !(a->flags & ASN1_STRING_FLAG_NDEF))
        OPENSSL_cleanse(a->data, a->length);
    ASN1_STRING_free(a);
}
# if OPENSSL_API_COMPAT < 0x10100000L
#endif
