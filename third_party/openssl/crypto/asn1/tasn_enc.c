#include <stddef.h>
#include <string.h>
#include "internal/cryptlib.h"
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/objects.h>
#include "crypto/asn1.h"
#include "asn1_local.h"
typedef struct {
    unsigned char *data;
    int length;
    ASN1_VALUE *field;
} DER_ENC;
