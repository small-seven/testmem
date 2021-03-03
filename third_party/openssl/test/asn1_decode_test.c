#include <stdio.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/asn1t.h>
#include "internal/numbers.h"
#include "testutil.h"
#ifdef __GNUC__
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#ifdef __clang__
# pragma clang diagnostic ignored "-Wunused-function"
#endif
#if OPENSSL_API_COMPAT < 0x10200000L
typedef struct {
    long test_long;
} ASN1_LONG_DATA;
#endif
typedef struct {
    int32_t test_int32;
} ASN1_INT32_DATA;
typedef struct {
    uint32_t test_uint32;
} ASN1_UINT32_DATA;
typedef struct {
    int64_t test_int64;
} ASN1_INT64_DATA;
typedef struct {
    uint64_t test_uint64;
} ASN1_UINT64_DATA;
#if OPENSSL_API_COMPAT < 0x10200000L
#endif
