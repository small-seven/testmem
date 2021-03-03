#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/kdf.h>
#include <openssl/dh.h>
#include "testutil.h"
#include "internal/nelem.h"
#include "crypto/evp.h"
#ifndef OPENSSL_NO_EC
#endif
typedef struct APK_DATA_st {
    const unsigned char *kder;
    size_t size;
    int evptype;
    int check;
    int pub_check;
    int param_check;
    int type; /* 0 for private, 1 for public, 2 for params */
} APK_DATA;
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_SM2
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#if !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305)
#endif /* !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305) */
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_SM2
#endif
#ifndef OPENSSL_NO_EC
#endif
#if !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305)
#endif
#ifndef OPENSSL_NO_DH
#endif
