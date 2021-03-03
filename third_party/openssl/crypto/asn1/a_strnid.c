#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/asn1.h>
#include <openssl/objects.h>
#include "tbl_standard.h"
static void st_free(ASN1_STRING_TABLE *tbl)
{
    if (tbl->flags & STABLE_FLAGS_MALLOC)
        OPENSSL_free(tbl);
}
