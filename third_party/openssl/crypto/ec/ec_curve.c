#include <string.h>
#include "ec_local.h"
#include <openssl/err.h>
#include <openssl/obj_mac.h>
#include <openssl/opensslconf.h>
#include "internal/nelem.h"
typedef struct {
    int field_type,             /* either NID_X9_62_prime_field or
                                 * NID_X9_62_characteristic_two_field */
     seed_len, param_len;
    unsigned int cofactor;      /* promoted to BN_ULONG */
} EC_CURVE_DATA;
#ifndef OPENSSL_NO_EC2M
#endif
#ifndef OPENSSL_NO_SM2
#endif /* OPENSSL_NO_SM2 */
typedef struct _ec_list_element_st {
    int nid;
    const EC_CURVE_DATA *data;
    const EC_METHOD *(*meth) (void);
    const char *comment;
} ec_list_element;
#ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
#else
#endif
#ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
#else
#endif
#if defined(ECP_NISTZ256_ASM)
#elif !defined(OPENSSL_NO_EC_NISTP_64_GCC_128)
#else
#endif
#ifndef OPENSSL_NO_EC2M
#endif
#ifndef OPENSSL_NO_EC2M
#endif
#ifndef OPENSSL_NO_EC2M
#endif
#ifndef OPENSSL_NO_SM2
#endif
#define curve_list_length OSSL_NELEM(curve_list)
#ifndef OPENSSL_NO_EC2M
#endif
typedef struct {
    const char *name;           /* NIST Name of curve */
    int nid;                    /* Curve NID */
} EC_NIST_NAME;
#define NUM_BN_FIELDS 6
