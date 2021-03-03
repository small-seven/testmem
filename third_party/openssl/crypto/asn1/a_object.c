#include <stdio.h>
#include <limits.h>
#include "crypto/ctype.h"
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include <openssl/asn1.h>
#include <openssl/objects.h>
#include <openssl/bn.h>
#include "crypto/asn1.h"
#include "asn1_local.h"
void ASN1_OBJECT_free(ASN1_OBJECT *a)
{
    if (a == NULL)
        return;
    if (a->flags & ASN1_OBJECT_FLAG_DYNAMIC_STRINGS) {
#ifndef CONST_STRICT            /* disable purely for compile-time strict
                                 * const checking. Doing this on a "real"
                                 * compile will cause memory leaks */
        OPENSSL_free((void*)a->sn);
        OPENSSL_free((void*)a->ln);
#endif
        a->sn = a->ln = NULL;
    }
    if (a->flags & ASN1_OBJECT_FLAG_DYNAMIC_DATA) {
        OPENSSL_free((void*)a->data);
        a->data = NULL;
        a->length = 0;
    }
    if (a->flags & ASN1_OBJECT_FLAG_DYNAMIC)
        OPENSSL_free(a);
}
