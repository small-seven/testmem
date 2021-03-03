#include "openssl/opensslconf.h"
#ifdef OPENSSL_NO_RSA
#else
# include "internal/cryptlib.h"
# include <stdio.h>
# include <openssl/rsa.h>
# include <openssl/objects.h>
# include <openssl/asn1t.h>
# include <openssl/evp.h>
# include <openssl/x509.h>
# ifndef OPENSSL_NO_RC4
typedef struct netscape_pkey_st {
    int32_t version;
    X509_ALGOR *algor;
    ASN1_OCTET_STRING *private_key;
} NETSCAPE_PKEY;
typedef struct netscape_encrypted_pkey_st {
    ASN1_OCTET_STRING *os;
    /*
     * This is the same structure as DigestInfo so use it: although this
     * isn't really anything to do with digests.
     */
    X509_SIG *enckey;
} NETSCAPE_ENCRYPTED_PKEY;
# endif                         /* OPENSSL_NO_RC4 */
#endif
