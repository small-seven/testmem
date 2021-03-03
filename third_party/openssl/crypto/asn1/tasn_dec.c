#include <stddef.h>
#include <string.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/objects.h>
#include <openssl/buffer.h>
#include <openssl/err.h>
#include "internal/numbers.h"
#include "asn1_local.h"
#define ASN1_MAX_CONSTRUCTED_NEST 30
#define asn1_tlc_clear(c)       if (c) (c)->valid = 0
#define asn1_tlc_clear_nc(c)    (c)->valid = 0
#ifndef ASN1_MAX_STRING_NEST
# define ASN1_MAX_STRING_NEST 5
#endif
