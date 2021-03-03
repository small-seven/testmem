#include <stdio.h>
#include <stdlib.h>
#include "ssl_local.h"
#include <openssl/asn1t.h>
#include <openssl/x509.h>
typedef struct {
    uint32_t version;
    int32_t ssl_version;
    ASN1_OCTET_STRING *cipher;
    ASN1_OCTET_STRING *comp_id;
    ASN1_OCTET_STRING *master_key;
    ASN1_OCTET_STRING *session_id;
    ASN1_OCTET_STRING *key_arg;
    int64_t time;
    int64_t timeout;
    X509 *peer;
    ASN1_OCTET_STRING *session_id_context;
    int32_t verify_result;
    ASN1_OCTET_STRING *tlsext_hostname;
    uint64_t tlsext_tick_lifetime_hint;
    uint32_t tlsext_tick_age_add;
    ASN1_OCTET_STRING *tlsext_tick;
#ifndef OPENSSL_NO_PSK
    ASN1_OCTET_STRING *psk_identity_hint;
    ASN1_OCTET_STRING *psk_identity;
#endif
#ifndef OPENSSL_NO_SRP
    ASN1_OCTET_STRING *srp_username;
#endif
    uint64_t flags;
    uint32_t max_early_data;
    ASN1_OCTET_STRING *alpn_selected;
    uint32_t tlsext_max_fragment_len_mode;
    ASN1_OCTET_STRING *ticket_appdata;
} SSL_SESSION_ASN1;
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_PSK
#endif                          /* OPENSSL_NO_PSK */
#ifndef OPENSSL_NO_SRP
#endif                          /* OPENSSL_NO_SRP */
static int ssl_session_memcpy(unsigned char *dst, size_t *pdstlen,
                              ASN1_OCTET_STRING *src, size_t maxlen)
{
    if (src == NULL) {
        *pdstlen = 0;
        return 1;
    }
    if (src->length < 0 || src->length > (int)maxlen)
        return 0;
    memcpy(dst, src->data, src->length);
    *pdstlen = src->length;
    return 1;
}
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_SRP
#endif                          /* OPENSSL_NO_SRP */
