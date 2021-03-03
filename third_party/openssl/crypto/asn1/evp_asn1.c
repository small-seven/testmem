#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
typedef struct {
    int32_t num;
    ASN1_OCTET_STRING *oct;
} asn1_int_oct;
