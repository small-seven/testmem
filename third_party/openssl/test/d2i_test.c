#include <stdio.h>
#include <string.h>
#include "testutil.h"
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "internal/nelem.h"
typedef enum {
    ASN1_UNKNOWN,
    ASN1_OK,
    ASN1_BIO,
    ASN1_DECODE,
    ASN1_ENCODE,
    ASN1_COMPARE
} expected_error_t;
typedef struct {
    const char *str;
    expected_error_t code;
} error_enum;
