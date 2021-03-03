#include <stdio.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/asn1t.h>
#include "internal/numbers.h"
#include "testutil.h"
#ifdef __GNUC__
# pragma GCC diagnostic ignored "-Wunused-function"
# pragma GCC diagnostic ignored "-Wformat"
#endif
#ifdef __clang__
# pragma clang diagnostic ignored "-Wunused-function"
# pragma clang diagnostic ignored "-Wformat"
#endif
typedef struct {
    unsigned char *bytes1;
    size_t nbytes1;
    unsigned char *bytes2;
    size_t nbytes2;
} TEST_CUSTOM_DATA;
#define CUSTOM_DATA(v)                          \
#define CUSTOM_EXPECTED_SUCCESS(num, znum)      \
#define CUSTOM_EXPECTED_FAILURE                 \
typedef int i2d_fn(void *a, unsigned char **pp);
typedef void *d2i_fn(void **a, unsigned char **pp, long length);
typedef void ifree_fn(void *a);
typedef struct {
    ASN1_ITEM_EXP *asn1_type;
    const char *name;
    int skip;                    /* 1 if this package should be skipped */

    /* An array of structures to compare decoded custom data with */
    void *encode_expectations;
    size_t encode_expectations_size;
    size_t encode_expectations_elem_size;

    /*
     * An array of structures that are encoded into a DER blob, which is
     * then decoded, and result gets compared with the original.
     */
    void *encdec_data;
    size_t encdec_data_size;
    size_t encdec_data_elem_size;

    /* The i2d function to use with this type */
    i2d_fn *i2d;
    /* The d2i function to use with this type */
    d2i_fn *d2i;
    /* Function to free a decoded structure */
    ifree_fn *ifree;
} TEST_PACKAGE;
#define ENCDEC_DATA(num, znum)                  \
#define ENCDEC_ARRAY(max, zmax, min, zmin)      \
#if OPENSSL_API_COMPAT < 0x10200000L
typedef struct {
    /* If decoding is expected to succeed, set this to 1, otherwise 0 */
    ASN1_BOOLEAN success;
    long test_long;
    long test_zlong;
} ASN1_LONG_DATA;
#endif
typedef struct {
    ASN1_BOOLEAN success;
    int32_t test_int32;
    int32_t test_zint32;
} ASN1_INT32_DATA;
typedef struct {
    ASN1_BOOLEAN success;
    uint32_t test_uint32;
    uint32_t test_zuint32;
} ASN1_UINT32_DATA;
typedef struct {
    ASN1_BOOLEAN success;
    int64_t test_int64;
    int64_t test_zint64;
} ASN1_INT64_DATA;
typedef struct {
    ASN1_BOOLEAN success;
    uint64_t test_uint64;
    uint64_t test_zuint64;
} ASN1_UINT64_DATA;
typedef struct {
    ASN1_BOOLEAN success;
    unsigned char bytes[1];       /* In reality, there's more */
} EXPECTED;
#define DATA_BUF_SIZE 256
#if OPENSSL_API_COMPAT < 0x10200000L
#endif
#if OPENSSL_API_COMPAT < 0x10200000L
#endif
