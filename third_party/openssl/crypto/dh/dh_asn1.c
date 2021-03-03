#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/bn.h>
#include "dh_local.h"
#include <openssl/objects.h>
#include <openssl/asn1t.h>
typedef struct {
    ASN1_BIT_STRING *seed;
    BIGNUM *counter;
} int_dhvparams;
typedef struct {
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *g;
    BIGNUM *j;
    int_dhvparams *vparams;
} int_dhx942_dh;
