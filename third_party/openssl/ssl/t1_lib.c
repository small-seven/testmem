#include <stdio.h>
#include <stdlib.h>
#include <openssl/objects.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/ocsp.h>
#include <openssl/conf.h>
#include <openssl/x509v3.h>
#include <openssl/dh.h>
#include <openssl/bn.h>
#include "internal/nelem.h"
#include "ssl_local.h"
#include <openssl/ct.h>
void tls1_free(SSL *s)
{
    OPENSSL_free(s->ext.session_ticket);
    ssl3_free(s);
}
#ifndef OPENSSL_NO_EC
# ifdef OPENSSL_NO_EC2M
# endif
# define MAX_CURVELIST   OSSL_NELEM(nid_list)
typedef struct {
    size_t nidcnt;
    int nid_arr[MAX_CURVELIST];
} nid_cb_st;
#else
#endif                          /* OPENSSL_NO_EC */
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_GOST
#endif
#define RSA_PSS_MINIMUM_KEY_SIZE(md) (2 * EVP_MD_size(md) + 2)
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_PSK
#endif                          /* OPENSSL_NO_PSK */
#ifndef OPENSSL_NO_SRP
#endif
#define TLS_MAX_SIGALGCNT (OSSL_NELEM(sigalg_lookup_tbl) * 2)
typedef struct {
    size_t sigalgcnt;
    /* TLSEXT_SIGALG_XXX values */
    uint16_t sigalgs[TLS_MAX_SIGALGCNT];
} sig_cb_st;
#define TLS_MAX_SIGSTRING_LEN   40
#define CERT_PKEY_VALID_FLAGS \
#define CERT_PKEY_STRICT_FLAGS \
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_GOST
#endif
